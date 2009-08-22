# Ports collection makefile for:	stardict2-dict-zh_CN
# Date created:			16 Jan 2004
# Whom:				LI Dong <ld@FreeBSD.org.cn>
# $FreeBSD$
#

PORTNAME=	stardict2-dict-zh_CN
PORTVERSION=	2.4.2
PORTREVISION=	8
CATEGORIES=	chinese textproc
MASTER_SITES=	SF/stardict/stardict-dictionaries-zh_CN/${PORTVERSION}
DISTFILES=	stardict-cdict-gb-${PORTVERSION}.tar.bz2 \
		stardict-cedict-gb-${PORTVERSION}.tar.bz2 \
		stardict-oxford-gb-${PORTVERSION}.tar.bz2 \
		stardict-stardict1.3-${PORTVERSION}.tar.bz2 \
		stardict-xdict-ce-gb-${PORTVERSION}.tar.bz2 \
		stardict-xdict-ec-gb-${PORTVERSION}.tar.bz2
DIST_SUBDIR=	stardict

MAINTAINER=	ports@FreeBSD.org
COMMENT=	English-Chinese(S)/Chinese(S)-English dictionaries for StarDict

RUN_DEPENDS=	stardict:${PORTSDIR}/textproc/stardict2

NO_BUILD=	yes
USE_BZIP2=	yes

do-install:
		${MKDIR} ${PREFIX}/share/stardict/dic/
		${INSTALL_DATA} ${WRKDIR}/stardict-cdict-gb-${PORTVERSION}/* ${PREFIX}/share/stardict/dic/
		${INSTALL_DATA} ${WRKDIR}/stardict-cedict-gb-${PORTVERSION}/* ${PREFIX}/share/stardict/dic/
		${INSTALL_DATA} ${WRKDIR}/stardict-oxford-gb-${PORTVERSION}/* ${PREFIX}/share/stardict/dic/
		${INSTALL_DATA} ${WRKDIR}/stardict-stardict1.3-${PORTVERSION}/* ${PREFIX}/share/stardict/dic/
		${INSTALL_DATA} ${WRKDIR}/stardict-xdict-ce-gb-${PORTVERSION}/* ${PREFIX}/share/stardict/dic/
		${INSTALL_DATA} ${WRKDIR}/stardict-xdict-ec-gb-${PORTVERSION}/* ${PREFIX}/share/stardict/dic/

.include <bsd.port.mk>
