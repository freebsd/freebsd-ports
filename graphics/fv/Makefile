# Created by: Igor Pokrovsky <ip@doom.homeunix.org>
# $FreeBSD$

PORTNAME=	fv
PORTVERSION=	1.03
PORTREVISION=	2
CATEGORIES=	graphics
MASTER_SITES=	http://www.eaflux.com/fv/sources/
DISTNAME=	${PORTNAME}-src-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Viewer of hdr/pfm images

LICENSE=	GPLv2

LIB_DEPENDS=	png15:${PORTSDIR}/graphics/png

USES=		pkgconfig zip
USE_GL=		glut
USE_GMAKE=	yes
ALL_TARGET=	${PORTNAME}

CXXFLAGS+=	$$(pkg-config --cflags libpng15) \
		-I${LOCALBASE}/include ${PTHREAD_CFLAGS}
LDFLAGS+=	$$(pkg-config --libs libpng15) \
		-L${LOCALBASE}/lib -lglut -lGLU -lGL -lbz2 -lm -lz -llzma \
		${PTHREAD_LIBS}

PORTDOCS=	AUTHORS ChangeLog README
PLIST_FILES=	bin/${PORTNAME}

NO_STAGE=	yes

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

.if !defined(WITH_DEBUG)
CXXFLAGS+=	-DNDEBUG
.endif

post-patch:
	@${REINPLACE_CMD} -e \
		's|^CXX=|CXX?=| ; \
		 s|^CXXFLAGS=|CXXFLAGS?=| ; \
		 s|^LDFLAGS=|LDFLAGS?=|' ${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin

.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
.endif

.include <bsd.port.mk>
