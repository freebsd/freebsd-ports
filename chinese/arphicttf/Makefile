# New ports collection makefile for:	Arphic Chinese TrueType fonts
# Version required:	1.0
# Date created:		13 Oct 1999
# Whom:			Keith Jang <keith@freebsd.sinica.edu.tw>
#
# $FreeBSD$
#

DISTNAME=	zh-arphicttf-1.0
CATEGORIES=	chinese x11-fonts
MASTER_SITES=	ftp://freebsd.sinica.edu.tw/pub/keith/

MAINTAINER=	keith@freebsd.sinica.edu.tw

LIB_DEPENDS=	font.1:${PORTSDIR}/x11-servers/XttXF86srv-common

USE_X_PREFIX=	yes

NO_BUILD=	yes
SHAREMODE=	644
FONTDIR=	${PREFIX}/lib/X11/fonts/TrueType

.include <bsd.port.pre.mk>

do-install:
.if !exists(${FONTDIR})
	@${ECHO} "========================================================="
	@${ECHO} "Please add ${FONTDIR} to your font path"
	@${ECHO} "in /etc/XF86Config."
	@${ECHO} "========================================================="
	@${MKDIR} ${FONTDIR}
.endif
	@${INSTALL_DATA} ${WRKDIR}/bkai00mp.ttf ${FONTDIR}
	@${INSTALL_DATA} ${WRKDIR}/bsmi00lp.ttf ${FONTDIR}
	@${INSTALL_DATA} ${WRKDIR}/gbsn00lp.ttf ${FONTDIR}
	@${INSTALL_DATA} ${WRKDIR}/gkai00mp.ttf ${FONTDIR}
	@${INSTALL_DATA} ${WRKDIR}/ARPHICPL_Big5.TXT ${FONTDIR}
	@${INSTALL_DATA} ${WRKDIR}/ARPHICPL_Eng.TXT ${FONTDIR}
	@${INSTALL_DATA} ${WRKDIR}/ARPHICPL_GB.TXT ${FONTDIR}
	@${SETENV} PKG_PREFIX=${PREFIX} ${SH} ${PKGDIR}/INSTALL ${PKGNAME} POST-INSTALL

.include <bsd.port.post.mk>
