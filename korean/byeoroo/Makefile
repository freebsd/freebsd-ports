# New ports collection makefile for:	byeoroo
# Date created:		04 Jun 1999
# Whom:			CHOI Junho <cjh@kr.freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	byeoroo
PORTVERSION=	0.0.19990605.3
CATEGORIES=	korean x11
MASTER_SITES=	http://adam.kaist.ac.kr/~cwryu/archive/byeoroo/

MAINTAINER=	cjh@kr.freebsd.org

RUN_DEPENDS=	${PREFIX}/lib/X11/fonts/local/johabm16.pcf.gz:${PORTSDIR}/korean/johabfonts \
		${X11BASE}/lib/X11/fonts/local/hgm12.pcf.gz:${PORTSDIR}/korean/hanyangfonts

USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes

post-install:
	# patch XLC_LOCALE for ko_KR.EUC(harmless)
	if [ -f ${PREFIX}/lib/X11/locale/ko/XLC_LOCALE ]; then \
	        ${MV} -f ${PREFIX}/lib/X11/locale/ko/XLC_LOCALE \
	                ${PREFIX}/lib/X11/locale/ko/XLC_LOCALE.orig; \
	fi
	${INSTALL_DATA} ${FILESDIR}/XLC_LOCALE \
	        ${PREFIX}/lib/X11/locale/ko/
	${INSTALL_DATA} ${FILESDIR}/XLC_LOCALE \
	        ${PREFIX}/share/byeoroo/

.include <bsd.port.mk>
