# Created by: Veniamin Gvozdikov <vg@FreeBSD.org>
# $FreeBSD$

PORTNAME=	impressive
PORTVERSION=	0.10.3
PORTREVISION=	10
CATEGORIES=	graphics
MASTER_SITES=	SF/${PORTNAME}/Impressive/${PORTVERSION}/
DISTNAME=	Impressive-${PORTVERSION}

MAINTAINER=	vg@FreeBSD.org
COMMENT=	The stylish way of giving presentations

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/license.txt

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}PyOpenGL>=0:graphics/py-PyOpenGL \
		${PYTHON_PKGNAMEPREFIX}pillow>0:graphics/py-pillow \
		xpdf:graphics/xpdf \
		pdftk:print/pdftk \
		xdg-open:devel/xdg-utils \
		mplayer:multimedia/mplayer \
		${PYGAME}

USES=		ghostscript:run python
NO_BUILD=	yes
NO_ARCH=	yes
PLIST_FILES=	bin/${PORTNAME} \
		man/man1/${PORTNAME}.1.gz

PORTDOCS=	${PORTNAME}.html demo.pdf

OPTIONS_DEFINE=	DOCS

do-install:
	@${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME}.py ${STAGEDIR}${PREFIX}/bin/${PORTNAME}
	@${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 ${STAGEDIR}${MAN1PREFIX}/man/man1

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
