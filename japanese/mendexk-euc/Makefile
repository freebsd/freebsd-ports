# New ports collection makefile for:    mendexk-euc
# Date created:         1 Dec 1997
# Whom:                 Makoto WATANABE <watanabe@zlab.phys.nagoya-u.ac.jp>
#
# $FreeBSD$
#

PORTNAME=	mendexk
PORTVERSION=	2.5
CATEGORIES=	japanese print
MASTER_SITES=	ftp://ftp.ascii.co.jp/pub/TeX/ascii-ptex/mendex/
PKGNAMESUFFIX=	-euc
DISTNAME=	${PORTNAME}${PORTVERSION}

MAINTAINER=	watanabe@zlab.phys.nagoya-u.ac.jp
COMMENT=	Index formatter for Japanese (EUC)

EXTRACT_DEPENDS=	${NONEXISTENT}:${PORTSDIR}/japanese/ptex-base:configure

USE_GMAKE=	yes
DIST_SUBDIR=	teTeX
WRKSRC=	${WRKDIRPREFIX}${.CURDIR}/../ptex-base/work/tetex-src-${TETEX_VERSION}/texk/${DISTNAME}
ALL_TARGET=	mendex

TETEX_VERSION=	2.0.2

MANLANG=	ja
MAN1=		mendex.1

post-extract:
	@${RM} -rf ${WRKSRC}
	@${MV} ${WRKDIR}/${DISTNAME} ${WRKSRC}

pre-build:
	@(cd ${WRKSRC}/../kpathsea; ${MAKE})

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/mendex ${PREFIX}/bin
	@${MKDIR} ${PREFIX}/man/${MANLANG}/man1
	@${INSTALL_MAN} ${WRKSRC}/mendex.1 ${PREFIX}/man/${MANLANG}/man1
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/mendex
	@${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/mendex
.endif

pre-clean:
	@${RM} -rf ${WRKSRC}

.include <bsd.port.mk>
