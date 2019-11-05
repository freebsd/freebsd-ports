# Created by: NAKATA Maho <maho@FreeBSD.org>
# $FreeBSD$

PORTNAME=	mxp
PORTVERSION=	1.3
PORTREVISION=	5
CATEGORIES=	graphics
MASTER_SITES=	SUNSITE/apps/math/fractals

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Application for computing/exploring Mandelbrot set

LICENSE=	GPLv2

WRKSRC=		${WRKDIR}/${PORTNAME}

USES=		xorg
USE_XORG=	xaw xbitmaps xpm
ALL_TARGET=	${PORTNAME}
MAKE_JOBS_UNSAFE=	yes

CFLAGS+=	-Wno-error=return-type
CPPFLAGS+=	-I${LOCALBASE}/include -DXPM
LDFLAGS+=	-L${LOCALBASE}/lib -lXpm

PORTDOCS=	README
PLIST_FILES=	bin/${PORTNAME} share/pixmaps/${PORTNAME}.xpm

DESKTOP_ENTRIES="Mxp" "Mandelbrot Explorer" \
		"${PREFIX}/share/pixmaps/${PORTNAME}.xpm" "${PORTNAME}" \
		"" ""

OPTIONS_DEFINE=	DOCS

post-patch:
	@(cd ${WRKSRC} && ${SED} -e \
		's|$$(XINC)|$$(CPPFLAGS)| ; \
		 s|-L/X/X11/lib|$$(LDFLAGS)|' Makefile.noimake > Makefile)

post-build:
	@${LN} -sf icon.xpm ${WRKSRC}/${PORTNAME}.xpm

do-install:
	(cd ${WRKSRC} && ${INSTALL_PROGRAM} ${PORTNAME} \
		${STAGEDIR}${PREFIX}/bin)
	(cd ${WRKSRC} && ${INSTALL_DATA} ${PORTNAME}.xpm \
		${STAGEDIR}${PREFIX}/share/pixmaps)
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} \
		${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
