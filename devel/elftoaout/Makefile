# Created by: kchowksey@hss.hns.com
# $FreeBSD$

PORTNAME=	elftoaout
PORTVERSION=	2.3
CATEGORIES=	devel
MASTER_SITES=	DEBIAN/pool/main/s/sparc-utils
DISTNAME=	sparc-utils_1.9.orig

MAINTAINER=	ports@FreeBSD.org
COMMENT=	ELF to a.out conversion tool by Jakub Jelinek and Pete Zaitcev

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

WRKSRC=		${WRKDIR}/sparc-utils-1.9.orig/elftoaout-2.3
MAKE_ARGS=	CC="${CC}" CFLAGS="${CFLAGS}"
PLIST_FILES=	bin/elftoaout \
		man/man1/elftoaout.1.gz

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/elftoaout ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/elftoaout.1 ${STAGEDIR}${PREFIX}/man/man1

.include <bsd.port.mk>
