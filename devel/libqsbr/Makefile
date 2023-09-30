PORTNAME=	libqsbr
PORTVERSION=	g2020082801
CATEGORIES=	devel

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	QSBR and EBR library
WWW=		https://github.com/rmind/libqsbr

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/../LICENSE

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
