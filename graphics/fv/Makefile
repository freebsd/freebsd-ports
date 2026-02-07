PORTNAME=	fv
PORTVERSION=	1.03
PORTREVISION=	7
CATEGORIES=	graphics
MASTER_SITES=	http://www.eaflux.com/fv/sources/
DISTNAME=	${PORTNAME}-src-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Viewer of hdr/pfm images
WWW=		http://www.eaflux.com/fv/

LICENSE=	GPLv2+

LIB_DEPENDS=	libpng.so:graphics/png

USES=		gl gmake xorg zip
USE_GL=		gl glu glut
USE_XORG=	sm x11 xext xi xmu
ALL_TARGET=	${PORTNAME}

PORTDOCS=	AUTHORS ChangeLog README
PLIST_FILES=	bin/${PORTNAME}

OPTIONS_DEFINE=	DOCS

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
