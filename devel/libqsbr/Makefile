PORTNAME=	libqsbr
PORTVERSION=	g2020082801
CATEGORIES=	devel

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	QSBR and EBR library
WWW=		https://github.com/rmind/libqsbr

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/../LICENSE

BROKEN_FreeBSD_armv7=	static assertion failed due to requirement 'sizeof(unsigned long) == 8': expected 64-bit counter

USES=		compiler:c11 gmake libtool:build
USE_GITHUB=	yes
GH_ACCOUNT=	rmind
GH_TAGNAME=	e73407c
WRKSRC_SUBDIR=	src
USE_LDCONFIG=	yes
MAKE_ENV=	DESTDIR=${STAGEDIR}${PREFIX} \
		INCDIR=${LOCALBASE}/include \
		LIBDIR=${LOCALBASE}/lib \
		MANDIR=${LOCALBASE}/man
TEST_TARGET=	tests

.include <bsd.port.options.mk>

.if ${OPSYS} == FreeBSD && ${OSVERSION} >= 1500006
CFLAGS_i386=	-Wno-error=sync-alignment
.endif

.include <bsd.port.mk>
