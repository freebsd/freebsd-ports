#!/bin/sh
# $FreeBSD$
#
# MAINTAINER: portmgr@FreeBSD.org

set -e
set -o pipefail

. "${dp_SCRIPTSDIR}/functions.sh"

validate_env dp_CURDIR dp_ECHO_CMD dp_ECHO_MSG dp_EXPR dp_GREP dp_PKGNAME \
	dp_SED dp_TR dp_MAKE

[ -n "${DEBUG_MK_SCRIPTS}" ] || [ -n "${DEBUG_MK_SCRIPTS_CHECK_DESKTOP_ENTRIES}" ] && set -x

set -u

# http://standards.freedesktop.org/menu-spec/menu-spec-latest.html
DESKTOP_CATEGORIES_MAIN='AudioVideo Audio Video Development Education Game
Graphics Network Office Science Settings System Utility'
DESKTOP_CATEGORIES_ADDITIONAL='Building Debugger IDE GUIDesigner Profiling
RevisionControl Translation Calendar ContactManagement Database Dictionary
Chart Email Finance FlowChart PDA ProjectManagement Presentation Spreadsheet
WordProcessor 2DGraphics VectorGraphics RasterGraphics 3DGraphics Scanning OCR
Photography Publishing Viewer TextTools DesktopSettings HardwareSettings
Printing PackageManager Dialup InstantMessaging Chat IRCClient Feed
FileTransfer HamRadio News P2P RemoteAccess Telephony TelephonyTools
VideoConference WebBrowser WebDevelopment Midi Mixer Sequencer Tuner TV
AudioVideoEditing Player Recorder DiscBurning ActionGame AdventureGame
ArcadeGame BoardGame BlocksGame CardGame KidsGame LogicGame RolePlaying Shooter
Simulation SportsGame StrategyGame Art Construction Music Languages
ArtificialIntelligence Astronomy Biology Chemistry ComputerScience
DataVisualization Economy Electricity Geography Geology Geoscience History
Humanities ImageProcessing Literature Maps Math NumericalAnalysis
MedicalSoftware Physics Robotics Spirituality Sports ParallelComputing
Amusement Archiving Compression Electronics Emulator Engineering FileTools
FileManager TerminalEmulator Filesystem Monitor Security Accessibility
Calculator Clock TextEditor Documentation Adult Core KDE GNOME MATE XFCE GTK Qt
Motif Java ConsoleOnly'
DESKTOP_CATEGORIES_RESERVED='Screensaver TrayIcon Applet Shell'

VALID_DESKTOP_CATEGORIES="${dp_VALID_DESKTOP_CATEGORIES} ${DESKTOP_CATEGORIES_MAIN} ${DESKTOP_CATEGORIES_ADDITIONAL} ${DESKTOP_CATEGORIES_RESERVED}"

if [ "$(${dp_EXPR} $# % 6)" -ne 0 ]; then
	${dp_ECHO_MSG} "${dp_PKGNAME}: Makefile error: the DESKTOP_ENTRIES list must contain one or more groups of 6 elements"
	exit 1
fi

num=0

while [ $# -ge 6 ]; do
	num=$(${dp_EXPR} ${num} + 1)
	entry="#${num}"

	Name="${1}"
	#Comment="${2}" # Not Used
	Icon="${3}"
	Exec="${4}"
	Categories="${5}"
	StartupNotify="${6}"

	shift 6

	if [ -n "${Exec}" ]; then
		entry="${entry} (${Exec})"
	elif [ -n "${Name}" ]; then
		entry="${entry} (${Name})"
	fi

	if [ -z "${Name}" ]; then
		${dp_ECHO_MSG} "${dp_PKGNAME}: Makefile error: in desktop entry ${entry}: field 1 (Name) is empty"
		exit 1
	fi

	if ${dp_EXPR} '(' "${Icon}" : '.*\.xpm$' ')' '|' '(' "${Icon}" : '.*\.png$' ')'  '|' '(' "${Icon}" : '.*\.svg$' ')' > /dev/null; then
		if ! echo "${Icon}" | ${dp_GREP} -qe '^/' ; then
			${dp_ECHO_MSG} "${dp_PKGNAME}: Makefile warning: in desktop entry ${entry}: field 3 (Icon) should be either absolute path or icon name without extension if installed icons follow Icon Theme Specification"
		fi
	fi

	if [ -z "${Exec}" ]; then
		${dp_ECHO_MSG} "${dp_PKGNAME}: Makefile error: in desktop entry ${entry}: field 4 (Exec) is empty"
		exit 1
	fi

	if [ -n "${Categories}" ]; then
		for c in $(${dp_ECHO_CMD} "${Categories}" | ${dp_TR} ';' ' '); do
			if ! ${dp_ECHO_CMD} "${VALID_DESKTOP_CATEGORIES}" | ${dp_GREP} -wq "${c}"; then
				${dp_ECHO_CMD} "${dp_PKGNAME}: Makefile warning: in desktop entry ${entry}: category ${c} is not a valid desktop category"
			fi
		done

		if ! ${dp_ECHO_CMD} "${Categories}" | ${dp_GREP} -Eq "$(${dp_ECHO_CMD} "${DESKTOP_CATEGORIES_MAIN}" | ${dp_SED} -E 's,[[:blank:]]+,\|,g')"; then
			${dp_ECHO_CMD} "${dp_PKGNAME}: Makefile warning: in desktop entry ${entry}: field 5 (Categories) must contain at least one main desktop category (make -VDESKTOP_CATEGORIES_MAIN)"
		fi

		if ! ${dp_EXPR} "${Categories}" : '.*;$' > /dev/null; then
			${dp_ECHO_MSG} "${dp_PKGNAME}: Makefile error: in desktop entry ${entry}: field 5 (Categories) does not end with a semicolon"
			exit 1
		fi
	else
		if [ -z "$(cd "${dp_CURDIR}" && ${dp_MAKE} desktop-categories)" ]; then
			${dp_ECHO_MSG} "${dp_PKGNAME}: Makefile error: in desktop entry ${entry}: field 5 (Categories) is empty and could not be deduced from the CATEGORIES variable"
			exit 1
		fi
	fi

	if [ "${StartupNotify}" != "true" ] && [ "${StartupNotify}" != "false" ] && [ -n "${StartupNotify}" ]; then
		${dp_ECHO_MSG} "${dp_PKGNAME}: Makefile error: in desktop entry ${entry}: field 6 (StartupNotify) is not \"true\", \"false\" or \"\"(empty)"
		exit 1
	fi
done
