# Created by: dom@happygiraffe.net
# $FreeBSD$

PORTNAME=	cthumb
PORTVERSION=	4.2
PORTREVISION=	4
CATEGORIES=	graphics www
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Themeable web picture album generator

LICENSE=	GPLv2+

RUN_DEPENDS=	${LOCALBASE}/bin/pnmscale:graphics/netpbm \
		${LOCALBASE}/bin/jhead:graphics/jhead \
		p5-HTML-Parser>=0:www/p5-HTML-Parser \
		p5-URI>=0:net/p5-URI

USES=		jpeg:run perl5
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-themedir=${DATADIR}
CONFIGURE_ENV=	perl_path=${PERL}
NO_ARCH=	yes

PORTDOCS=	BUGS ChangeLog README TO-DO cthumbrc.sample

OPTIONS_DEFINE=	DOCS

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/cthumb ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/cthumb.1 ${STAGEDIR}${MAN1PREFIX}/man/man1
	@cd ${WRKSRC}/themes && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR}

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for doc in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${doc} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
