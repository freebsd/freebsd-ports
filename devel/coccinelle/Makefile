PORTNAME=	coccinelle
PORTVERSION=	1.2
CATEGORIES=	devel

MAINTAINER=	freebsd@dev.thsi.be
COMMENT=	Program matching and transformation engine
WWW=		http://coccinelle.lip6.fr/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/license.txt

BUILD_DEPENDS=	menhir:devel/menhir \
		ocaml-parmap>=0:devel/ocaml-parmap \
		ocaml-pcre>=0:devel/ocaml-pcre
LIB_DEPENDS=	libpcre.so:devel/pcre

USES=		autoreconf gmake perl5 pkgconfig:build python shebangfix
USE_GITHUB=	yes
# until coccinelle/stdcompat releases with ocaml 5.2 support.
GH_TUPLE=	thierry-martinez:stdcompat:d53390d788027fe0a2282c4745eb3d1626341f99:stdcompat
USE_OCAML=	3.0+
USE_OCAML_CAMLP4=	yes
USE_PERL5=	build
SHEBANG_FILES=	tools/pycocci
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	PYTHON="${PYTHON_CMD}" PYVER="${PYTHON_VER}"
MAKE_ARGS=	PYTHON_VERSION="${PYTHON_VER}"
BINARY_ALIAS=	make=${LOCALBASE}/bin/gmake

post-extract:
	${RM} -r ${WRKSRC}/bundles/stdcompat/stdcompat-current
	(cd ${WRKSRC_stdcompat} && ${COPYTREE_SHARE} . \
		${WRKSRC}/bundles/stdcompat/stdcompat-current)

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/spatch
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/spgen
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/coccinelle/*.so

.include <bsd.port.mk>
