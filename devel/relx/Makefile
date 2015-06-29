# $FreeBSD$

PORTNAME=	relx
PORTVERSION=	3.0.0
DISTVERSIONPREFIX=v
CATEGORIES=	devel
MASTER_SITES+=	http://olgeni.olgeni.com/~olgeni/distfiles/:deps \
		LOCAL/olgeni:deps
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		relx-deps-2.tar.gz:deps \
		relx-cache-2.tar.gz:deps

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	Sane, simple release creation for Erlang

LICENSE=	APACHE20

BUILD_DEPENDS=	${LOCALBASE}/bin/erl:${PORTSDIR}/lang/erlang
RUN_DEPENDS=	${LOCALBASE}/bin/erl:${PORTSDIR}/lang/erlang

USE_GITHUB=	yes
GH_ACCOUNT=	erlware

PLIST_FILES=	bin/${PORTNAME}

# rebar3 insists on downloading dependencies, and some kind of package
# index into the user's HOME. We need to trick it into behaving by
# providing both before building.

post-extract:
	@${CP} -R ${WRKDIR}/_build ${WRKSRC}/
	@${LN} -s cache ${WRKDIR}/.cache

post-patch:
	@${REINPLACE_CMD} -e "s/%%PORTVERSION%%/${PORTVERSION}/" ${WRKSRC}/src/relx.app.src
	@${RM} ${WRKSRC}/src/*.bak ${WRKSRC}/src/*.orig

do-build:
	@cd ${WRKSRC} && HOME=${WRKDIR} ./rebar3 escriptize

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/_build/default/bin/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/

.include <bsd.port.mk>
