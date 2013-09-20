# Created by: Lars Koeller <Lars.Koeller@Uni-Bielefeld.de>
# $FreeBSD$

PORTNAME=	jpeg2ps
PORTVERSION=	1.9
PORTREVISION=	3
CATEGORIES=	graphics converters
MASTER_SITES=	http://www.pdflib.com/fileadmin/pdflib/products/more/jpeg2ps/

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	Converter for JPEG compressed images to PostScript Level 2

LIB_DEPENDS=	paper:${PORTSDIR}/print/libpaper

OPTIONS_DEFINE=	DOCS
CFLAGS=		-DLIBPAPER -I${LOCALBASE}/include
LDADD=		-lm -lpaper -L${LOCALBASE}/lib
MAKE_ARGS=	LDADD="${LDADD}"
MAN1=		jpeg2ps.1
PLIST_FILES=	bin/jpeg2ps

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDOCS}
PORTDOCS=	jpeg2ps.txt
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/jpeg2ps ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/jpeg2ps.1 ${MANPREFIX}/man/man1
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/jpeg2ps.txt ${DOCSDIR}
.endif

.include <bsd.port.mk>
