# Created by: Yuichi Narahara
# $FreeBSD$

PORTNAME=	sxsame
PORTVERSION=	3.02
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	http://hanzubon.jp/mirrors/Vine/%SUBDIR%/ \
		http://ftp.jaist.ac.jp/pub/Linux/Vine/%SUBDIR%/ \
		http://ftp.riken.go.jp/Linux/vine/%SUBDIR%/ \
		http://ftp.yz.yamagata-u.ac.jp/pub/Linux/Vine/%SUBDIR%/ \
		http://ftp.nara.wide.ad.jp/pub/Linux/vine/%SUBDIR%/ \
		http://ftp.vinelinux.org/pub/Vine/%SUBDIR%/ \
		http://www.asahi-net.or.jp/~fj9y-ynym/
MASTER_SITE_SUBDIR=	VinePlus/1.1/JG-0.9.1/sources

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Tile-removing puzzle game for the X Window system

USES=		imake xorg
USE_XORG=	xpm
INSTALL_TARGET=	install install.dir

OPTIONS_DEFINE=	DOCS

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/sxsame ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/X11/sxsame
	(cd ${WRKSRC}/contrib ; ${COPYTREE_SHARE} . ${STAGEDIR}${PREFIX}/lib/X11/sxsame)
	${TOUCH} ${STAGEDIR}${PREFIX}/lib/X11/sxsame/hiscore
	@${CHMOD} -R 775 ${STAGEDIR}${PREFIX}/lib/X11/sxsame
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for i in INSTALL.jp README.jp
	${INSTALL_DATA} ${WRKSRC}/${i} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
