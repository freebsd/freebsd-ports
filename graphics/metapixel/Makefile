# Created by: Tilman Linneweh <arved@FreeBSD.org>
# $FreeBSD$

PORTNAME=	metapixel
PORTVERSION=	1.0.2
PORTREVISION=	10
CATEGORIES=	graphics
MASTER_SITES=	http://www.complang.tuwien.ac.at/schani/metapixel/files/ \
		http://mirror.roe.ch/dist/metapixel/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Photomosaic generator

LICENSE=	GPLv2

LIB_DEPENDS=	libgif.so:${PORTSDIR}/graphics/giflib \
		libpng.so:${PORTSDIR}/graphics/png

CPPFLAGS+=	$$(libpng-config --I_opts) -I${LOCALBASE}/include -I.
LDFLAGS+=	$$(libpng-config --L_opts) -L${LOCALBASE}/lib
USES=		gmake jpeg shebangfix
SHEBANG_FILES=	metapixel-prepare metapixel-sizesort

PLIST_FILES=	bin/metapixel \
		bin/metapixel-convert \
		bin/metapixel-imagesize \
		bin/metapixel-prepare \
		bin/metapixel-sizesort \
		man/man1/metapixel.1.gz
PORTDOCS=	NEWS README
PORTEXAMPLES=	metapixelrc

OPTIONS_DEFINE=	DOCS EXAMPLES

post-patch:
	@${RM} ${WRKSRC}/getopt.h

do-install:
	(cd ${WRKSRC} && ${INSTALL_PROGRAM} metapixel metapixel-convert \
		metapixel-imagesize ${STAGEDIR}${PREFIX}/bin)
	(cd ${WRKSRC} && ${INSTALL_SCRIPT} metapixel-prepare \
		metapixel-sizesort ${STAGEDIR}${PREFIX}/bin)
	${INSTALL_MAN} ${WRKSRC}/metapixel.1 ${STAGEDIR}${PREFIX}/man/man1
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR})
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	(cd ${WRKSRC} && ${INSTALL_DATA} ${PORTEXAMPLES} ${STAGEDIR}${EXAMPLESDIR})

.include <bsd.port.mk>
