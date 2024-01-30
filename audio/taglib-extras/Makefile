PORTNAME=	taglib-extras
PORTVERSION=	1.0.1
CATEGORIES=	audio
MASTER_SITES=	KDE/stable/${PORTNAME}/${PORTVERSION}/src

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Extra taglib features for Amarok 2.2
WWW=		http://websvn.kde.org/trunk/kdesupport/taglib-extras/

DEPRECATED=		Incompatible with taglib 2.x and unmaintained upstream since 2015
EXPIRATION_DATE=	2024-02-14

LIB_DEPENDS=	libtag.so:audio/taglib

USES=		cmake

post-extract:
	${REINPLACE_CMD} -e 's|$${LIB_INSTALL_DIR}/pkgconfig|libdata/pkgconfig|' \
		${WRKSRC}/CMakeLists.txt

.include <bsd.port.mk>
