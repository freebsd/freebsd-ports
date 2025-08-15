PORTNAME=	coccinelle
DISTVERSION=	1.3
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	https://coccinelle.gitlabpages.inria.fr/website/distrib/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	freebsd@dev.thsi.be
COMMENT=	Program matching and transformation engine
WWW=		https://coccinelle.gitlabpages.inria.fr/website/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/license.txt

BUILD_DEPENDS=	menhir:devel/menhir \
		ocaml-parmap>=0:devel/ocaml-parmap \
		ocaml-pcre>=0:devel/ocaml-pcre
LIB_DEPENDS=	libpcre.so:devel/pcre
TEST_DEPENDS=	bash:shells/bash

USES=		autoreconf gmake ocaml:camlp4 perl5 pkgconfig:build python shebangfix
USE_GITHUB=	nodefault
# until coccinelle/stdcompat releases with ocaml 5.2 support.
GH_TUPLE=	thierry-martinez:stdcompat:d53390d788027fe0a2282c4745eb3d1626341f99:stdcompat
USE_PERL5=	build
SHEBANG_FILES=	tools/pycocci scripts/cpptests.sh
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	PYTHON="${PYTHON_CMD}" PYVER="${PYTHON_VER}"
MAKE_ARGS=	PYTHON_VERSION="${PYTHON_VER}"
BINARY_ALIAS=	make=${GMAKE}
TEST_TARGET=	check check-cpp

OPTIONS_DEFINE=		EMACS VIM
OPTIONS_DEFAULT=	EMACS VIM
OPTIONS_SUB=	yes

EMACS_DESC=	Emacs plugin
VIM_DESC=	Vim plugin

EMACS_USES=	emacs
EMACS_NO_DEPENDS=	yes

post-extract:
	${RM} -r ${WRKSRC}/bundles/stdcompat/stdcompat-current
	(cd ${WRKSRC_stdcompat} && ${COPYTREE_SHARE} . \
		${WRKSRC}/bundles/stdcompat/stdcompat-current)

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/spatch
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/spgen
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/coccinelle/*.so

post-install-EMACS-on:
	${MKDIR} ${STAGEDIR}${PREFIX}/${EMACS_SITE_LISPDIR}/cocci
	cd ${WRKSRC}/editors/emacs && \
		${INSTALL_DATA} cocci-ediff.el cocci.el \
		${STAGEDIR}${PREFIX}/${EMACS_SITE_LISPDIR}/cocci

post-install-VIM-on:
.for d in ftdetect syntax
	${MKDIR} ${STAGEDIR}${PREFIX}/share/vim/vimfiles/${d}
	${INSTALL_DATA} ${WRKSRC}/editors/vim/${d}/cocci.vim \
		${STAGEDIR}${PREFIX}/share/vim/vimfiles/${d}
.endfor

.include <bsd.port.mk>
