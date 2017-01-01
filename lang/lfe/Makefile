# $FreeBSD$

PORTNAME=	lfe
PORTVERSION=	1.2.1
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
	${INSTALL_SCRIPT} ${WRKSRC}/bin/lfe ${STAGEDIR}${ERL_APP_ROOT}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/bin/lfec ${STAGEDIR}${ERL_APP_ROOT}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/bin/lfescript ${STAGEDIR}${ERL_APP_ROOT}/bin
	${LN} -sf ${ERL_APP_ROOT:S,^${PREFIX}/,,:S,^,../,}/bin/lfe \
	    ${STAGEDIR}${PREFIX}/bin
	${LN} -sf ${ERL_APP_ROOT:S,^${PREFIX}/,,:S,^,../,}/bin/lfec \
	    ${STAGEDIR}${PREFIX}/bin
	${LN} -sf ${ERL_APP_ROOT:S,^${PREFIX}/,,:S,^,../,}/bin/lfescript \
	    ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
