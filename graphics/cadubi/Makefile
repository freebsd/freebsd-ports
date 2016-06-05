# Created by: Kris Kennaway <kris@FreeBSD.org>
# $FreeBSD$

PORTNAME=	cadubi
PORTVERSION=	1.3.1
DISTVERSIONPREFIX=	v
PORTREVISION=	1
CATEGORIES=	graphics editors

MAINTAINER=	ports@FreeBSD.org
COMMENT=	ASCII drawing utility

LICENSE=	ART10

RUN_DEPENDS=	p5-Term-ReadKey>=0:devel/p5-Term-ReadKey

GH_ACCOUNT=	statico
USE_GITHUB=	yes
USES=		perl5 shebangfix
SHEBANG_FILES=	cadubi
NO_BUILD=	yes

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
	@(cd ${WRKSRC} && ${INSTALL_DATA} ${d} ${STAGEDIR}${DATADIR})
.endfor

	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.md ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/extras/ansi_term_codes.txt ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
