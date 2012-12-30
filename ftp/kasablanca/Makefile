# Create by: Markus Brueffer <markus@FreeBSD.org>
# $FreeBSD$

PORTNAME=	kasablanca
PORTVERSION=	0.4.0.2
PORTREVISION=	8
CATEGORIES=	ftp kde
MASTER_SITES=	BERLIOS \
		http://www.hitnet.rwth-aachen.de/~brueffer/distfiles/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Graphical ftp client for KDE

DEPRECATED=	Depends on QT3; unmaintained
EXPIRATION_DATE=	2013-07-01

EXTRA_PATCHES=	${.CURDIR}/../../x11/kde3/files/extrapatch-old_configure

USE_KDELIBS_VER=3
USE_GMAKE=	yes
USE_OPENSSL=	yes
USE_AUTOTOOLS=	libtool

post-patch:
	@${REINPLACE_CMD} -e 's|-O2||g'	${WRKSRC}/${CONFIGURE_SCRIPT}
	@${REINPLACE_CMD} -e 's|\(-lssl\)|\1 -lcrypto|' \
		${WRKSRC}/src/Makefile.in

.include <bsd.port.mk>
