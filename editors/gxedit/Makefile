# New ports collection makefile for:	gxedit
# Date created:				01 Jul 1998
# Whom:					Dom Mitchell <dom@happygiraffe.net>
#
# $FreeBSD$
#

PORTNAME=	gxedit
PORTVERSION=	1.23
PORTREVISION=	1
CATEGORIES=	editors
MASTER_SITES=	http://mirrors.darkelf.net/GXedit/ \
		http://www.linuxbox.com/~drow/GXedit/
DISTNAME=	GXedit${PORTVERSION}

MAINTAINER=	dom@happygiraffe.net
COMMENT=	A simple GTK+ editor

USE_X_PREFIX=	yes
USE_REINPLACE=	yes
USE_GNOME=	gtk12

ALL_TARGET=	gxedit

post-patch:
	@${REINPLACE_CMD} -e "s|%%LOCALBASE%%|${LOCALBASE}|g" ${WRKSRC}/config.h

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/gtk-shell ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/gxedit ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/ftp.sh ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/ftp-ls.sh ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/ftp-put.sh ${PREFIX}/bin
	${MKDIR} ${PREFIX}/share/gxedit/
.for i in popmail.scr traceroute.scr userinfo.scr www.scr
	${INSTALL_DATA} ${WRKSRC}/$i ${PREFIX}/share/gxedit
.endfor
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/gxedit/
.for i in charmap.txt manual.ps manual.txt quickref.ps quickref.txt
	${INSTALL_DATA} ${WRKSRC}/docs/$i ${PREFIX}/share/doc/gxedit/
.endfor
.endif

.include <bsd.port.mk>
