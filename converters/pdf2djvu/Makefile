# Created by: Denise H. G. <darcsis@gmail.com>
# $FreeBSD$

PORTNAME=	pdf2djvu
PORTVERSION=	0.7.17
CATEGORIES=	converters
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE}
DISTNAME=	${PORTNAME}_${PORTVERSION}${EXTRACT_SUFFIX}

MAINTAINER=	darcsis@gmail.com
COMMENT=	Pdf2djvu creates DjVu files from PDF files

LICENSE=	GPLv2

BUILD_DEPENDS=	${LOCALBASE}/include/pstreams/pstream.h:${PORTSDIR}/devel/pstreams
LIB_DEPENDS=	libpoppler.so:${PORTSDIR}/graphics/poppler \
		libdjvulibre.so:${PORTSDIR}/graphics/djvulibre

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	LIBS=-pthread
CPPFLAGS+=	-I${LOCALBASE}/include
USES=		compiler:c++11-lang gmake pkgconfig

PLIST_FILES=	bin/pdf2djvu man/man1/pdf2djvu.1.gz

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

.include <bsd.port.options.mk>

.if ${OSVERSION} < 900014
FAVORITE_COMPILER=      gcc
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN}  ${WRKSRC}/doc/${PORTNAME}.1 ${STAGEDIR}${MANPREFIX}/man/man1

.include <bsd.port.mk>
