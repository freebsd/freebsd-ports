# New ports collection makefile for:	mplayer-fonts
# Date created:		15 August 2001
# Whom:			Thomas E. Zander
#
# $FreeBSD$
#

PORTNAME=	mplayer-fonts
PORTVERSION=	0.50
CATEGORIES=	chinese multimedia
MASTER_SITES=	ftp://ftp.mplayerhq.hu/MPlayer/contrib/fonts/chinesefonts/ \
		ftp://freebsd.sinica.edu.tw/pub/statue/mplayer/
DISTFILES=	big5-kai.tar.bz big5-ming.tar.bz \
		gb2312-kai.tar.bz gb2312-ming.tar.bz

MAINTAINER=	statue@freebsd.sinica.edu.tw

RUN_DEPENDS=	${LOCALBASE}/share/mplayer/fonts:${PORTSDIR}/multimedia/mplayer-fonts

USE_BZIP2=	yes
NO_BUILD=	yes

FONTDIRS=	big5-kai/bkai00mp16 big5-kai/bkai00mp24 \
		big5-ming/bsmi00lp16 big5-ming/bsmi00lp24 \
		gb2312-kai/gkai00mp16 gb2312-kai/gkai00mp24 \
		gb2312-ming/gbsn00lp16 gb2312-ming/gbsn00lp24

do-install:
	@${MKDIR} ${PREFIX}/share/mplayer/fonts
	@${CHMOD} 0555 ${PREFIX}/share/mplayer/fonts
.for dir in ${FONTDIRS}
	@${MKDIR} ${PREFIX}/share/mplayer/fonts/${dir}
	@${CHMOD} 0555 ${PREFIX}/share/mplayer/fonts/${dir}
	@${INSTALL_DATA} ${WRKDIR}/${dir}/* \
		${PREFIX}/share/mplayer/fonts/${dir}
.endfor

.include <bsd.port.mk>
