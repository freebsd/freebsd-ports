# Created by: Sean Bruno
# $FreeBSD$

PORTNAME=	Cockatrice
PORTVERSION=	2.5.1.g2018.04.16
CATEGORIES=	games

MAINTAINER=	sbruno@FreeBSD.org
COMMENT=	Cross-platform virtual tabletop for multiplayer card games

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libprotobuf.so:devel/protobuf

USE_GITHUB=	yes
GH_TAGNAME=	2018-04-16-Release-2.5.1

USES=		cmake compiler:c++11-lib
USE_QT5=	buildtools concurrent core multimedia network printsupport \
		qmake svg linguisttools widgets gui

INSTALLS_ICONS=	yes
DATADIR=	${PREFIX}/share/${PORTNAME:tl}

.include <bsd.port.mk>
