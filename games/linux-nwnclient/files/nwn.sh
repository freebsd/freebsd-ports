#!/bin/sh
#
# $FreeBSD$
#

NWNDATADIR="%%NWNDATADIR%%"
NWNCLIENTDIR="%%NWNCLIENTDIR%%"
NWNUSERDIR="${HOME}/.nwn"
LCDIRS="ambient data dmvault hak localvault music override portraits"

set -e

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
		[ -e "${NWNUSERDIR}/${file}" ] ||
			ln -s "${1}/${file}" "${NWNUSERDIR}/${file}"
	done
}

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

if [ ! -d "${NWNUSERDIR}" ] ; then
	echo "Creating user directory"
	mkdir "${NWNUSERDIR}"

	# Copy the ini file so the user can tweak it
	cp "${NWNCLIENTDIR}/nwn.ini" "${NWNUSERDIR}"

	# Create a non-empty CD key file to work around a bug in the
	# client: it will ask for the key twice if the file is
	# initally empty or missing
	echo '[CDKEY]' >"${NWNUSERDIR}/nwncdkey.ini"

	# Copy ${NWNCLIENTDIR} first since it may contain files which
	# override parts of ${NWNDATADIR}
	copydir "${NWNCLIENTDIR}"
	copydir "${NWNDATADIR}"

	# Some files need to have their names converted to lowercase
	cd "${NWNUSERDIR}"
	lowerdir ${LCDIRS}

	echo "Your Neverwinter Nights directory (~/.nwn) has now been"
	echo "created and populated.  Press ENTER to start the game."
	read dummy
fi

echo "Saved games will be stored in ${NWNUSERDIR}/saves/"

cd "${NWNUSERDIR}"

# SDL settings
export SDL_MOUSE_RELATIVE=0
export SDL_VIDEO_X11_DGAMOUSE=0

# Library locations
export LD_LIBRARY_PATH="${NWNUSERDIR}/lib:${NWNUSERDIR}/miles"

echo "Starting Neverwinter Nights..."
exec ./nwmain
