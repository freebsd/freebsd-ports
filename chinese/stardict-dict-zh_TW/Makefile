# Ports collection makefile for:	stardict-dict-zh_TW
# Date created:			02 Feb 2010
# Whom:				Ju Pengfei <jupengfei@gmail.com>
# $FreeBSD$
#

PORTNAME=	stardict-dict-zh_TW
PORTVERSION=	2.4.2
CATEGORIES=	chinese textproc
MASTER_SITES=	SF/stardict/stardict-dictionaries-zh_TW/${PORTVERSION}
DISTFILES=	stardict-cdict-big5-${PORTVERSION}.tar.bz2 \
		stardict-cedict-big5-${PORTVERSION}.tar.bz2 \
		stardict-oxford-big5-${PORTVERSION}.tar.bz2 \
		stardict-xdict-ce-big5-${PORTVERSION}.tar.bz2 \
		stardict-xdict-ec-big5-${PORTVERSION}.tar.bz2
DIST_SUBDIR=	stardict

MAINTAINER=	jupengfei@gmail.com
COMMENT=	English-Chinese(T)/Chinese(T)-English dictionaries for StarDict

NO_BUILD=	yes
USE_BZIP2=	yes

do-install:
		${MKDIR} ${PREFIX}/share/stardict/dic/
		${INSTALL_DATA} ${WRKDIR}/stardict-cdict-big5-${PORTVERSION}/* ${PREFIX}/share/stardict/dic/
		${INSTALL_DATA} ${WRKDIR}/stardict-cedict-big5-${PORTVERSION}/* ${PREFIX}/share/stardict/dic/
		${INSTALL_DATA} ${WRKDIR}/stardict-oxford-big5-${PORTVERSION}/* ${PREFIX}/share/stardict/dic/
		${INSTALL_DATA} ${WRKDIR}/stardict-xdict-ce-big5-${PORTVERSION}/* ${PREFIX}/share/stardict/dic/
		${INSTALL_DATA} ${WRKDIR}/stardict-xdict-ec-big5-${PORTVERSION}/* ${PREFIX}/share/stardict/dic/

post-install:
		@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
