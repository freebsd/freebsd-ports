# Created by: Kris Kennaway <kris@FreeBSD.org>
# $FreeBSD$

PORTNAME=	cadubi
PORTVERSION=	1.3.4
DISTVERSIONPREFIX=	v
CATEGORIES=	graphics editors

MAINTAINER=	ports@FreeBSD.org
COMMENT=	ASCII drawing utility

LICENSE=	ART10

RUN_DEPENDS=	p5-Term-ReadKey>=0:devel/p5-Term-ReadKey

USE_GITHUB=	yes
GH_ACCOUNT=	statico

USES=		perl5 shebangfix
SHEBANG_FILES=	cadubi
NO_BUILD=	yes
NO_ARCH=	yes

PLIST_FILES=	bin/${PORTNAME} \
		%%DATADIR%%/help.txt \
		%%DATADIR%%/logo.txt

PORTDOCS=	*

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e 's|$$Bin/help|${DATADIR}/help|' \
		${WRKSRC}/cadubi

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/
	@${MKDIR} ${STAGEDIR}${DATADIR}
.for d in help.txt logo.txt
	${INSTALL_DATA} ${WRKSRC}/${d} ${STAGEDIR}${DATADIR}
.endfor

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.md ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/extras/ansi_term_codes.txt ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
