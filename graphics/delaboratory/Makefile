# Created by: Alexey Dokuchaev <danfe@FreeBSD.org>
# $FreeBSD$

PORTNAME=	delaboratory
PORTVERSION=	0.8
CATEGORIES=	graphics
MASTER_SITES=	GOOGLE_CODE

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Unique image postprocessing application

LICENSE=	GPLv3

USES=		gmake
MAKE_ARGS=	CXX="${CXX}" WXCONFIG="${WX_CONFIG}"
USE_WX=		2.8+

PLIST_FILES=	bin/${PORTNAME}

post-patch:
	${REINPLACE_CMD} -e 's,-Ofast.*},${CXXFLAGS},' ${WRKSRC}/${MAKEFILE}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin

.include <bsd.port.mk>
