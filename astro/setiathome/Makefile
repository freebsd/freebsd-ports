# Ports collection makefile for:    setiathome
# Date created:         22 Apr 1999
# Whom:                 stb@freebsd.org
#
# $FreeBSD$

PORTNAME=	setiathome
PORTVERSION=	3.03
PORTREVISION=	2
CATEGORIES=	astro
MASTER_SITES=	ftp://ftp.cdrom.com/pub/setiathome/ \
		ftp://alien.ssl.berkeley.edu/pub/ \
		ftp://setidata.ssl.berkeley.edu/pub/ \
		ftp://serendip.ssl.berkeley.edu/pub/
DISTNAME=	${PORTNAME}-${PORTVERSION}.${PORT_HOST}
EXTRACT_SUFX=	.tar

MAINTAINER=	clefevre@poboxes.com

.include <bsd.port.pre.mk>

#
# Global variables
#

.if !defined(PACKAGE_BUILDING) || empty(PACKAGE_BUILDING)
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
SCRIPTS_ENV+=	PACKAGE_BUILDING=${PACKAGE_BUILDING}

MAN1=		${PORTNAME}.1

#
# Local variables
#

PORT_CPU=	${ARCH}
PORT_VENDOR=	unknown
PORT_OSNAME=	freebsd
PORT_OSREL=	2.2.8
PORT_OS=	${PORT_OSNAME}${PORT_OSREL}
PORT_HOST=	${PORT_CPU}-${PORT_VENDOR}-${PORT_OS}

SBINSUBDIR?=	sbin
RCDSUBDIR=	etc/rc.d
MANSUBDIR=	man
PROG=		${PORTNAME}
SCRIPT=		${PORTNAME}.sh

# xsetiathome is currently broken at 4.2. should work at 2.x,
# don't know between 3.0 and 4.2 ? so, be conservative...
# diagnostic messages are :
#	Warning: Cannot convert string "doneB" to type Widget
#	Floating point exception (core dumped)

.if ${OSVERSION} < 300000
XBINSUBDIR=	bin
XPROG+=		x${PORTNAME}
MAN1+=		x${PORTNAME}.1
.endif

#
# Post-configure
#

post-configure:
	@${SED} -e 's.!!SUBDIR!!.${SBINSUBDIR}.g' ${FILESDIR}/${SCRIPT} > ${WRKSRC}/${SCRIPT}

#
# Install
#

do-install: install-daemon install-program install-script install-man

install-daemon:
	@${INSTALL_PROGRAM} ${WRKSRC}/${PROG} ${PREFIX}/${SBINSUBDIR}

install-program:
.if defined(XPROG)
	@${INSTALL_PROGRAM} ${WRKSRC}/${prog} ${PREFIX}/${XBINSUBDIR}
.endif

install-script:
	@${INSTALL_SCRIPT} ${WRKSRC}/${SCRIPT} ${PREFIX}/${RCDSUBDIR}

install-man:
.for mansect in 1
.for man in ${MAN${mansect}}
	@${INSTALL_MAN} ${FILESDIR}/${man} \
			${MAN${mansect}PREFIX}/${MANSUBDIR}/man${mansect}
.endfor
.endfor

#
# Post-install
#

post-install: update-plist configure-package

update-plist:
	@${GREP} -q ${SBINSUBDIR}/${PROG} ${TMPPLIST} || \
	 ${ECHO} ${SBINSUBDIR}/${PROG} >> ${TMPPLIST}
.if defined(XPROG)
	@${GREP} -q ${XBINSUBDIR}/${XPROG} ${TMPPLIST} || \
	 ${ECHO} ${XBINSUBDIR}/${XPROG} >> ${TMPPLIST}
.endif

configure-package:
.if defined(IS_INTERACTIVE)
	@${SETENV} ${SCRIPTS_ENV} ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL
.endif

.include <bsd.port.post.mk>
