# Created by: Kris Kennaway <kris@FreeBSD.org>
# $FreeBSD$

PORTNAME=	cadubi
PORTVERSION=	1.3
PORTREVISION=	1
CATEGORIES=	graphics editors
MASTER_SITES=	http://langworth.com/pub/

MAINTAINER=	nemysis@gmx.ch
COMMENT=	ASCII drawing utility

LICENSE=	ART10

RUN_DEPENDS=	p5-Term-ReadKey>=0:${PORTSDIR}/devel/p5-Term-ReadKey

USE_PERL5=	yes
NO_BUILD=	yes

PLIST_FILES=	bin/${PORTNAME}

PORTDATA=	*
PORTDOCS=	*

.include <bsd.port.options.mk>

do-configure:
	@${REINPLACE_CMD} -i '' -e 's|Bin/help|Bin/../share/cadubi/help|' \
		${WRKSRC}/cadubi

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin
	${MKDIR} ${DATADIR}
.for d in help.txt logo.txt
	@(cd ${WRKSRC} && ${INSTALL_DATA} ${d} ${DATADIR})
.endfor

.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/extras/ansi_term_codes.txt ${DOCSDIR}
.endif

.include <bsd.port.mk>
