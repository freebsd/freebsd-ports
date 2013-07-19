# $FreeBSD$

PORTNAME=	supertux
PORTVERSION=	0.3.4
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE}
PKGNAMESUFFIX=	-devel

MAINTAINER=	makc@FreeBSD.org
COMMENT=	SuperTux is a side-scroller similar to Super Mario Brothers

BUILD_DEPENDS=	${LOCALBASE}/include/boost/smart_ptr.hpp:${PORTSDIR}/devel/boost-libs
LIB_DEPENDS=	physfs.1:${PORTSDIR}/devel/physfs \
		curl:${PORTSDIR}/ftp/curl \
		vorbis.4:${PORTSDIR}/audio/libvorbis

USE_BZIP2=	yes
USE_SDL=	image
USE_OPENAL=	al
USE_GL=		glew
USES=		cmake:outsource
MAKE_JOBS_SAFE=	yes

post-patch:
	${REINPLACE_CMD} -e '/^Icon=/s,supertux.png,supertux2.png,' \
		${WRKSRC}/supertux2.desktop

.include <bsd.port.mk>
