# Created by: Kimura Fuyuki <fuyuki@nigredo.org>
# $FreeBSD$

PORTNAME=	qdbm
PORTVERSION=	1.8.78
PORTREVISION=	4
CATEGORIES=	databases
MASTER_SITES=	https://dbmx.net/qdbm/

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	Quick Database Manager

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	liblzo2.so:archivers/lzo2

USES=		iconv
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
CONFIGURE_ENV=	ac_cv_lib_iconv_main=yes
CONFIGURE_ARGS=	--enable-bzip --enable-lzo --enable-zlib \
		--enable-iconv --enable-pthread
CPPFLAGS+=	-I${LOCALBASE}/include
CFLAGS+=	-fPIC -fsigned-char
LIBS+=		-L${LOCALBASE}/lib ${ICONV_LIB}
MAKE_ARGS=	MYDATADIR="${DOCSDIR}" MYDOCS="${PORTDOCS}" \
		MYPCDIR="${PREFIX}/libdata/pkgconfig"
INSTALL_TARGET=	install-strip
PORTDOCS=	ChangeLog NEWS

OPTIONS_DEFINE=	DOCS

post-patch:
.if defined(WITH_DEBUG)
	@${REINPLACE_CMD} 's/-DNDEBUG//' ${WRKSRC}/Makefile.in
.endif

post-build:
	cd ${WRKSRC}/lab && ${MAKE} CC="${CC}" CFLAGS="${CFLAGS}" \
	    CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}" \
	    fmtcnv031127

post-install:
	${INSTALL_PROGRAM} ${WRKSRC}/lab/fmtcnv031127 ${STAGEDIR}${PREFIX}/bin
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libqdbm.so.14.14.0

.include <bsd.port.mk>
