# Created by: Andriy Gapon
# $FreeBSD$

PORTNAME=	coccinelle
DISTVERSION=	1.0.0-rc18
CATEGORIES=	devel
MASTER_SITES=	http://coccinelle.lip6.fr/distrib/
EXTRACT_SUFX=	.tgz

MAINTAINER=	avg@icyb.net.ua
COMMENT=	Coccinelle is a program matching and transformation engine

USES=		shebangfix gmake perl5
GNU_CONFIGURE=	yes
USE_PERL5=	build
USE_PYTHON=	2.6+
USE_OCAML=	3.0+
bash_CMD=	${SH}
SHEBANG_FILES=	setup/echo.sh
MAKE_ARGS+=	PYTHON_VERSION=${PYTHON_VER}

post-install:
	${STRIP_CMD} ${STAGEDIR}${DATADIR}/dllpcre_stubs.so \
		${STAGEDIR}${DATADIR}/dllpycaml_stubs.so \
		${STAGEDIR}${DATADIR}/spatch

.include <bsd.port.mk>
