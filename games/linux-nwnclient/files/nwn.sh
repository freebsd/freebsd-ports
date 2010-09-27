#!/bin/sh
#
# $FreeBSD$
#

NWNDATADIR="%%NWNDATADIR%%"
NWNCLIENTDIR="%%NWNCLIENTDIR%%"
NWNUSERDIR="${HOME}/.nwn"
LCDIRS="ambient data dmvault hak localvault music override portraits"

set -e

# Print arguments in lowercase
tolower() {
	set -e
	echo "$@" | tr '[:upper:]' '[:lower:]'
}

# Rename all files in a directory to lowercase
lowerdir() {
	set -e
	find "$@" -name '*[A-Z]*' | while read name ; do
		mv -v "${name}" "$(tolower ${name})"
	done
}

# Copy a directory structure and symlink its contents
copydir() {
	set -e
	cd "$1"
	find . -type d | cut -c 3- | while read dir ; do
		[ -d "${NWNUSERDIR}/${dir}" ] ||
			mkdir "${NWNUSERDIR}/${dir}"
	done
	find . -type l | cut -c 3- | while read file ; do
		[ -L "${NWNUSERDIR}/${file}" ] ||
			cp -R "${file}" "${NWNUSERDIR}/${file}"
	done
	find . -type f | cut -c 3- | while read file ; do
		[ -e "${NWNUSERDIR}/${file}" -o \
		-e "$(tolower ${NWNUSERDIR}/${file})" ] ||
			ln -s "${1}/${file}" "${NWNUSERDIR}/${file}"
	done
}

# Create user directory.  Will also update a user directory if anything is
# different due to running NWN with different versions of the game.
rebuilduserdir() {
	# Copy ${NWNCLIENTDIR} first since it may contain files which
	# override parts of ${NWNDATADIR}
	copydir "${NWNCLIENTDIR}"
	copydir "${NWNDATADIR}"

	# Some files need to have their names converted to lowercase.  Create
	# the directories if missing due to differences between versions of NWN.
	cd "${NWNUSERDIR}"
	mkdir -p ${LCDIRS}
	lowerdir ${LCDIRS}
}

if [ ! -d "${NWNUSERDIR}" ] ; then
	echo "Creating user directory"
	mkdir "${NWNUSERDIR}"

	# Copy the ini file so the user can tweak it
	cp "${NWNCLIENTDIR}/nwn.ini" "${NWNUSERDIR}"

	# Create a non-empty CD key file to work around a bug in the
	# client: it will ask for the key twice if the file is
	# initally empty or missing
	echo '[CDKEY]' >"${NWNUSERDIR}/nwncdkey.ini"

	rebuilduserdir

	echo "Your Neverwinter Nights directory (~/.nwn) has now been"
	echo "created and populated.  Press ENTER to start the game."
	read dummy
else
	# Remove dead links from different versions (e.g., original versus
	# Diamond Edition) of NWN as they could confuse the game.
	find -L ${NWNUSERDIR} -type l -exec rm -- {} +

	rebuilduserdir
fi

echo "Saved games will be stored in ${NWNUSERDIR}/saves/"

cd "${NWNUSERDIR}"

# Remove old movie log file.
rm -f ${NWNUSERDIR}/nwmovies.log

# Prevent flickering at beginning and ending of playing a movie.
export NWMOVIES_GRAB_HACK=1

# SDL settings
export SDL_MOUSE_RELATIVE=0
export SDL_VIDEO_X11_DGAMOUSE=0
export SDL_AUDIODRIVER=${SDL_AUDIODRIVER:-"dsp"}

# Library locations
export LD_LIBRARY_PATH="${NWNUSERDIR}/lib:${NWNUSERDIR}/miles"

# Prevent core files from NWN.
ulimit -c 0

echo "Starting Neverwinter Nights..."
if [ -e ./nwmovies/nwmovies.so ] ; then
	export LD_PRELOAD=./nwmovies/nwmovies.so
fi
./nwmain "${@}"
