PORTNAME=	coccinelle
DISTVERSION=	1.3.1
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	https://coccinelle.gitlabpages.inria.fr/website/distrib/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	freebsd@dev.thsi.be
COMMENT=	Program matching and transformation engine
WWW=		https://coccinelle.gitlabpages.inria.fr/website/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/license.txt

BUILD_DEPENDS=	${OCAMLFIND_DEPEND} \
		menhir:devel/menhir \
		ocaml-parmap>=0:devel/ocaml-parmap \
		ocaml-pcre>=0:devel/ocaml-pcre
LIB_DEPENDS=	libpcre.so:devel/pcre
TEST_DEPENDS=	bash:shells/bash

USES=		autoreconf gmake ocaml:build,camlp4 perl5 pkgconfig:build python shebangfix
USE_PERL5=	build
SHEBANG_FILES=	tools/pycocci scripts/cpptests.sh
GNU_CONFIGURE=	yes
# --with-python bakes the interpreter path into cocciconfig.ml so spatch can
# derive the Python version and load libpython; configure ignores env PYTHON,
# and its "python" default does not exist on FreeBSD.
CONFIGURE_ARGS=	--with-python=${PYTHON_CMD}
CONFIGURE_ENV=	PYVER="${PYTHON_VER}"
MAKE_ARGS=	PYTHON_VERSION="${PYTHON_VER}"
BINARY_ALIAS=	make=${GMAKE}
TEST_TARGET=	check check-cpp

# Run the upstream suite, then exercise @script:python@ scripting: the
# upstream suite doesn't, and it regressed silently when the embedded
# interpreter failed to load libpython.  The optimized build only produces
# spatch.opt, but check-cpp's cpptests.sh and the smoke test both invoke a
# plain ./spatch, so alias it first.
do-test:
	@${LN} -sf spatch.opt ${TEST_WRKSRC}/spatch
	@cd ${TEST_WRKSRC} && ${SETENVI} ${WRK_ENV} ${TEST_ENV} \
		${MAKE_CMD} ${MAKE_FLAGS} ${MAKEFILE} \
		${TEST_ARGS:N${DESTDIRNAME}=*} ${TEST_TARGET}
	@cd ${WRKSRC} && \
		out=$$(${SETENVI} ${WRK_ENV} ${TEST_ENV} ./spatch --very-quiet \
			--sp-file ${FILESDIR}/regress-python.cocci \
			${FILESDIR}/regress-python.c) && \
		case "$$out" in \
		*"hit: ${FILESDIR}/regress-python.c:1"*) \
			${ECHO_MSG} "===>  @script:python@ smoke test PASSED" ;; \
		*) ${ECHO_MSG} "===>  @script:python@ smoke test FAILED: $$out"; \
			exit 1 ;; \
		esac

OPTIONS_DEFINE=		EMACS VIM
OPTIONS_DEFAULT=	EMACS VIM
OPTIONS_SUB=	yes

EMACS_DESC=	Emacs plugin
VIM_DESC=	Vim plugin

EMACS_USES=	emacs

post-install:
	${RM} -r ${STAGEDIR}${PREFIX}/share/metainfo
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
