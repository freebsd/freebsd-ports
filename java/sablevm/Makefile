# New ports collection makefile for:    sablevm
# Date created:         		9 July 2002
# Whom:                 		Archie Cobbs <archie@freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	sablevm
PORTVERSION=	1.1.5
CATEGORIES=	java
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=sablevm
DISTFILES=	${PORTNAME}-${PORTVERSION}${EXTRACT_SUFX} \
		${PORTNAME}-classpath-${PORTVERSION}${EXTRACT_SUFX}

MAINTAINER=	roman@ontographics.com
COMMENT=	Java VM created by McGill University's Sable Research Group

BUILD_DEPENDS=	jikes:${PORTSDIR}/java/jikes
LIB_DEPENDS=	popt:${PORTSDIR}/devel/popt \
		ffi:${PORTSDIR}/devel/libffi

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_LIBTOOL_VER=13
USE_LIBLTDL=	yes
INSTALLS_SHLIB=	yes
PLIST_SUB=	PORTVERSION=${PORTVERSION}
CONFIGURE_ENV=	CFLAGS="-I${PREFIX}/include -L${PREFIX}/lib"
ONLY_FOR_ARCHS=	i386

MAN1=		java-sablevm.1 sablevm.1

INFO=		hacking vmintegration

# Directories for the SableVM source components
SABLEVMDIR=	${PORTNAME}-${PORTVERSION}
CLASSPATHDIR=	${PORTNAME}-classpath-${PORTVERSION}

post-build:
		@${ECHO} "===>    ${CLASSPATHDIR}"
		@( cd ${.CURDIR} && ${MAKE} do-configure \
		    CONFIGURE_WRKSRC=${WRKDIR}/${CLASSPATHDIR} \
		    CONFIGURE_ARGS="--disable-gtk-peer" )
		@( cd ${.CURDIR} && ${MAKE} do-build \
		    BUILD_WRKSRC=${WRKDIR}/${CLASSPATHDIR} )

post-install:
		@${ECHO} "===>    ${CLASSPATHDIR}"
		@( cd ${.CURDIR} && ${MAKE} do-install \
		    INSTALL_WRKSRC=${WRKDIR}/${CLASSPATHDIR} )

.include <bsd.port.mk>
