# New ports collection makefile for:    games
# Version required:	1.8
# Date created:         Mon Dec 14 21:03:01 MET 1998
# Whom:                 jmz
#
# $Id: Makefile,v 1.8 1999/01/15 02:54:18 jmz Exp $
#

DISTNAME=	doomsrc-1.8
PKGNAME=	doom-1.8
CATEGORIES=	games
MASTER_SITES=	ftp://ftp.idsoftware.com/idstuff/source/ \
		ftp://ftp.stomped.com/pub/idmirror/idstuff/source/ \
		ftp://ftp.cdrom.com/pub/idgames/idstuff/source/ \
		ftp://ftp.gamesnet.net/idsoftware/source/
DISTFILES=	doomsrc.zip

MAINTAINER=	jmz@FreeBSD.org

BUILD_DEPENDS=	unzip:${PORTSDIR}/archivers/unzip

USE_XLIB=	yes
EXTRACT_CMD=	unzip
EXTRACT_ARGS=	-q
NO_WRKSUBDIR=	yes
USE_GMAKE=	yes

post-extract:
	@cd ${WRKDIR} && tar xzf linuxdoom-1.10.src.tgz && tar xzf sndserv.tgz

do-build:
	@cd ${WRKDIR}/linuxdoom-1.10 && ${GMAKE}
	@cd ${WRKDIR}/sndserv && ${GMAKE}

do-install:
	@${INSTALL_PROGRAM} ${WRKDIR}/linuxdoom-1.10/linux/linuxxdoom ${PREFIX}/bin/doom
	@${INSTALL_PROGRAM} ${WRKDIR}/sndserv/linux/sndserver ${PREFIX}/bin/sndserver

.include <bsd.port.mk>
