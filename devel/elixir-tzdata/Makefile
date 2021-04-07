PORTNAME=	tzdata
PORTVERSION=	0.5.19
DISTVERSIONPREFIX=	v
CATEGORIES=	devel
PKGNAMEPREFIX=	elixir-

MAINTAINER=	erlang@FreeBSD.org
COMMENT=	Time zone data for Elixir

LICENSE=	MIT

USES=		elixir
USE_GITHUB=	yes
GH_ACCOUNT=	lau

MIX_BUILD_DEPS=	www/elixir-httpoison \
		www/erlang-hackney
MIX_REWRITE=	yes

OPTIONS_DEFINE=	DOCS

post-extract:
	@${RM} ${WRKSRC}/priv/release_ets/.gitkeep

.include <bsd.port.mk>
