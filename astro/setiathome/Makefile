# Ports collection makefile for:    setiathome
# Date created:         22 Apr 1999
# Whom:                 stb@freebsd.org
#
# $FreeBSD$

PORTNAME=	setiathome
PORTVERSION=	3.03
PORTREVISION=	3
CATEGORIES=	astro
MASTER_SITES=	ftp://ftp.cdrom.com/pub/setiathome/ \
		ftp://alien.ssl.berkeley.edu/pub/ \
		ftp://setidata.ssl.berkeley.edu/pub/ \
		ftp://serendip.ssl.berkeley.edu/pub/
DISTNAME=	${PORTNAME}-${PORTVERSION}.${PORT_HOST}
EXTRACT_SUFX=	.tar

MAINTAINER?=	cyrille.lefevre@laposte.net

.include <bsd.port.pre.mk>

# Global variables
#

.if !defined(BATCH)
IS_INTERACTIVE=	yes
.endif

ONLY_FOR_ARCHS=	i386

NO_BUILD=	"binary distribution"
NO_CDROM=	"interactive install"

.if ${OSVERSION} <= 226000
BROKEN=		"currently supports only FreeBSD 2.2.6 and above"
.endif

EXTRACT_CMD=	${CAT}
EXTRACT_BEFORE_ARGS=

STRIP=		# aout is already stripped
SCRIPTS_ENV+=	PKG_PREFIX=${PREFIX}
PLIST_SUB=	X11PORTS=${X11PORTS}

MAN1=		${PORTNAME}.1

MSG_FILE=	${PKGDIR}/pkg-message
PKGMESSAGE=	${WRKDIR}/pkg-message
PKGDEINSTALL=	${PKGINSTALL}

# Local variables
#

PORT_CPU=	${ARCH}
PORT_VENDOR=	unknown
PORT_OSNAME=	freebsd
PORT_OSREL=	2.2.8
PORT_OS=	${PORT_OSNAME}${PORT_OSREL}
PORT_HOST=	${PORT_CPU}-${PORT_VENDOR}-${PORT_OS}

SBIN_DIR=	${PREFIX}/sbin
CONF_DIR=	${PREFIX}/etc
RC_DIR=		${PREFIX}/etc/rc.d

SAMP_SUFX=	.sample

BIN_FILE=	setiathome
RC_FILES=	setiathome

# xsetiathome is currently broken at 4.2. should work at 2.x,
# don't know between 3.0 and 4.2 ? so, be conservative...
# diagnostic messages are :
#	Warning: Cannot convert string "doneB" to type Widget
#	Floating point exception (core dumped)

.if ${OSVERSION} < 300000
MAN1+=		x${PORTNAME}.1
XBIN_DIR=	${PREFIX}/bin
XBIN_FILE+=	xsetiathome
X11PORTS=
.else
X11PORTS=	"@comment "
.endif

#
#

post-patch: patch-message

patch-message:
	@${SED} 's|%%PREFIX%%|${PREFIX}|g' ${MSG_FILE} > ${PKGMESSAGE}

# Install
#

do-install: install-daemon install-program install-man

install-daemon:
	@${INSTALL_PROGRAM} ${WRKSRC}/${BIN_FILE} ${SBIN_DIR}

install-program:
.if defined(XPROG)
	@${INSTALL_PROGRAM} ${WRKSRC}/${XBIN_FILE} ${XBIN_DIR}
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
		${CONF_DIR}/rc.${file}.conf${SAMP_SUFX}
.if !exists(${CONF_DIR}/rc.${file}.conf)
	@${INSTALL_DATA} ${FILESDIR}/rc.${file}.conf ${CONF_DIR}
.endif
.endif
.if exists(${FILESDIR}/${file}.sh)
	@${INSTALL_SCRIPT} ${FILESDIR}/${file}.sh ${RC_DIR}
.endif
.endfor

configure-package:
.if !defined(BATCH)
	@${SETENV} ${SCRIPTS_ENV} ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL
.endif

display-message:
.if !defined(BATCH)
	@${CAT} ${PKGMESSAGE}
.endif

.include <bsd.port.post.mk>
