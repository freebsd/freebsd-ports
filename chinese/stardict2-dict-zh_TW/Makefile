# Ports collection makefile for:	stardict2-dict-zh_TW
# Date created:			16 Jan 2004
# Whom:				LI Dong <ld@FreeBSD.org.cn>
# $FreeBSD$
#

PORTNAME=	stardict2-dict-zh_TW
PORTVERSION=	2.4.2
PORTREVISION=	3
CATEGORIES=	chinese textproc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	stardict
DISTFILES=	stardict-cdict-big5-${PORTVERSION}.tar.bz2 \
		stardict-cedict-big5-${PORTVERSION}.tar.bz2 \
		stardict-langdao-ce-big5-${PORTVERSION}.tar.bz2 \
		stardict-langdao-ec-big5-${PORTVERSION}.tar.bz2 \
		stardict-oxford-big5-${PORTVERSION}.tar.bz2 \
		stardict-xdict-ce-big5-${PORTVERSION}.tar.bz2 \
		stardict-xdict-ec-big5-${PORTVERSION}.tar.bz2
DIST_SUBDIR=	stardict

MAINTAINER=	ld@FreeBSD.org.cn
COMMENT=	English-Chinese(T)/Chinese(T)-English dictionaries for StarDict

RUN_DEPENDS=	stardict:${PORTSDIR}/textproc/stardict2

NO_BUILD=	yes
USE_X_PREFIX=	yes
USE_BZIP2=	yes

do-install:
		${MKDIR} ${PREFIX}/share/gnome/stardict/dic/
		${INSTALL_DATA} ${WRKDIR}/stardict-cdict-big5-${PORTVERSION}/* ${PREFIX}/share/gnome/stardict/dic/
		${INSTALL_DATA} ${WRKDIR}/stardict-cedict-big5-${PORTVERSION}/* ${PREFIX}/share/gnome/stardict/dic/
		${INSTALL_DATA} ${WRKDIR}/stardict-langdao-ce-big5-${PORTVERSION}/* ${PREFIX}/share/gnome/stardict/dic/
		${INSTALL_DATA} ${WRKDIR}/stardict-langdao-ec-big5-${PORTVERSION}/* ${PREFIX}/share/gnome/stardict/dic/
		${INSTALL_DATA} ${WRKDIR}/stardict-oxford-big5-${PORTVERSION}/* ${PREFIX}/share/gnome/stardict/dic/
		${INSTALL_DATA} ${WRKDIR}/stardict-xdict-ce-big5-${PORTVERSION}/* ${PREFIX}/share/gnome/stardict/dic/
		${INSTALL_DATA} ${WRKDIR}/stardict-xdict-ec-big5-${PORTVERSION}/* ${PREFIX}/share/gnome/stardict/dic/

.include <bsd.port.mk>
