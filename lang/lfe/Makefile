# $FreeBSD$

PORTNAME=	lfe
PORTVERSION=	1.3
DISTVERSIONPREFIX=	v
CATEGORIES=	lang

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	Lisp Flavored Erlang

LICENSE=	APACHE20

USES=		erlang gmake
USE_GITHUB=	yes
GH_ACCOUNT=	rvirding
ALL_TARGET=	compile
PORTDOCS=	README.md

do-build:
	cd ${BUILD_WRKSRC} && \
	    ${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} ${ALL_TARGET}

post-install:
	@${MKDIR} ${STAGEDIR}${ERL_APP_ROOT}/bin
.for FILE in lfe lfec lfedoc lfescript
	${INSTALL_SCRIPT} ${WRKSRC}/bin/${FILE} ${STAGEDIR}${ERL_APP_ROOT}/bin
	${LN} -sf ${ERL_APP_ROOT:S,^${PREFIX}/,,:S,^,../,}/bin/${FILE} \
	    ${STAGEDIR}${PREFIX}/bin
.endfor
.for FILE in lfe.1 lfescript.1
	${INSTALL_MAN} ${WRKSRC}/doc/man/${FILE} \
		${STAGEDIR}${MAN1PREFIX}/man/man1             
.endfor
.for FILE in lfe_lib.3 lfe_doc.3 lfe_clj.3 lfe_cl.3 lfe_gen.3 \
	lfe_io.3 lfe_macro.3 lfe_comp.3 lfe_bits.3
	${INSTALL_MAN} ${WRKSRC}/doc/man/${FILE} \
		${STAGEDIR}${MAN1PREFIX}/man/man3
.endfor
.for FILE in lfe_guide.7 lfe_types.7
	${INSTALL_MAN} ${WRKSRC}/doc/man/${FILE} \
		${STAGEDIR}${MAN1PREFIX}/man/man7
.endfor

.include <bsd.port.mk>
