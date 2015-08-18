# $FreeBSD$

PORTNAME=	geo
PORTVERSION=	0.15.2
DISTVERSIONPREFIX=	v
CATEGORIES=	databases
PKGNAMEPREFIX=	elixir-

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	Collection of GIS functions for Elixir

LICENSE=	MIT

OPTIONS_SUB=	yes
USES=		elixir
USE_GITHUB=	yes
GH_ACCOUNT=	bryanjos

OPTIONS_DEFINE=	POSTGIS

.include <bsd.port.options.mk>

MIX_BUILD_DEPS=	databases/elixir-ecto \
		devel/elixir-poison

.if ${PORT_OPTIONS:MPOSTGIS}
MIX_BUILD_DEPS+=databases/elixir-postgrex
.endif

MIX_RUN_DEPS:=	${MIX_BUILD_DEPS}
MIX_REWRITE=	yes

post-patch:
.if ! ${PORT_OPTIONS:MPOSTGIS}
	# These files must be removed or the build will hang forever
	${RM} -r ${WRKSRC}/lib/geo/postgis.ex ${WRKSRC}/lib/geo/postgis
.endif

.include <bsd.port.mk>
