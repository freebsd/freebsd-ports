# Created by: Alexey Dokuchaev <danfe@FreeBSD.org>
# $FreeBSD$

PORTNAME=	delaboratory
PORTVERSION=	0.8
PORTREVISION=	5
CATEGORIES=	graphics
MASTER_SITES=	http://BSDforge.com/projects/source/graphics/delaboratory/

MAINTAINER=	portmaster@bsdforfe.com
COMMENT=	Unique image postprocessing application

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libtiff.so:graphics/tiff

USES=		compiler:c++11-lib gmake
MAKE_ARGS=	CXX="${CXX}" WXCONFIG="${WX_CONFIG}"
USE_WX=		3.0
USE_CXXSTD=	c++11
USE_GNOME=	libxml2

PLIST_FILES=	bin/${PORTNAME}

post-patch:
	@${REINPLACE_CMD} -e 's|-Ofast.*}|${CXXFLAGS}| ; \
		s|CXXFLAGS_WX +=|& ${CXXFLAGS} -I${LOCALBASE}/include|' \
			${WRKSRC}/${MAKEFILE}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
