# Ports collection makefile for:    setiathome
# Date created:         22 Apr 1999
# Whom:                 stb@freebsd.org
#
# $FreeBSD$

PORTNAME=	setiathome
PORTVERSION?=	3.03
PORTREVISION?=	5
CATEGORIES?=	astro
MASTER_SITES=	ftp://ftp.cdrom.com/pub/setiathome/ \
		ftp://alien.ssl.berkeley.edu/pub/
DISTNAME=	${PORTNAME}-${PORTVERSION}.${PORT_HOST}
EXTRACT_SUFX=	.tar

MAINTAINER?=	cyrille.lefevre@laposte.net

.include <bsd.port.pre.mk>

# Global variables
#

.if !defined(BATCH)
IS_INTERACTIVE=	yes
.endif

ONLY_FOR_ARCHS?= alpha i386

NO_BUILD=	binary distribution
NO_CDROM=	interactive install

.if ${OSVERSION} <= 226000
BROKEN=		"currently supports only FreeBSD 2.2.6 and above"
.endif

EXTRACT_CMD=	${CAT}
EXTRACT_BEFORE_ARGS=

STRIP=		# aout is already stripped
SCRIPTS_ENV+=	PKG_PREFIX=${PREFIX}
PLIST_SUB=	X11PORTS=${X11PORTS} \
		PREFX="${PKGNAMEPREFIX}" SUFX="${PKGNAMESUFFIX}"

MAN1=		${PORTNAME}.1

MSG_FILE=	${PKGDIR}/pkg-message
PKGMESSAGE=	${WRKDIR}/pkg-message
PKGDEINSTALL=	${PKGINSTALL}

# Port specific variables
#

PORT_CPU?=	${ARCH}
.if ${ARCH} == alpha
PORT_VENDOR=	compaq
PORT_OSNAME=	T64U
PORT_OSREL=	v4.0d
.else
PORT_VENDOR?=	unknown
PORT_OSNAME?=	freebsd
PORT_OSREL?=	2.2.8
.endif
PORT_OS=	${PORT_OSNAME}${PORT_OSREL}
PORT_HOST=	${PORT_CPU}-${PORT_VENDOR}-${PORT_OS}

# Arch/OS specific variables
#

.if ${ARCH} != i386
MD5_FILE=	${MASTERDIR}/distinfo.${ARCH}
.elif ${PORT_OSNAME} != freebsd
PKGNAMEPREFIX=	${PORT_OSNAME}-
PKGNAMESUFFIX=	-${PORT_CPU}
MD5_FILE=	${.CURDIR}/distinfo
COMMENT=	${.CURDIR}/pkg-comment
DESCR=		${.CURDIR}/pkg-descr
.if ${PORT_OSNAME} == linux
.if !exists(${LINUXBASE}/usr/X11R6/lib/libXaw.so.7)
NO_XBIN=	libXaw.so.7 is missing from linux_base-6
.endif
NO_XBIN?=	xsetiathome is broken
.endif
.elif ${OSVERSION} >= 300000
NO_XBIN=	xsetiathome is broken
.endif

# Local variables
#

SBIN_DIR=	${PREFIX}/sbin
CONF_DIR=	${PREFIX}/etc
RC_DIR=		${PREFIX}/etc/rc.d

SAMP_SUFX=	.sample

BIN_FILE=	setiathome
RC_FILES=	setiathome

# i386 NOTES:
# xsetiathome is currently broken at 4.2. should work at 2.x,
# don't know between 3.0 and 4.2 ? so, be conservative...
# diagnostic messages are :
#	Warning: Cannot convert string "doneB" to type Widget
#	Floating point exception (core dumped)
# Linux NOTES:
# xsetiathome requires libXawk.so.7 which is missing from linux_base-6.
# using linux_base-7, diagnostic messages are :
#	Warning: Cannot convert string "doneB" to type Widget
#	Shared memory segment doesn't exist. errno=2
#	Couldn't attach to the science process!

.if !defined(NO_XBIN)
MAN1+=		x${PORTNAME}.1
XBIN_DIR=	${PREFIX}/bin
XBIN_FILE=	xsetiathome
X11PORTS=
.else
X11PORTS=	"@comment "
.endif

# Post-patch
#

post-patch: patch-pkgmessage

patch-pkgmessage:
	@${SED} 's|%%PREFIX%%|${PREFIX}|g; \
		 s|%%PREFX%%|${PKGNAMEPREFIX}|g; \
		 s|%%SUFX%%|${PKGNAMESUFFIX}|g' \
		${MSG_FILE} > ${PKGMESSAGE}

# Install
#

do-install: install-daemon install-program install-man

install-daemon:
	@${INSTALL_PROGRAM} ${WRKSRC}/${BIN_FILE} \
		${SBIN_DIR}/${PKGNAMEPREFIX}${BIN_FILE}${PKGNAMESUFFIX}

install-program:
.if defined(XBIN_FILE)
	@${INSTALL_PROGRAM} ${WRKSRC}/${XBIN_FILE} \
		${XBIN_DIR}/${PKGNAMEPREFIX}${XBIN_FILE}${PKGNAMESUFFIX}
.endif

install-man:
.for mansect in 1
.for man in ${MAN${mansect}}
	@${INSTALL_MAN} ${FILESDIR}/${man} \
		${MAN${mansect}PREFIX}/man/man${mansect}
.endfor
.endfor

# Post-install
#

post-install: install-startup-files configure-package display-message

install-startup-files:
.for file in ${RC_FILES}
.if exists(${FILESDIR}/rc.${file}.conf)
	@${INSTALL_DATA} ${FILESDIR}/rc.${file}.conf \
		${CONF_DIR}/rc.${PKGNAMEPREFIX}${file}${PKGNAMESUFFIX}.conf${SAMP_SUFX}
.if !exists(${CONF_DIR}/rc.${PKGNAMEPREFIX}${file}${PKGNAMESUFFIX}.conf)
	@${INSTALL_DATA} ${FILESDIR}/rc.${file}.conf \
		${CONF_DIR}/rc.${PKGNAMEPREFIX}${file}${PKGNAMESUFFIX}.conf
.endif
.endif
.if defined(PKGNAMEPREFIX) && !empty(PKGNAMEPREFIX)
	-@${CHMOD} -x ${RC_DIR}/*${file}*.sh 2> /dev/null
.endif
.if exists(${FILESDIR}/${file}.sh)
	@${INSTALL_SCRIPT} ${FILESDIR}/${file}.sh \
		${RC_DIR}/${PKGNAMEPREFIX}${file}${PKGNAMESUFFIX}.sh
.endif
.endfor

configure-package:
.if !defined(BATCH)
	@${SETENV} ${SCRIPTS_ENV} ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL
.endif

display-message:
.if !defined(BATCH)
	@${ECHO_MSG}
	@${CAT} ${PKGMESSAGE}
	@${ECHO_MSG}
.endif

# Maintainer use only
#

maintainer-makesum:
.for arch in ${ONLY_FOR_ARCHS}
	${MAKE} ARCH=${arch} makesum
.endfor

.include <bsd.port.post.mk>
