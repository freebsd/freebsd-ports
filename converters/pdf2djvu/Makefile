# Created by: Denise H. G. <darcsis@gmail.com>
# $FreeBSD$

PORTNAME=	pdf2djvu
PORTVERSION=	0.5.11
PORTREVISION=	11
CATEGORIES=	converters
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE}
DISTNAME=	${PORTNAME}_${PORTVERSION}${EXTRACT_SUFFIX}

MAINTAINER=	darcsis@gmail.com
COMMENT=	Pdf2djvu creates DjVu files from PDF files

DEPRECATED=	Broken for more than 6 month
EXPIRATION_DATE=	2013-11-18

BUILD_DEPENDS=	${LOCALBASE}/include/pstreams/pstream.h:${PORTSDIR}/devel/pstreams
LIB_DEPENDS=	poppler:${PORTSDIR}/graphics/poppler
LIB_DEPENDS+=	djvulibre:${PORTSDIR}/graphics/djvulibre

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	LIBS=-pthread
CPPFLAGS+=	-I${LOCALBASE}/include
USES=		pkgconfig
USE_GMAKE=	yes

BROKEN=		does not build

PLIST_FILES=	bin/pdf2djvu
MAN1=		pdf2djvu.1
MANCOMPRESSED=	no

WRKSRC=	${WRKDIR}/${PORTNAME}-${PORTVERSION}

NO_STAGE=	yes
do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin
	${INSTALL_MAN}  ${WRKSRC}/doc/${PORTNAME}.1 ${MANPREFIX}/man/man1

.include <bsd.port.mk>
