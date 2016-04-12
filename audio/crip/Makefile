# Created by: Philip Paeps <philip@paeps.cx>
# $FreeBSD$

PORTNAME=	crip
PORTVERSION=	3.9
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	http://bach.dynet.com/crip/src/

MAINTAINER=	philip@FreeBSD.org
COMMENT=	Terminal-based ripper/encoder/tagger

OPTIONS_DEFINE=	SOX DOCS
SOX_DESC=	SoX audio support

RUN_DEPENDS=	p5-CDDB_get>=0:audio/p5-CDDB_get \
		cdparanoia:audio/cdparanoia \
		oggenc:audio/vorbis-tools \
		vorbisgain:audio/vorbisgain

SOX_RUN_DEPENDS+=	sox:audio/sox
PORTDOCS=	Changelog README criprc_example

USES=		shebangfix perl5
SHEBANG_FILES=	crip editcomment editfilenames
NO_BUILD=	yes

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/crip ${STAGEDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/editcomment ${STAGEDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/editfilenames ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
