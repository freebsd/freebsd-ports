PORTNAME=	liba52
DISTVERSION=	0.8.0
PORTREVISION=	2
CATEGORIES=	audio
MASTER_SITES=	https://distfiles.adelielinux.org/source/a52dec/
DISTNAME=	a52dec-${DISTVERSION}

MAINTAINER=	multimedia@FreeBSD.org
COMMENT=	Free library for decoding ATSC A/52 streams, aka AC-3
WWW=		https://git.adelielinux.org/community/a52dec/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		autoreconf libtool
USE_CSTD=	gnu89
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes

INSTALL_TARGET=	install-strip
TEST_TARGET=	check

CONFIGURE_ARGS=	--disable-oss --enable-shared

OPTIONS_DEFINE=	DOCS

post-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/liba52.txt ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/liba52/a52_internal.h ${STAGEDIR}${PREFIX}/include/a52dec

.include <bsd.port.mk>
