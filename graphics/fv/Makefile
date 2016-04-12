# Created by: Igor Pokrovsky <ip@doom.homeunix.org>
# $FreeBSD$

PORTNAME=	fv
PORTVERSION=	1.03
PORTREVISION=	5
CATEGORIES=	graphics
MASTER_SITES=	http://www.eaflux.com/fv/sources/
DISTNAME=	${PORTNAME}-src-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Viewer of hdr/pfm images

LICENSE=	GPLv2

LIB_DEPENDS=	libpng.so:graphics/png

USES=		gmake pkgconfig zip
USE_GL=		glut
ALL_TARGET=	${PORTNAME}

CXXFLAGS+=	$$(pkg-config --cflags libpng) -I${LOCALBASE}/include
LDFLAGS+=	$$(pkg-config --libs libpng) -L${LOCALBASE}/lib -lglut \
		-lGLU -lGL -lbz2 -lm -lz -llzma -lpthread

PORTDOCS=	AUTHORS ChangeLog README
PLIST_FILES=	bin/${PORTNAME}

OPTIONS_DEFINE=	DEBUG DOCS

.include <bsd.port.options.mk>

.if ! ${PORT_OPTIONS:MDEBUG}
CXXFLAGS+=	-DNDEBUG
.endif

post-patch:
	@${REINPLACE_CMD} -e \
		's|^CXX=|CXX?=| ; \
		 s|^CXXFLAGS=|CXXFLAGS?=| ; \
		 s|^LDFLAGS=|LDFLAGS?=|' ${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
