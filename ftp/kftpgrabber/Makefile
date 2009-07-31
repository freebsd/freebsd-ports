# New ports collection makefile for:	kftpgrabber
# Date created:				Thu Aug 19 00:35:34 CEST 2004
# Whom:					Markus Brueffer <markus@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=	kftpgrabber
PORTVERSION=	0.8.1
PORTREVISION=	2
CATEGORIES=	ftp kde
MASTER_SITES=	http://www.kftp.org/uploads/files/

MAINTAINER=	markus@FreeBSD.org
COMMENT=	Graphical FTP client for KDE

USE_BZIP2=	yes
USE_KDELIBS_VER=3
USE_GMAKE=	yes
USE_OPENSSL=	yes
USE_AUTOTOOLS=	libtool:15

post-patch:
	@${REINPLACE_CMD} -e 's|-O2||g'	${WRKSRC}/${CONFIGURE_SCRIPT}

.include <bsd.port.mk>
