# Created by: Michael Johnson <ahze@FreeBSD.org>
# $FreeBSD$

PORTNAME=	qdbm
PORTVERSION=	1.8.78
PORTREVISION=	5
CATEGORIES=	databases
MASTER_SITES=	https://dbmx.net/qdbm/
PKGNAMESUFFIX=	-plus

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	C++ API for QDBM

LICENSE=	LGPL21
LICENSE_FILE=	${WRKDIR}/${PORTNAME}-${PORTVERSION}/COPYING

LIB_DEPENDS=	liblzo2.so:archivers/lzo2 \
		libqdbm.so:databases/qdbm

USES=		iconv shebangfix
SHEBANG_FILES=	xapidoc/installdox
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}/plus
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
CONFIGURE_ENV=	ac_cv_lib_iconv_main=yes
CXXFLAGS+=	-fsigned-char -fPIC
INSTALL_TARGET=	install-strip

post-patch:
.if defined(WITH_DEBUG)
	@${REINPLACE_CMD} 's/-DNDEBUG//' ${WRKSRC}/Makefile.in
.endif

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libxqdbm.so.3.0.0

.include <bsd.port.mk>
