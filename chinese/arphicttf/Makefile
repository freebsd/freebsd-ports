# New ports collection makefile for:	Arphic Chinese TrueType fonts
# Date created:		13 Oct 1999
# Whom:			Keith Jang <keith@freebsd.sinica.edu.tw>
#
# $FreeBSD$
#

PORTNAME=	arphicttf
PORTVERSION=	2.11
CATEGORIES=	chinese x11-fonts
MASTER_SITES=	ftp://freebsd.sinica.edu.tw/pub/keith/
DISTNAME=	${PKGNAME}

MAINTAINER=	keith@freebsd.sinica.edu.tw

LIB_DEPENDS=	font.1:${PORTSDIR}/x11-servers/XttXF86srv-common

USE_X_PREFIX=	yes

NO_BUILD=	yes
SHAREMODE=	644
WRKSRC=		${WRKDIR}/arphic
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
	@${INSTALL_DATA} ${WRKSRC}/font/bkai00mp.ttf ${FONTDIR}
	@${INSTALL_DATA} ${WRKSRC}/font/bsmi00lp.ttf ${FONTDIR}
	@${INSTALL_DATA} ${WRKSRC}/font/gbsn00lp.ttf ${FONTDIR}
	@${INSTALL_DATA} ${WRKSRC}/font/gkai00mp.ttf ${FONTDIR}
	@${RM} -fr ${FONTDIR}/arphic
	@${MKDIR} ${FONTDIR}/arphic
	@${CP} -fr ${WRKSRC}/license ${FONTDIR}/arphic
	@${CP} -f ${WRKSRC}/logo.gif ${WRKSRC}/release.txt ${FONTDIR}/arphic
	@${SETENV} PKG_PREFIX=${PREFIX} ${SH} ${PKGDIR}/INSTALL ${PKGNAME} POST-INSTALL

.include <bsd.port.post.mk>
