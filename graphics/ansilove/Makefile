# Created by: Dmitry Marakasov <amdmi3@FreeBSD.org>
# $FreeBSD$

PORTNAME=	ansilove
PORTVERSION=	3.0.4
CATEGORIES=	graphics textproc

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	ANSi / ASCII art to PNG converter

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libgd.so:graphics/gd

USE_GITHUB=	yes

USES=		cmake

PORTDOCS=	AUTHORS ChangeLog README.md THANKS TODO
PORTEXAMPLES=	*

PLIST_FILES=	bin/ansilove \
		man/man1/ansilove.1.gz

OPTIONS_DEFINE=	DOCS EXAMPLES

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${DOCSDIR}/
.endfor

post-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/* ${STAGEDIR}${EXAMPLESDIR}/

.include <bsd.port.mk>
