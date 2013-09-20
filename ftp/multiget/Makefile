# Created by: alepulver
# $FreeBSD$

PORTNAME=	multiget
PORTVERSION=	1.1.3
PORTREVISION=	6
CATEGORIES=	ftp www
MASTER_SITES=	SF/${PORTNAME}/OldFiles

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An http/ftp downloader with a nice GUI

USE_WX=		2.6+
MAKEFILE=	makefile
ALL_TARGET=	MultiGet
WRKSRC=		${WRKDIR}/${DISTNAME}/src

PLIST_FILES=	bin/${PORTNAME}

NO_STAGE=	yes
post-patch:
	@${REINPLACE_CMD} -e \
		's|g++|${CXX}|; \
		 s|\(CFLAGS\) =|\1 +=|; \
		 s|wx-config|${WX_CONFIG}|' \
		 ${WRKSRC}/${MAKEFILE}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/MultiGet ${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
