# Created by: Dmitry Marakasov <amdmi3@FreeBSD.org>
# $FreeBSD$

PORTNAME=	irrlamb
PORTVERSION=	0.2.1
DISTVERSIONPREFIX=	v
CATEGORIES=	games

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	3D physics-based puzzle game

LICENSE=	GPLv3 # or later
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libsqlite3.so:${PORTSDIR}/databases/sqlite3 \
		libIrrlicht.so:${PORTSDIR}/x11-toolkits/irrlicht \
		libvorbis.so:${PORTSDIR}/audio/libvorbis \
		libogg.so:${PORTSDIR}/audio/libogg \
		libfreetype.so:${PORTSDIR}/print/freetype2 \
		libBulletCollision.so:${PORTSDIR}/devel/bullet

USE_GITHUB=	yes
GH_ACCOUNT=	jazztickets

USES=		cmake compiler:c++11-lib lua:53 openal

PORTDOCS=	*
PORTDATA=	*

PLIST_FILES=	bin/irrlamb \
		share/applications/irrlamb.desktop \
		share/pixmaps/irrlamb.png

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e 's|share/games|share|g' ${WRKSRC}/CMakeLists.txt \
		${WRKSRC}/deployment/${PORTNAME}

.include <bsd.port.mk>
