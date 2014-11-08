# $FreeBSD$

PORTNAME=	git-extras
PORTVERSION=	2.1.0
CATEGORIES=	devel

MAINTAINER=	igor.ostapenko@gmail.com
COMMENT=	Sub-commands for repo summary, repl, changelog population, and more

LICENSE=	MIT

RUN_DEPENDS=	git:${PORTSDIR}/devel/git \
		bash:${PORTSDIR}/shells/bash

USE_GITHUB=	yes
GH_ACCOUNT=	tj
GH_TAGNAME=	v${PORTVERSION}
GH_COMMIT=	28f0ad8

USES=		gmake shebangfix
SHEBANG_FILES=	bin/git-squash

NO_BUILD=	yes

.include <bsd.port.mk>
