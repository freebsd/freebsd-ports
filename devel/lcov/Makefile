# Created by: Romain Tartiere <romain@FreeBSD.org>
# $FreeBSD$

PORTNAME=	lcov
PORTVERSION=	1.12
CATEGORIES=	devel
MASTER_SITES=	SF/ltp/Coverage%20Analysis/LCOV-${PORTVERSION}

MAINTAINER=	romain@FreeBSD.org
COMMENT=	Linux Test Project GCOV extension

LICENSE=	GPLv1

RUN_DEPENDS=	bash:shells/bash

NO_BUILD=	yes
USES=		perl5 shebangfix
USE_PERL5=	run
SHEBANG_FILES=	bin/lcov bin/gendesc bin/genhtml bin/genpng bin/geninfo

PLIST_FILES=	bin/lcov bin/gendesc bin/genhtml bin/genpng bin/geninfo \
		man/man1/gendesc.1.gz man/man1/genhtml.1.gz \
		man/man1/geninfo.1.gz man/man1/genpng.1.gz \
		man/man1/lcov.1.gz man/man5/lcovrc.5.gz

do-install:
	cd ${WRKSRC}/bin && ${COPYTREE_BIN} "gendesc genhtml geninfo genpng lcov" ${STAGEDIR}${PREFIX}/bin
	cd ${WRKSRC}/man && ${INSTALL_MAN} *.1 ${STAGEDIR}${MANPREFIX}/man/man1
	cd ${WRKSRC}/man && ${INSTALL_MAN} *.5 ${STAGEDIR}${MANPREFIX}/man/man5

.include <bsd.port.mk>
