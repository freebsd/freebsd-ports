# Created by: Anonymous <swell.k@gmail.com>
# $FreeBSD$

PORTNAME=	apngasm
PORTVERSION=	2.8
DISTVERSIONSUFFIX=-src
CATEGORIES=	graphics
MASTER_SITES=	SF/${PORTNAME}/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Create Animated PNG from a sequence of files

LICENSE=	ZLIB

OPTIONS_DEFINE=	DOCS STATIC

NO_WRKSUBDIR=	yes

USES=		dos2unix gmake zip

LDFLAGS+=	-lz

PORTDOCS=	readme.txt
PLIST_FILES=	bin/${PORTNAME}

STATIC_BUILD_DEPENDS=	${LOCALBASE}/lib/libpng.a:${PORTSDIR}/graphics/png
STATIC_MAKE_ENV=	STATIC=1

.include <bsd.port.options.mk>

.if ! ${PORT_OPTIONS:MSTATIC}
LIB_DEPENDS+=	libpng15.so:${PORTSDIR}/graphics/png
.endif

do-install:
	(cd ${WRKSRC} && ${INSTALL_PROGRAM} ${PORTNAME} \
		${STAGEDIR}${PREFIX}/bin)
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} \
		${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
