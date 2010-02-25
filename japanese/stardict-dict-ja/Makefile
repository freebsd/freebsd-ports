# Ports collection makefile for:	stardict2-dict-ja
# Date created:			16 Jan 2004
# Whom:				LI Dong <ld@FreeBSD.org.cn>
# $FreeBSD$
#

PORTNAME=	stardict-dict-ja
PORTVERSION=	2.4.2
CATEGORIES=	japanese textproc
MASTER_SITES=	SF/stardict/stardict-dictionaries-ja/${PORTVERSION}
DISTFILES=	stardict-jmdict-en-ja-${PORTVERSION}.tar.bz2 \
		stardict-jmdict-ja-en-${PORTVERSION}.tar.bz2
DIST_SUBDIR=	stardict

MAINTAINER=	jupengfei@gmail.com
COMMENT=	English-Japanese/Japanese-English dictionaries for StarDict

NO_BUILD=	yes
USE_BZIP2=	yes

do-install:
		${MKDIR} ${PREFIX}/share/stardict/dic/
		${INSTALL_DATA} ${WRKDIR}/stardict-jmdict-en-ja-${PORTVERSION}/* ${PREFIX}/share/stardict/dic/
		${INSTALL_DATA} ${WRKDIR}/stardict-jmdict-ja-en-${PORTVERSION}/* ${PREFIX}/share/stardict/dic/

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
