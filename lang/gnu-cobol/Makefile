PORTNAME=	gnucobol
PORTVERSION=	3.2
PORTREVISION=	3
CATEGORIES=	lang
MASTER_SITES=	GNU/gnucobol

MAINTAINER=	wen@FreeBSD.org
COMMENT=	Free/libre COBOL compiler
WWW=		https://www.gnu.org/software/gnucobol/

LICENSE=	GPLv3 LGPL3
LICENSE_COMB=	multi

BUILD_DEPENDS=	help2man:misc/help2man
LIB_DEPENDS=	libgmp.so:math/gmp \
		libcjson.so:devel/libcjson

USES=		autoreconf bdb gmake gnome libtool ncurses tar:xz
USE_GNOME=	libxml2
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	MATH_LIBS=-lm

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

.include <bsd.port.mk>
