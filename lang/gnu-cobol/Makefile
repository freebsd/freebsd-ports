# Created by: ijliao

PORTNAME=	gnucobol
PORTVERSION=	3.1.2
PORTREVISION=	1
CATEGORIES=	lang
MASTER_SITES=	GNU/gnucobol

MAINTAINER=	wen@FreeBSD.org
COMMENT=	Free/libre COBOL compiler

LICENSE=	GPLv3 LGPL3
LICENSE_COMB=	multi

LIB_DEPENDS=	libgmp.so:math/gmp \
		libcjson.so:devel/libcjson \
		libxml2.so:textproc/libxml2

USES=		bdb gmake libtool ncurses tar:xz
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
TEST_TARGET=	check
TEST_ENV=	TESTSUITEFLAGS=--jobs=${MAKE_JOBS_NUMBER}

INFO=		gnucobol
DATADIR=	${PREFIX}/share/gnucobol

INSTALL_TARGET=	install-strip
SSP_CFLAGS?=	-fstack-protector # XXX -strong fails to build
CPPFLAGS+=	-I${BDB_INCLUDE_DIR} -I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

OPTIONS_DEFINE=	NLS
OPTIONS_SUB=	yes
NLS_USES=	gettext
NLS_CONFIGURE_ENABLE=nls

post-patch:
	@${REINPLACE_CMD} -e 's|-lcurses|-lncurses|g ; \
		s|-R$$found_dir|-Wl,-rpath,$$found_dir|g' ${WRKSRC}/configure

.include <bsd.port.mk>
