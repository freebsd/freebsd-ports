# Created by: Gvozdikov Veniamin <g.veniamin@googlemail.com>
# $FreeBSD$

PORTNAME=	tepsonic
PORTVERSION=	0.98.2
PORTREVISION=	3
CATEGORIES=	audio
MASTER_SITES=	http://www.tepsonic.org/files/
DISTNAME=	${PORTNAME}-${PORTVERSION}-src

MAINTAINER=	vg@FreeBSD.org
COMMENT=	TepSonic is a simple and fast audio player

LICENSE=	GPLv3

LIB_DEPENDS=	libtag.so:${PORTSDIR}/audio/taglib

USES=		cmake
USE_LDCONFIG=	yes
INSTALLS_ICONS=	yes
USE_QT4=	gui xml sql phonon network linguist_build \
		rcc_build qmake_build uic_build moc_build

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

post-patch:
	${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|g' \
		${WRKSRC}/3rdparty/qxt/CMakeLists.txt

.include <bsd.port.mk>
