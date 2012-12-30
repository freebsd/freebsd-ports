# New ports collection makefile for:	kftpgrabber
# Date created:				Thu Aug 19 00:35:34 CEST 2004
# Whom:					Markus Brueffer <markus@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=	kftpgrabber
PORTVERSION=	0.8.1
PORTREVISION=	5
CATEGORIES=	ftp kde
MASTER_SITES=	http://www.kftp.org/uploads/files/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Graphical FTP client for KDE

DEPRECATED=	Depends on QT3; unmaintained
EXPIRATION_DATE=	2013-07-01

USE_BZIP2=	yes
USE_KDELIBS_VER=3
USE_GMAKE=	yes
USE_OPENSSL=	yes
USE_AUTOTOOLS=	libtool

post-patch:
	@${REINPLACE_CMD} -e 's|-O2||g'	${WRKSRC}/${CONFIGURE_SCRIPT}

.include <bsd.port.mk>
