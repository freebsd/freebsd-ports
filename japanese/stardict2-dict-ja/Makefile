# Ports collection makefile for:	stardict2-dict-ja
# Date created:			16 Jan 2004
# Whom:				LI Dong <ld@FreeBSD.org.cn>
# $FreeBSD$
#

PORTNAME=	stardict2-dict-ja
PORTVERSION=	2.4.2
PORTREVISION=	3
CATEGORIES=	japanese textproc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	stardict
DISTFILES=	stardict-jmdict-en-ja-${PORTVERSION}.tar.bz2 \
		stardict-jmdict-ja-en-${PORTVERSION}.tar.bz2
DIST_SUBDIR=	stardict

MAINTAINER=	ld@FreeBSD.org.cn
COMMENT=	English-Japanese/Japanese-English dictionaries for StarDict

RUN_DEPENDS=	stardict:${PORTSDIR}/textproc/stardict2

NO_BUILD=	yes
USE_X_PREFIX=	yes
USE_BZIP2=	yes

do-install:
		${MKDIR} ${PREFIX}/share/gnome/stardict/dic/
		${INSTALL_DATA} ${WRKDIR}/stardict-jmdict-en-ja-${PORTVERSION}/* ${PREFIX}/share/gnome/stardict/dic/
		${INSTALL_DATA} ${WRKDIR}/stardict-jmdict-ja-en-${PORTVERSION}/* ${PREFIX}/share/gnome/stardict/dic/

.include <bsd.port.mk>
