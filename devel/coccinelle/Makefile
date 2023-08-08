PORTNAME=	coccinelle
PORTVERSION=	1.1.1
CATEGORIES=	devel

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Program matching and transformation engine
WWW=		http://coccinelle.lip6.fr/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/license.txt

BUILD_DEPENDS=	menhir:devel/menhir \
		ocaml-parmap>=0:devel/ocaml-parmap \
		ocaml-pcre>=0:devel/ocaml-pcre
LIB_DEPENDS=	libpcre.so:devel/pcre

USE_OCAML=	3.0+
USE_OCAML_CAMLP4=yes

USES=		autoreconf gmake perl5 pkgconfig:build python shebangfix
BINARY_ALIAS=	make=${LOCALBASE}/bin/gmake
SHEBANG_FILES=	tools/pycocci
USE_PERL5=	build
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	PYTHON="${PYTHON_CMD}" PYVER="${PYTHON_VER}"
MAKE_ARGS=	PYTHON_VERSION="${PYTHON_VER}"

USE_GITHUB=	yes

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/spatch
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/spgen
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/coccinelle/*.so

.include <bsd.port.mk>
