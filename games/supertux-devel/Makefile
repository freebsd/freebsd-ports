# $FreeBSD$

PORTNAME=	supertux
PORTVERSION=	0.3.4
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE}
PKGNAMESUFFIX=	-devel

MAINTAINER=	makc@FreeBSD.org
COMMENT=	Side-scroller game similar to Super Mario Brothers

BUILD_DEPENDS=	${LOCALBASE}/include/boost/smart_ptr.hpp:${PORTSDIR}/devel/boost-libs
LIB_DEPENDS=	libphysfs.so:${PORTSDIR}/devel/physfs \
		libcurl.so:${PORTSDIR}/ftp/curl \
		libvorbis.so:${PORTSDIR}/audio/libvorbis

USE_BZIP2=	yes
USE_SDL=	image
USE_OPENAL=	al
USE_GL=		glew
USES=		cmake:outsource iconv
LDFLAGS+=	-L${LOCALBASE}/lib ${ICONV_LIB}

post-patch:
	${REINPLACE_CMD} -e '/^Icon=/s,supertux.png,supertux2.png,' \
		${WRKSRC}/supertux2.desktop

.include <bsd.port.mk>
