# New ports collection makefile for:	tepsonic
# Date created:		2010-05-18
# Whom:			Gvozdikov Veniamin <g.veniamin@googlemail.com>
#
# $FreeBSD$
#

PORTNAME=	tepsonic
PORTVERSION=	0.98.2
CATEGORIES=	audio
MASTER_SITES=	http://www.tepsonic.org/files/
DISTNAME=	${PORTNAME}-${PORTVERSION}-src

MAINTAINER=	g.veniamin@googlemail.com
COMMENT=	TepSonic is a simple and fast audio player

LIB_DEPENDS=	tag.1:${PORTSDIR}/audio/taglib

USE_CMAKE=	yes
USE_QT_VER=	4
USE_LDCONFIG=	yes
INSTALLS_ICONS=	yes
QT_COMPONENTS=	gui xml sql phonon network linguist_build \
		rcc_build qmake_build uic_build moc_build

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

LICENSE=	GPLv3

post-patch:
	${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|g' \
		${WRKSRC}/3rdparty/qxt/CMakeLists.txt

.include <bsd.port.mk>
