PORTNAME=	delaboratory
PORTVERSION=	0.8
PORTREVISION=	15
CATEGORIES=	graphics
MASTER_SITES=	https://BSDforge.com/projects/source/graphics/delaboratory/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Unique image postprocessing application
WWW=		https://bsdforge.com/projects/graphics/delaboratory/

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libtiff.so:graphics/tiff

USES=		compiler:c++11-lib gmake gnome
USE_CXXSTD=	c++11
USE_GNOME=	libxml2
USE_WX=		3.0

MAKE_ARGS=	CXX="${CXX}" \
		WXCONFIG="${WX_CONFIG}"

PLIST_FILES=	bin/${PORTNAME}

post-patch:
	@${MV} ${WRKSRC}/gui_wx/semaphore.h ${WRKSRC}/gui_wx/desemaphore.h
	@${REINPLACE_CMD} -e 's|-Ofast.*}|${CXXFLAGS}| ; \
		s|CXXFLAGS_WX +=|& ${CXXFLAGS} -I${LOCALBASE}/include| ;\
		s|LDFLAGS=|LDFLAGS+=|' \
			${WRKSRC}/${MAKEFILE}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
