#!/bin/sh
#
# $FreeBSD$
#

# There is a Perl script that accompanies the NWMovies distfile, however, it
# would require Linux Perl to be installed when a simple shell script will
# suffice.  Since the name of the Perl script is hardcoded into the binary, this
# file has a .pl extension even though it is Bourne shell.

# Initialization.
NWNUSERDIR="${HOME}/.nwn"
NWNSKIPFILE=${NWNUSERDIR}/nwmovies.skip
NWNMOVIEDIR=${NWNUSERDIR}/movies
NWNMOVIES=${NWNUSERDIR}/nwmovies
NWNINI=${NWNUSERDIR}/nwn.ini

# Print arguments in lowercase
tolower() {
	set -e
	echo "$@" | tr '[:upper:]' '[:lower:]'
}

# Determine case-insensitive movie name to play prior to setting LD_PRELOAD.
reqmovie="$(tolower ${NWNMOVIEDIR}/${1}).bik"
for m in ${NWNMOVIEDIR}/*
do
	if [ ${reqmovie} = $(tolower ${m}) ]
	then
		movie="${m}"
		break
	fi
done
if [ -z "${movie}" ]
then
	echo "${reqmovie} not found"
	exit 1
fi

# Skip movies request by user.
if [ -e ${NWNSKIPFILE} ]
then
	reqmovie="$(tolower ${1})"
	for m in `cat ${NWNSKIPFILE}`
	do
		if [ ${reqmovie} = $(tolower ${m}) ]
		then
			echo "Skipping ${1} as requested"
			exit 0
		fi
	done
fi

# Prevent core files from BinkPlayer.
ulimit -c 0

# Configure movie display (default to 800x600 if not in .ini file).
BINK_WIDTH=`grep -i width ${NWNINI} | cut -f 2 -d '='` 2> /dev/null
export BINK_WIDTH=${BINK_WIDTH:-800}
BINK_HEIGHT=`grep -i height ${NWNINI} | cut -f 2 -d '='` 2> /dev/null
export BINK_HEIGHT=${BINK_HEIGHT:-600}
export BINK_FULLSCREEN=1

# Silence warnings from SDL.
export SDL_AUDIODRIVER=${SDL_AUDIODRIVER:-"dsp"}

# Configure for needed libraries (some are only needed if running standalone).
if [ ! -e ${NWNMOVIES}/libX11.so ]
then
	ln -sf /compat/linux/usr/lib/libX11.so.6 ${NWNMOVIES}/libX11.so
fi
export LD_LIBRARY_PATH=${NWNUSERDIR}/nwmovies:${LD_LIBRARY_PATH}
export LD_PRELOAD=./nwmovies/binklib.so

# Play movie.
./nwmovies/BinkPlayer ${movie}
