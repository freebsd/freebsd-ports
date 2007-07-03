# New ports collection makefile for:    sablevm
# Date created:         		9 July 2002
# Whom:                 		Archie Cobbs <archie@freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	sablevm
PORTVERSION=	1.1.6
PORTREVISION=	5
CATEGORIES=	java
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=sablevm
DISTFILES=	${PORTNAME}-${PORTVERSION}${EXTRACT_SUFX} \
		${PORTNAME}-classpath-${PORTVERSION}${EXTRACT_SUFX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Java VM created by McGill University's Sable Research Group

BUILD_DEPENDS=	jikes:${PORTSDIR}/java/jikes
LIB_DEPENDS=	popt:${PORTSDIR}/devel/popt \
		ffi:${PORTSDIR}/devel/libffi \
		gtk-x11-2.0:${PORTSDIR}/x11-toolkits/gtk20 \
		art_lgpl_2:${PORTSDIR}/graphics/libart_lgpl

USE_AUTOTOOLS=	autoconf:259 libltdl:15 libtool:15
#GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_LDCONFIG=	yes
PLIST_SUB=	PORTVERSION=${PORTVERSION}
CONFIGURE_ENV=	CFLAGS="-I${PREFIX}/include -L${PREFIX}/lib"
ONLY_FOR_ARCHS=	i386

MAN1=		java-sablevm.1 sablevm.1

INFO=		hacking vmintegration

# Directories for the SableVM source components
SABLEVMDIR=	${PORTNAME}-${PORTVERSION}
CLASSPATHDIR=	${PORTNAME}-classpath-${PORTVERSION}

post-patch:
	@${REINPLACE_CMD} -e 's|echo aout|echo elf|g' \
	${WRKDIR}/${CLASSPATHDIR}/configure

post-build:
		@${ECHO} "===>    ${CLASSPATHDIR}"
		@( cd ${.CURDIR} && ${MAKE} do-configure \
		    CONFIGURE_WRKSRC=${WRKDIR}/${CLASSPATHDIR})
		@( cd ${.CURDIR} && ${MAKE} do-build \
		    BUILD_WRKSRC=${WRKDIR}/${CLASSPATHDIR} )

post-install:
		@${ECHO} "===>    ${CLASSPATHDIR}"
		@( cd ${.CURDIR} && ${MAKE} do-install \
		    INSTALL_WRKSRC=${WRKDIR}/${CLASSPATHDIR} )

.include <bsd.port.mk>
