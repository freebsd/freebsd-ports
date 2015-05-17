# $FreeBSD$

PORTNAME=	rebar3
PORTVERSION=	20150517
CATEGORIES=	devel
MASTER_SITES+=	http://olgeni.olgeni.com/~olgeni/distfiles/:deps \
		LOCAL/olgeni:deps
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} rebar3-deps-1.tar.gz:deps

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	Build tool for Erlang

LICENSE=	APACHE20

BUILD_DEPENDS=	${LOCALBASE}/bin/erl:${PORTSDIR}/lang/erlang \
		${LOCALBASE}/bin/git:${PORTSDIR}/devel/git
RUN_DEPENDS=	${LOCALBASE}/bin/erl:${PORTSDIR}/lang/erlang

USE_GITHUB=	yes
GH_ACCOUNT=	rebar
GH_TAGNAME=	9ad3025

PLIST_FILES=	bin/${PORTNAME}

post-extract:
	@${CP} -R ${WRKDIR}/_build ${WRKSRC}/

do-build:
	@cd ${WRKSRC} && ./bootstrap

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/

.include <bsd.port.mk>
