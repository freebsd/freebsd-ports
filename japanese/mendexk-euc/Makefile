# New ports collection makefile for:    mendexk-euc
# Date created:         1 Dec 1997
# Whom:                 Makoto WATANABE <watanabe@zlab.phys.nagoya-u.ac.jp>
#
# $FreeBSD$
#

PORTNAME=	mendexk
PORTVERSION=	2.5
PORTREVISION=	1
CATEGORIES=	japanese print
MASTER_SITES=	ftp://ftp.ascii.co.jp/pub/TeX/ascii-ptex/mendex/
PKGNAMESUFFIX=	-${KANJICODE}
DISTNAME=	${PORTNAME}${PORTVERSION}

MAINTAINER=	watanabe@zlab.phys.nagoya-u.ac.jp
COMMENT=	Index formatter for Japanese

KANJICODE?=	euc

EXTRACT_DEPENDS=	${NONEXISTENT}:${PORTSDIR}/japanese/ptex-base:configure
.if ${KANJICODE} == "sjis"
EXTRACT_DEPENDS+=	nkf:${PORTSDIR}/japanese/nkf
.endif

USE_GMAKE=	yes
DIST_SUBDIR=	teTeX
WRKSRC=	${WRKDIRPREFIX}${.CURDIR}/../ptex-base/work/tetex-src-${TETEX_VERSION}/texk/${DISTNAME}
ALL_TARGET=	mendex

TETEX_VERSION=	2.0.2
KANJI_FILES=	kana.h ktable.h

MANLANG=	ja
MAN1=		mendex.1

post-extract:
	@${RM} -rf ${WRKSRC}
	@${MV} ${WRKDIR}/${DISTNAME} ${WRKSRC}
.if ${KANJICODE} == "sjis"
	@( cd ${WRKSRC} ; \
	    for i in ${KANJI_FILES}; do \
	      ${MV} $$i $$i.orig ; \
	      nkf -s $$i.orig > $$i ; \
	    done )
.endif

pre-build:
	@(cd ${WRKSRC}/../kpathsea; ${MAKE})

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/mendex ${PREFIX}/bin
	@${MKDIR} ${PREFIX}/man/${MANLANG}/man1
	@${INSTALL_MAN} ${WRKSRC}/mendex.1 ${PREFIX}/man/${MANLANG}/man1
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif

pre-clean:
	@${RM} -rf ${WRKSRC}

.include <bsd.port.mk>
