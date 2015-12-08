# $FreeBSD$

PORTNAME=	lfe
PORTVERSION=	0.9.2
CATEGORIES=	lang

MAINTAINER=	rpaulo@FreeBSD.org
COMMENT=	Lisp Flavored Erlang

LICENSE=	APACHE20

USE_GITHUB=	yes
GH_ACCOUNT=	rvirding

USES=		erlang:rebar

post-install:
	@${MKDIR} ${STAGEDIR}${ERL_APP_ROOT}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/bin/lfe ${STAGEDIR}${ERL_APP_ROOT}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/bin/lfec ${STAGEDIR}${ERL_APP_ROOT}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/bin/lfescript ${STAGEDIR}${ERL_APP_ROOT}/bin
	${LN} -sf ${ERL_APP_ROOT}/bin/lfe ${STAGEDIR}${PREFIX}/bin
	${LN} -sf ${ERL_APP_ROOT}/bin/lfec ${STAGEDIR}${PREFIX}/bin
	${LN} -sf ${ERL_APP_ROOT}/bin/lfescript ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
