# New ports collection makefile for:	kftpgrabber
# Date created:				Thu Aug 19 00:35:34 CEST 2004
# Whom:					Markus Brueffer <markus@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=	kftpgrabber
PORTVERSION=	0.4.0
CATEGORIES=	ftp kde
MASTER_SITES=	http://kftpgrabber.sourceforge.net/releases/

PATCH_SITES=	http://www.brueffer.de/distfiles/
PATCHFILES=	${DISTNAME}-patch.gz

MAINTAINER=	markus@FreeBSD.org
COMMENT=	Graphical ftp client for KDE

USE_BZIP2=	yes
USE_KDELIBS_VER=3
USE_GMAKE=	yes
USE_OPENSSL=	yes
GNU_CONFIGURE=	yes
USE_REINPLACE=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|-O2||g'	${WRKSRC}/${CONFIGURE_SCRIPT}

.include <bsd.port.mk>
