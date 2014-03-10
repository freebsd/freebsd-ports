# $FreeBSD$

PORTNAME=	l2p
PORTVERSION=	1.1.1
PORTREVISION=	3
CATEGORIES=	graphics print perl5
MASTER_SITES=	http://static.redsymbol.net/software/l2p/dist/ \
		http://nivit.altervista.org/FreeBSD/ports/distfiles/

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	Create PNG images from LaTeX math expressions

RUN_DEPENDS=	convert:${PORTSDIR}/graphics/ImageMagick

NO_BUILD=	yes

OPTIONS_DEFINE=	DOCS

PLIST_FILES=	bin/l2p
PORTDOCS=	l2p.txt l2p.html

SHEBANG_FILES=	${WRKSRC}/${PORTNAME}

USE_PERL5=	run
USE_TEX=	latex dvipsk
USES=		perl5 shebangfix zip

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

NO_STAGE=	yes
.include <bsd.port.options.mk>

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
.endif

.include <bsd.port.mk>
