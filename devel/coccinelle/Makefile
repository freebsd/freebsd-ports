# Created by: Andriy Gapon
# $FreeBSD$

PORTNAME=	coccinelle
DISTVERSION=	1.0.0-rc18
CATEGORIES=	devel
MASTER_SITES=	http://coccinelle.lip6.fr/distrib/
EXTRACT_SUFX=	.tgz

MAINTAINER=	avg@icyb.net.ua
COMMENT=	Coccinelle is a program matching and transformation engine

LIB_DEPENDS=	libpcre.so:${PORTSDIR}/devel/pcre

USES=		shebangfix gmake perl5 pkgconfig:build
GNU_CONFIGURE=	yes
USE_PERL5=	build
USE_PYTHON=	yes
USE_OCAML=	3.0+
bash_CMD=	${SH}
SHEBANG_FILES=	setup/echo.sh
MAKE_ARGS+=	PYTHON_VERSION=${PYTHON_VER}
CONFIGURE_ENV+=	PYVER=${PYTHON_VER} PYTHON=${PYTHON_CMD}

post-install:
	${STRIP_CMD} ${STAGEDIR}${DATADIR}/dllpcre_stubs.so \
		${STAGEDIR}${DATADIR}/dllpycaml_stubs.so \
		${STAGEDIR}${DATADIR}/spatch

.include <bsd.port.mk>
