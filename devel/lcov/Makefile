PORTNAME=	lcov
PORTVERSION=	1.15
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	SF/ltp/Coverage%20Analysis/LCOV-${PORTVERSION}

MAINTAINER=	romain@FreeBSD.org
COMMENT=	Linux Test Project GCOV extension
WWW=		https://ltp.sourceforge.net/coverage/lcov.php

LICENSE=	GPLv2

RUN_DEPENDS=	bash:shells/bash

NO_ARCH=	yes
NO_BUILD=	yes
USES=		gmake perl5 shebangfix
USE_PERL5=	run
SHEBANG_FILES=	bin/lcov bin/gendesc bin/genhtml bin/genpng bin/geninfo \
		bin/*.pl bin/*.sh

.include <bsd.port.mk>
