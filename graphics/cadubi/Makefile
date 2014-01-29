# Created by: Kris Kennaway <kris@FreeBSD.org>
# $FreeBSD$

PORTNAME=	cadubi
PORTVERSION=	1.3
PORTREVISION=	1
CATEGORIES=	graphics editors
MASTER_SITES=	http://langworth.com/pub/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	ASCII drawing utility

LICENSE=	ART10

RUN_DEPENDS=	p5-Term-ReadKey>=0:${PORTSDIR}/devel/p5-Term-ReadKey

USES=		perl5
NO_BUILD=	yes

PLIST_FILES=	bin/${PORTNAME} \
		%%DATADIR%%/help.txt \
		%%DATADIR%%/logo.txt
PLIST_DIRS=	%%DATADIR%%

PORTDOCS=	*

OPTIONS_DEFINE=	DOCS

do-configure:
	@${REINPLACE_CMD} -e \
		's|/usr/local/stow/perl-5.8.x/bin/perl|${PERL}|; \
		s|$$Bin/help|${DATADIR}/help|' \
		${WRKSRC}/cadubi

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/
	@${MKDIR} ${STAGEDIR}${DATADIR}
.for d in help.txt logo.txt
	@(cd ${WRKSRC} && ${INSTALL_DATA} ${d} ${STAGEDIR}${DATADIR})
.endfor

	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/extras/ansi_term_codes.txt ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
