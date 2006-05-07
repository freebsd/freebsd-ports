# New ports collection makefile for:	kasablanca
# Date created:			Fri Apr 16 12:10:00 CEST 2004
# Whom:				Markus Brueffer <markus@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=	kasablanca
PORTVERSION=	0.4.0.2
PORTREVISION=	2
CATEGORIES=	ftp kde
MASTER_SITES=	http://download.berlios.de/kasablanca/ \
		http://www.hitnet.rwth-aachen.de/~brueffer/distfiles/

MAINTAINER=	markus@FreeBSD.org
COMMENT=	Graphical ftp client for KDE

EXTRA_PATCHES=	${.CURDIR}/../../x11/kde3/files/extrapatch-old_configure

USE_KDELIBS_VER=3
USE_GMAKE=	yes
USE_OPENSSL=	yes
USE_AUTOTOOLS=	libtool:15

post-patch:
	@${REINPLACE_CMD} -e 's|-O2||g'	${WRKSRC}/${CONFIGURE_SCRIPT}
	@${REINPLACE_CMD} -e 's|\(-lssl\)|\1 -lcrypto|' \
		${WRKSRC}/src/Makefile.in

.include <bsd.port.mk>
