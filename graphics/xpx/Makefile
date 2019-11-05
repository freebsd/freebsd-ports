# Created by: Seiichirou Hiraoka
# $FreeBSD$

PORTNAME=	xpx
PORTVERSION=	1.41
PORTREVISION=	2
CATEGORIES=	graphics
MASTER_SITES=	http://www2s.biglobe.ne.jp/~yav/soft/xpx/
DISTNAME=	${PORTNAME}${PORTVERSION:S/.//}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Simple pixel editing tool to generate data for KISS

WRKSRC=		${WRKDIR}/${PORTNAME}

USES=		imake:notall xorg
USE_XORG=	x11 xext

DOCSDIR=	${PREFIX}/share/doc/ja/${PORTNAME}

PORTDOCS=	xpx.doc xpxrc.eg
PLIST_FILES=	bin/xpx

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e 's|myname|my_name|g' ${WRKSRC}/magtoppm.c
	@${REINPLACE_CMD} -e '/edit_mode/d' ${WRKSRC}/work.h

pre-configure:
	@(cd ${CONFIGURE_WRKSRC}; ${SH} configure)

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for file in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${file} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
