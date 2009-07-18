# Ports collection makefile for:	metapixel
# Date created:			2002-05-23
# Whom:				Tilman Linneweh <arved@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=	metapixel
PORTVERSION=	1.0.2
PORTREVISION=	2
CATEGORIES=	graphics
MASTER_SITES=	http://www.complang.tuwien.ac.at/schani/metapixel/files/ \
		http://mirror.roe.ch/dist/metapixel/

MAINTAINER=	daniel@roe.ch
COMMENT=	A photomosaic generator

LIB_DEPENDS=	png.5:${PORTSDIR}/graphics/png \
		jpeg.10:${PORTSDIR}/graphics/jpeg \
		ungif.5:${PORTSDIR}/graphics/libungif

USE_GMAKE=	yes
MAKE_ENV=	CPPFLAGS="${CPPFLAGS} -I${LOCALBASE}/include -I." \
		LDFLAGS="${LDFLAGS} -L${LOCALBASE}/lib"

PLIST_FILES=	bin/metapixel bin/metapixel-convert bin/metapixel-imagesize \
		bin/metapixel-prepare bin/metapixel-sizesort \
		share/examples/metapixel/metapixelrc
PLIST_DIRS=	share/examples/metapixel
PORTDOCS=	README NEWS
MAN1=		metapixel.1

post-patch:
	@${RM} ${WRKSRC}/getopt.h

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/metapixel ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/metapixel-convert ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/metapixel-imagesize ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/metapixel-prepare ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/metapixel-sizesort ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/metapixel.1 ${PREFIX}/man/man1
	${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/metapixelrc ${EXAMPLESDIR}
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR}
.endif

.include <bsd.port.mk>
