# Ports collection makefile for:    setiathome
# Date created:         22 Apr 1999
# Whom:                 stb@freebsd.org
#
# $FreeBSD$

PORTNAME=	setiathome
PORTVERSION=	2.4
CATEGORIES=	astro
MASTER_SITES=   ftp://ftp.cdrom.com/pub/setiathome/ \
		ftp://alien.ssl.berkeley.edu/pub/ \
		ftp://setidata.ssl.berkeley.edu/pub/ \
		ftp://serendip.ssl.berkeley.edu/pub/

MAINTAINER=	stb@freebsd.org

ONLY_FOR_ARCHS=	i386

EXTRACT_CMD=		tar
EXTRACT_BEFORE_ARGS=	-xf
EXTRACT_AFTER_ARGS=

MAN1=		setiathome.1 xsetiathome.1

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 310000
DISTFILES=	setiathome-2.4.i386-unknown-freebsd3.3.tar
WRKSRC=		setiathome-2.4.i386-unknown-freebsd3.3
.elif ${OSVERSION} >= 226000
DISTFILES=	setiathome-2.4.i386-unknown-freebsd2.2.8.tar
WRKSRC=		setiathome-2.4.i386-unknown-freebsd2.2.8
.else
DISTFILES=
.endif

.if make(makesum) || defined(FETCH_ALL)
DISTFILES=	setiathome-2.4.i386-unknown-freebsd2.2.8.tar	\
		setiathome-2.4.i386-unknown-freebsd3.3.tar
.endif

NO_BUILD=	"binary distribution"

MAN1=		setiathome.1 xsetiathome.1

NO_CDROM=	"interactive install"

.if !defined(PACKAGE_BUILDING)
IS_INTERACTIVE=	yes
.endif

pre-fetch:
	@if [ -z "${DISTFILES}" ]; then \
		${ECHO} "It seems you are running FreeBSD `uname -r`, which is not currently";	\
		${ECHO} "supported.  SETI@home currently supports only FreeBSD 2.2.6 and above,";	\
		${ECHO} "FreeBSD 3.1. and above, and FreeBSD 4.0."; \
		${ECHO} \
		exit 72; \
	fi;

do-install:
	${INSTALL_PROGRAM} ${WRKDIR}/${WRKSRC}/setiathome ${PREFIX}/bin
	${INSTALL_SCRIPT}  ${FILESDIR}/setiathome.sh ${PREFIX}/etc/rc.d
	${INSTALL_MAN}     ${FILESDIR}/setiathome.1 ${MAN1PREFIX}/man/man1
	${INSTALL_MAN}     ${FILESDIR}/xsetiathome.1 ${MAN1PREFIX}/man/man1

post-install:
	@PKG_PREFIX=${PREFIX} PACKAGE_BUILDING=${PACKAGE_BUILDING} \
		${SH} ${PKGDIR}/INSTALL ${PKGNAME} POST-INSTALL

.include <bsd.port.post.mk>
