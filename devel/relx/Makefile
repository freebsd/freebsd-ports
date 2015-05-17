# $FreeBSD$

PORTNAME=	relx
PORTVERSION=	2.0.0
DISTVERSIONPREFIX=v
CATEGORIES=	devel
MASTER_SITES+=	http://olgeni.olgeni.com/~olgeni/distfiles/:deps \
		LOCAL/olgeni:deps
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} relx-deps-1.tar.gz:deps

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	Sane, simple release creation for Erlang

LICENSE=	APACHE20

BUILD_DEPENDS=	${LOCALBASE}/bin/erl:${PORTSDIR}/lang/erlang \
		${LOCALBASE}/bin/git:${PORTSDIR}/devel/git
RUN_DEPENDS=	${LOCALBASE}/bin/erl:${PORTSDIR}/lang/erlang

USE_GITHUB=	yes
GH_ACCOUNT=	erlware

PLIST_FILES=	bin/${PORTNAME}

post-extract:
	@${CP} -R ${WRKDIR}/_build ${WRKSRC}/

post-patch:
	@${REINPLACE_CMD} -e "s/%%PORTVERSION%%/${PORTVERSION}/" ${WRKSRC}/src/relx.app.src
	@${RM} ${WRKSRC}/src/*.bak ${WRKSRC}/src/*.orig

do-build:
	@cd ${WRKSRC} && ./rebar3 escriptize

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/_build/default/bin/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/

.include <bsd.port.mk>
