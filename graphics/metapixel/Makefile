# Created by: Tilman Linneweh <arved@FreeBSD.org>
# $FreeBSD$

PORTNAME=	metapixel
PORTVERSION=	1.0.2
PORTREVISION=	6
CATEGORIES=	graphics
MASTER_SITES=	http://www.complang.tuwien.ac.at/schani/metapixel/files/ \
		http://mirror.roe.ch/dist/metapixel/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Photomosaic generator

LICENSE=	GPLv2

LIB_DEPENDS=	gif:${PORTSDIR}/graphics/giflib \
		jpeg:${PORTSDIR}/graphics/jpeg \
		png15:${PORTSDIR}/graphics/png

OPTIONS_DEFINE=	DOCS EXAMPLES

CPPFLAGS+=	$$(libpng-config --I_opts) -I${LOCALBASE}/include -I.
LDFLAGS+=	$$(libpng-config --L_opts) -L${LOCALBASE}/lib
USES=		gmake

MAN1=		metapixel.1
PLIST_FILES=	bin/metapixel \
		bin/metapixel-convert \
		bin/metapixel-imagesize \
		bin/metapixel-prepare \
		bin/metapixel-sizesort
PORTDOCS=	NEWS README
PORTEXAMPLES=	metapixelrc

NO_STAGE=	yes
.include <bsd.port.options.mk>

post-patch:
	@${RM} ${WRKSRC}/getopt.h

do-install:
	cd ${WRKSRC}/ && \
		${INSTALL_PROGRAM} metapixel metapixel-convert metapixel-imagesize ${PREFIX}/bin/ && \
		${INSTALL_SCRIPT} metapixel-prepare metapixel-sizesort ${PREFIX}/bin/ && \
		${INSTALL_MAN} metapixel.1 ${PREFIX}/man/man1/
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}/
	cd ${WRKSRC}/ && ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR}/
.endif
.if ${PORT_OPTIONS:MEXAMPLES}
	${MKDIR} ${EXAMPLESDIR}/
	cd ${WRKSRC}/ && ${INSTALL_DATA} ${PORTEXAMPLES} ${EXAMPLESDIR}/
.endif

.include <bsd.port.mk>
