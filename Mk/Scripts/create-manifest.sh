#!/bin/sh
# $FreeBSD$
#
# MAINTAINER: portmgr@FreeBSD.org

set -e

. "${dp_SCRIPTSDIR}/functions.sh"

validate_env dp_ACTUAL_PACKAGE_DEPENDS dp_CATEGORIES dp_COMMENT \
	dp_COMPLETE_OPTIONS_LIST dp_DEPRECATED dp_DESCR dp_EXPIRATION_DATE \
	dp_GROUPS dp_LICENSE dp_LICENSE_COMB dp_MAINTAINER dp_METADIR \
	dp_NO_ARCH dp_PKGBASE dp_PKGDEINSTALL dp_PKGINSTALL dp_PKGMESSAGE \
	dp_PKGORIGIN dp_PKGPOSTDEINSTALL dp_PKGPOSTINSTALL dp_PKGPOSTUPGRADE \
	dp_PKGPREDEINSTALL dp_PKGPREINSTALL dp_PKGPREUPGRADE dp_PKGUPGRADE \
	dp_PKGVERSION dp_PKG_BIN dp_PKG_IGNORE_DEPENDS dp_PKG_NOTES \
	dp_PORT_OPTIONS dp_PREFIX dp_USERS dp_WWW

[ -n "${DEBUG_MK_SCRIPTS}" -o -n "${DEBUG_MK_SCRIPTS_CREATE_MANIFEST}" ] && set -x

set -u

listcontains() {
	local str lst elt
	str=$1
	lst=$2

	for elt in ${lst} ; do
		if [ ${elt} = ${str} ]; then
			return 0
		fi
	done
	return 1
}

mkdir -p ${dp_METADIR}

# Save stdout and redirect it to the manifest file.
exec 3>&1 >${dp_METADIR}/+MANIFEST

# First, all the required bits
cat <<EOT
name: "${dp_PKGBASE}"
version: "${dp_PKGVERSION}"
origin: ${dp_PKGORIGIN}
comment: <<EOD
${dp_COMMENT}
EOD
maintainer: ${dp_MAINTAINER}
prefix: ${dp_PREFIX}
categories: [ ${dp_CATEGORIES} ]
licenselogic: ${dp_LICENSE_COMB:-single}
EOT

# Then, the optional bits
[ -z "${dp_WWW}" ] || echo "www: ${dp_WWW}"
[ -z "${dp_LICENSE}" ] || echo "licenses: [ ${dp_LICENSE} ]"
[ -z "${dp_USERS}" ] || echo "users: [ ${dp_USERS} ]"
[ -z "${dp_GROUPS}" ] || echo "groups: [ ${dp_GROUPS} ]"
[ -n "${dp_NO_ARCH}" ] && echo "arch : `${dp_PKG_BIN} config abi | tr '[:upper:]' '[:lower:]' | cut -d: -f1,2`:*"
[ -n "${dp_NO_ARCH}" ] && echo "abi : `${dp_PKG_BIN} config abi | cut -d: -f1,2`:*"

# Then the key/values sections
echo "deps: { "
eval ${dp_ACTUAL_PACKAGE_DEPENDS} | grep -v -E ${dp_PKG_IGNORE_DEPENDS} | sort -u
echo "}"

echo "options: {"
for opt in ${dp_COMPLETE_OPTIONS_LIST}; do
	if listcontains ${opt} "${dp_PORT_OPTIONS}"; then
		echo " ${opt}: on,"
	else
		echo " ${opt}: off,"
	fi
done
echo "}"

if [ -n "${dp_PKG_NOTES}" ]; then
	echo "annotations: {"
	for note in ${dp_PKG_NOTES}; do
		echo " ${note}: <<EOD"
		eval "echo \"\${dp_PKG_NOTE_${note}}\""
		echo "EOD"
	done
	echo "}"
fi

# Copy the pkg-descr file
cp ${dp_DESCR} ${dp_METADIR}/+DESC

# Concatenate all the scripts
for stage in INSTALL DEINSTALL UPGRADE; do
	for prepost in '' PRE POST; do
		eval files="\${dp_PKG${prepost}${stage}}"
		output=${dp_METADIR}/+${prepost:+${prepost}_}${stage}
		rm -f ${output}
		for input in ${files}; do
			[ -f "${input}" ] && cat ${input} >> ${output}
		done
	done
done

# *** STARTING NOW, STDOUT is +DISPLAY ***

exec >${dp_METADIR}/+DISPLAY

[ -f ${dp_PKGMESSAGE} ] && cat ${dp_PKGMESSAGE}

# Try and keep these messages in sync with check-deprecated
if [ ${dp_MAINTAINER} = "ports@FreeBSD.org" ]; then
	if [ -f "${dp_METADIR}/+DISPLAY" ]; then echo; fi
	cat <<-EOT
	===>   NOTICE:

	The ${dp_PKGBASE} port currently does not have a maintainer. As a result, it is
	more likely to have unresolved issues, not be up-to-date, or even be removed in
	the future. To volunteer to maintain this port, please create an issue at:

	https://bugs.freebsd.org/bugzilla

	More information about port maintainership is available at:

	https://www.freebsd.org/doc/en/articles/contributing/ports-contributing.html#maintain-port
	EOT
fi

if [ -n "${dp_DEPRECATED}" ]; then
	if [ -f "${dp_METADIR}/+DISPLAY" ]; then echo; fi
	cat <<-EOT
	===>   NOTICE:

	This port is deprecated; you may wish to reconsider installing it:

	${dp_DEPRECATED}.

	EOT

	if [ -n "${dp_EXPIRATION_DATE}" ]; then
		cat <<-EOT
		It is scheduled to be removed on or after ${dp_EXPIRATION_DATE}.

		EOT
	fi
fi

if [ ! -s ${dp_METADIR}/+DISPLAY ]; then
	rm -f ${dp_METADIR}/+DISPLAY
fi
