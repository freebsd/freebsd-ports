# New ports collection makefile for:	zh-wangttf
# Date created:		19 Nov 2000
# Whom:			Jing-Tang Keith Jang <keith@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	wangttf
PORTVERSION=	1.0
CATEGORIES=	chinese x11-fonts
MASTER_SITES=	ftp://freebsd.sinica.edu.tw/pub/keith/wangttf/
DISTFILES=	wcl-01.ttf.bz2 wcl-02.ttf.bz2 wcl-03.ttf.bz2 wcl-04.ttf.bz2 \
		wcl-05.ttf.bz2 wcl-06.ttf.bz2 wcl-07.ttf.bz2 wcl-08.ttf.bz2 \
		wcl-09.ttf.bz2 wcl-10.ttf.bz2
EXTRACT_ONLY=

MAINTAINER=	keith@FreeBSD.org

RUN_DEPENDS=	ttfm.sh:${PORTSDIR}/chinese/ttfm

DIST_SUBDIR=	zh-wangttf
USE_BZIP2=	yes
NO_BUILD=	yes
SHAREMODE=	644
FONTDIR=	${PREFIX}/share/fonts/ttf

.include <bsd.port.pre.mk>

do-install:
	@${MKDIR} ${FONTDIR}
.for i in ${DISTFILES}
	@${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/${i} ${FONTDIR}
	@${EXTRACT_CMD} -dv ${FONTDIR}/${i}
.endfor
	@${INSTALL_DATA} ${FILESDIR}/wangttf.txt ${FONTDIR}

.include <bsd.port.post.mk>
