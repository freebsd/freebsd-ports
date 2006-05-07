# New ports collection makefile for:   mxp
# Date Created:                18 March 2004
# Whom:                        NAKATA Maho <maho@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	mxp
PORTVERSION=	1.3
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR=apps/math/fractals

MAINTAINER=	maho@FreeBSD.org
COMMENT=	Application for computing/exploring Mandelbrot set

WRKSRC=		${WRKDIR}/${PORTNAME}
USE_XPM=	yes
ALL_TARGET=

post-extract:
	@${CP} ${WRKSRC}/Makefile.noimake ${WRKSRC}/Makefile
post-patch:
	@${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|g ; \
				s|%%X11BASE%%|${X11BASE}|g ; \
				s|%%CFLAGS%%|${CFLAGS}|g ; \
				s|%%LOCALBASE%%|${LOCALBASE}|g ; \
				s|%%CC%%|${CC}|g'  ${WRKSRC}/Makefile
do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/mxp ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif

.include <bsd.port.mk>
