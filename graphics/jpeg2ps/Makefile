# Created by: Lars Koeller <Lars.Koeller@Uni-Bielefeld.de>
# $FreeBSD$

PORTNAME=	jpeg2ps
PORTVERSION=	1.9
PORTREVISION=	4
CATEGORIES=	graphics converters
MASTER_SITES=	http://www.pdflib.com/fileadmin/pdflib/products/more/jpeg2ps/

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	Converter for JPEG compressed images to PostScript Level 2

BROKEN=		No public distfiles
DEPRECATED=	Broken for more than 6 months
EXPIRATION_DATE=	2015-11-26

LIB_DEPENDS=	libpaper.so:${PORTSDIR}/print/libpaper

OPTIONS_DEFINE=	DOCS
CFLAGS=		-DLIBPAPER -I${LOCALBASE}/include
LDADD=		-lm -lpaper -L${LOCALBASE}/lib
MAKE_ARGS=	LDADD="${LDADD}"

PLIST_FILES=	bin/jpeg2ps man/man1/jpeg2ps.1.gz

PORTDOCS=	jpeg2ps.txt

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/jpeg2ps ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/jpeg2ps.1 ${STAGEDIR}${MANPREFIX}/man/man1
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/jpeg2ps.txt ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
