# Created by: Romain Tartiere <romain@FreeBSD.org>
# $FreeBSD$

PORTNAME=	lcov
PORTVERSION=	1.14
CATEGORIES=	devel
MASTER_SITES=	SF/ltp/Coverage%20Analysis/LCOV-${PORTVERSION}

MAINTAINER=	romain@FreeBSD.org
COMMENT=	Linux Test Project GCOV extension

LICENSE=	GPLv2

RUN_DEPENDS=	bash:shells/bash

NO_BUILD=	yes
USES=		gmake perl5 shebangfix
USE_PERL5=	run
SHEBANG_FILES=	bin/lcov bin/gendesc bin/genhtml bin/genpng bin/geninfo \
		bin/*.pl bin/*.sh

post-patch:
	${REINPLACE_CMD} -e 's:$$(PREFIX)/share/man:$$(PREFIX)/man:' ${WRKSRC}/Makefile

.include <bsd.port.mk>
