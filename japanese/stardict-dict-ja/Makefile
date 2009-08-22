# Ports collection makefile for:	stardict2-dict-ja
# Date created:			16 Jan 2004
# Whom:				LI Dong <ld@FreeBSD.org.cn>
# $FreeBSD$
#

PORTNAME=	stardict2-dict-ja
PORTVERSION=	2.4.2
PORTREVISION=	7
CATEGORIES=	japanese textproc
MASTER_SITES=	SF/stardict/stardict-dictionaries-ja/${PORTVERSION}
DISTFILES=	stardict-jmdict-en-ja-${PORTVERSION}.tar.bz2 \
		stardict-jmdict-ja-en-${PORTVERSION}.tar.bz2
DIST_SUBDIR=	stardict

MAINTAINER=	ports@FreeBSD.org
COMMENT=	English-Japanese/Japanese-English dictionaries for StarDict

RUN_DEPENDS=	stardict:${PORTSDIR}/textproc/stardict2

NO_BUILD=	yes
USE_BZIP2=	yes

do-install:
		${MKDIR} ${PREFIX}/share/stardict/dic/
		${INSTALL_DATA} ${WRKDIR}/stardict-jmdict-en-ja-${PORTVERSION}/* ${PREFIX}/share/stardict/dic/
		${INSTALL_DATA} ${WRKDIR}/stardict-jmdict-ja-en-${PORTVERSION}/* ${PREFIX}/share/stardict/dic/

.include <bsd.port.mk>
