# New ports collection makefile for:   	stella
# Date created:			March 4, 1999
# Whom:				Jacques Vidrine <nectar@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	stella
PORTVERSION=	1.3
PORTREVISION=	1
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	${PORTNAME}-${PORTVERSION}-src

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A multi-platform Atari 2600 VCS emulator

LIB_DEPENDS=	png.5:${PORTSDIR}/graphics/png

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
BUILD_WRKSRC=	${WRKSRC}/src/build

USE_XLIB=	yes
USE_GMAKE=	yes
MAKEFILE=	makefile
PLIST_SUB=	STELLA_BIN="${STELLA_BIN}"

.if defined(WITHOUT_SDL)
ALL_TARGET=	freebsd-x
STELLA_BIN=	stella.x11
.else
USE_SDL=	yes
ALL_TARGET=	freebsd-sdl
STELLA_BIN=	stella.sdl
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/build/${STELLA_BIN} ${PREFIX}/bin
	@${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/src/emucore/stella.pro ${DATADIR}
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	cd ${WRKSRC}/docs && ${FIND} . | \
		${CPIO} -pdm -L -R ${SHAREOWN}:${SHAREGRP} ${DOCSDIR}
.endif

.include <bsd.port.mk>
