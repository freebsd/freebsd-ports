PORTNAME=	lfe
PORTVERSION=	2.1.1
DISTVERSIONPREFIX=	v
CATEGORIES=	lang

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	Lisp Flavored Erlang
WWW=		https://lfe.io

LICENSE=	APACHE20

USES=		erlang gmake
USE_GITHUB=	yes
GH_ACCOUNT=	rvirding
ALL_TARGET=	compile
PORTDOCS=	README.md

OPTIONS_DEFINE=	DOCS

do-build:
	cd ${BUILD_WRKSRC} && \
	    ${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} ${ALL_TARGET}

pre-install:
	@${MKDIR} ${STAGEDIR}${ERL_APP_ROOT}/bin

post-install: post-install-bin \
    post-install-man1 post-install-man3 post-install-man7

post-install-bin:
.for F in lfe lfec lfedoc lfescript
	${INSTALL_SCRIPT} ${WRKSRC}/bin/$F ${STAGEDIR}${ERL_APP_ROOT}/bin
	${LN} -sf ${ERL_APP_ROOT:S,^${PREFIX}/,,:S,^,../,}/bin/$F \
	    ${STAGEDIR}${PREFIX}/bin
.endfor

post-install-man1:
	cd ${WRKSRC}/doc/man && \
	    ${INSTALL_MAN} lfe.1 lfescript.1 \
		${STAGEDIR}${PREFIX}/share/man/man1

post-install-man3:
	cd ${WRKSRC}/doc/man && \
	    ${INSTALL_MAN} lfe_bits.3 lfe_cl.3 lfe_clj.3 lfe_comp.3 \
		lfe_docs.3 lfe_gen.3 lfe_io.3 lfe_lib.3 lfe_macro.3 \
		${STAGEDIR}${PREFIX}/share/man/man3

post-install-man7:
	cd ${WRKSRC}/doc/man && \
	    ${INSTALL_MAN} lfe_guide.7 lfe_types.7 \
		${STAGEDIR}${PREFIX}/share/man/man7

.include <bsd.port.mk>
