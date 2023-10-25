PORTNAME=	libqsbr
PORTVERSION=	g2020082801
CATEGORIES=	devel

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	QSBR and EBR library
WWW=		https://github.com/rmind/libqsbr

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/../LICENSE

# the fix uses __LONG_WIDTH__ which is only available from FreeBSD 13
BROKEN_FreeBSD_12_i386=		static_assert(sizeof(qsbr_epoch_t) == 8, "expected 64-bit counter")
BROKEN_FreeBSD_12_armv6=	static_assert(sizeof(qsbr_epoch_t) == 8, "expected 64-bit counter")
BROKEN_FreeBSD_12_armv7=	static_assert(sizeof(qsbr_epoch_t) == 8, "expected 64-bit counter")
BROKEN_FreeBSD_12_powerpc=	static_assert(sizeof(qsbr_epoch_t) == 8, "expected 64-bit counter")
BROKEN_FreeBSD_12_mips=		static_assert(sizeof(qsbr_epoch_t) == 8, "expected 64-bit counter")

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

.include <bsd.port.mk>
