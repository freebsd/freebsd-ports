# Created by: NAKATA Maho <maho@FreeBSD.org>
# $FreeBSD$

PORTNAME=	mxp
PORTVERSION=	1.3
PORTREVISION=	4
CATEGORIES=	graphics
MASTER_SITES=	SUNSITE
MASTER_SITE_SUBDIR=apps/math/fractals

MAINTAINER=	maho@FreeBSD.org
COMMENT=	Application for computing/exploring Mandelbrot set

WRKSRC=		${WRKDIR}/${PORTNAME}
ALL_TARGET=
USE_XORG=	xaw xbitmaps xpm
MAKE_JOBS_UNSAFE=	yes

PLIST_FILES=	bin/${PORTNAME} \
		%%PORTDOCS%%%%DOCSDIR%%/README
PLIST_DIRS=	%%PORTDOCS%%%%DOCSDIR%%

NO_STAGE=	yes
.include <bsd.port.options.mk>

post-extract:
	@${CP} ${WRKSRC}/Makefile.noimake ${WRKSRC}/Makefile
post-patch:
	@${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|g; \
				s|%%LOCALBASE%%|${LOCALBASE}|g; \
				s|%%CFLAGS%%|${CFLAGS}|g; \
				s|%%CC%%|${CC}|g'  ${WRKSRC}/Makefile
do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif

.include <bsd.port.mk>
