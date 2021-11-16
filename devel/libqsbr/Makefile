PORTNAME=	libqsbr
PORTVERSION=	g2020082801
CATEGORIES=	devel

MAINTAINER=	swills@FreeBSD.org
COMMENT=	QSBR and EBR library

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/../LICENSE

BROKEN_i386=	static_assert(sizeof(qsbr_epoch_t) == 8, "expected 64-bit counter")
BROKEN_powerpc=	static_assert(sizeof(qsbr_epoch_t) == 8, "expected 64-bit counter")

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

.include <bsd.port.mk>
