PORTNAME=	imageindex
PORTVERSION=	2.0
PORTREVISION=	2
CATEGORIES=	graphics
MASTER_SITES=	http://www.edwinh.org/imageindex/release/ \
		http://www.reynoldsnet.org/imageindex/release/

MAINTAINER=	johnjen@reynoldsnet.org
COMMENT=	Digital photo gallery tool

RUN_DEPENDS=	mplayer:multimedia/mplayer \
		p5-Image-Info>=0:graphics/p5-Image-Info

USES=		jpeg magick:6,run perl5
USE_PERL5=	run
MAKE_ARGS+=	PERLPATH=${PERL} PREFIX=${STAGEDIR}${PREFIX}

PLIST_FILES=	bin/imageindex bin/autocaption \
		man/man1/imageindex.1.gz
PORTDOCS=	README
OPTIONS_DEFINE=	DOCS

post-patch:
	${REINPLACE_CMD} -e 's|share/man|man|' ${WRKSRC}/Makefile

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
