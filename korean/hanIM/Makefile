# New ports collection makefile for:    hanIM
# Date created:         17 Mar 1998
# Whom:                 CHOI Junho <cjh@kr.freebsd.org
#
# $FreeBSD$
#

PORTNAME=	hanIM
PORTVERSION=	1.2.1
CATEGORIES=     korean x11
MASTER_SITES=   ftp://ftp.mizi.com/pub/hanIM/

MAINTAINER=     cjh@FreeBSD.org

LIB_DEPENDS=	Xpm.4:${PORTSDIR}/graphics/xpm
RUN_DEPENDS=	${X11BASE}/lib/X11/fonts/local/gulim12.pcf.gz:${PORTSDIR}/korean/baekmukfonts-bdf

USE_IMAKE=	YES
WRKSRC=		${WRKDIR}/hanIM

post-install:
	${MKDIR} ${PREFIX}/share/doc/hanIM
	${INSTALL_DATA} ${WRKSRC}/README ${WRKSRC}/LICENSE \
			${PREFIX}/share/doc/hanIM/
	# patch XLC_LOCALE for ko_KR.EUC(harmless)
	if [ -f ${PREFIX}/lib/X11/locale/ko/XLC_LOCALE ]; then \
		${MV} -f ${PREFIX}/lib/X11/locale/ko/XLC_LOCALE \
			 ${PREFIX}/lib/X11/locale/ko/XLC_LOCALE.orig; \
	fi
	${INSTALL_DATA} ${FILESDIR}/XLC_LOCALE \
		${PREFIX}/lib/X11/locale/ko/
	${INSTALL_DATA} ${FILESDIR}/XLC_LOCALE \
		${PREFIX}/share/doc/hanIM/

.include <bsd.port.mk>
