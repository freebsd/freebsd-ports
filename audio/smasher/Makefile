# Created by: chris@officialunix.com
# $FreeBSD$

PORTNAME=	smasher
PORTVERSION=	1.1.7
PORTREVISION=	6
CATEGORIES=	audio
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Cross platform audio loop slicer

LICENSE=	LGPL20
LICENSE_FILE=	${WRKSRC}/COPYING.LIB

LIB_DEPENDS=	libsndfile.so:audio/libsndfile \
		libmad.so:audio/libmad \
		libcsound64.so:audio/csound

GNU_CONFIGURE=	yes
USES=		desktop-file-utils gmake pkgconfig
USE_CXXSTD=	c++11
USE_GCC=	yes
USE_WX=		2.8
WX_CONF_ARGS=	absolute

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/share/pixmaps|${PREFIX}/share/pixmaps|g' \
		-e 's|/usr/share/applications|${DESKTOPDIR}|g' \
		${WRKSRC}/src/Makefile.in

.include <bsd.port.mk>
