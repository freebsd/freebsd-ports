# New ports collection makefile for:	Chinese Big5 TrueType fonts
# Date created:		9 July 1999
# Whom:			Keith Jang <keith@freebsd.sinica.edu.tw>
#
# $FreeBSD$
#

PORTNAME=	moettf
PORTVERSION=	1.0
CATEGORIES=	chinese x11-fonts
MASTER_SITES=	ftp://ftp.cc.ntut.edu.tw/OS/Linux/packages/chinese/fonts/twmoefont/ttf/ \
		ftp://ftp.ncu.edu.tw/Linux/Chinese/fonts/twmoefont/ttf/ \
		ftp://www.edu.tw/download/mandr/allbook/lishu/
DISTNAME=	${PKGNAME}
DISTFILES=	moe_kai.ttf moe_sung.ttf edustd-15.exe

MAINTAINER=	keith@freebsd.sinica.edu.tw

BUILD_DEPENDS=	unrar:${PORTSDIR}/archivers/unrar
LIB_DEPENDS=	font.1:${PORTSDIR}/x11-servers/XttXF86srv-common

USE_X_PREFIX=	yes
DIST_SUBDIR=	zh-moettf

NO_BUILD=	yes
NO_CDROM=	"Contact Taiwan Ministry of Education for commercial use."
SHAREMODE=	644
FONTDIR=	${PREFIX}/lib/X11/fonts/TrueType

.include <bsd.port.pre.mk>

do-extract:
	@${RM} -rf ${WRKDIR}
	@${MKDIR} ${WRKDIR}
	@unrar x ${DISTDIR}/${DIST_SUBDIR}/edustd-15.exe ${WRKDIR}
	@${MV} ${WRKDIR}/Edustd-15.TTF ${WRKDIR}/moe_lishu.ttf

do-install:
.if !exists(${FONTDIR})
	@${ECHO} "========================================================="
	@${ECHO} "Please add ${FONTDIR} to your font path"
	@${ECHO} "in /etc/XF86Config."
	@${ECHO} "========================================================="
	@${MKDIR} ${FONTDIR}
.endif
	@${INSTALL_DATA} ${WRKDIR}/moe_lishu.ttf ${FONTDIR}
	@${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/moe_kai.ttf ${FONTDIR}
	@${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/moe_sung.ttf ${FONTDIR}
	@${SETENV} PKG_PREFIX=${PREFIX} ${SH} ${PKGDIR}/INSTALL ${PKGNAME} POST-INSTALL

.include <bsd.port.post.mk>
