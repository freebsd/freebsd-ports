# New ports collection makefile for:	digikam
# Date created: 			3 February 2003
# Whom:					Arjan van Leeuwen <avleeuwen@piwebs.com>
#
# $FreeBSD$
#

PORTNAME=	digikam
PORTVERSION=	0.6
PORTREVISION=	1
CATEGORIES=	graphics kde
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	avleeuwen@piwebs.com
COMMENT=	Photo album manager for KDE with gphoto2 backend

LIB_DEPENDS=	exif:${PORTSDIR}/graphics/libexif \
		gphoto2.2:${PORTSDIR}/graphics/libgphoto2 \
		Imlib.5:${PORTSDIR}/graphics/imlib

BROKEN=		Does not compile

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_KDELIBS_VER=3
USE_REINPLACE=	yes
CONFIGURE_ARGS+=--program-prefix=''
INSTALLS_SHLIB=	yes

MAN1=		digikam.1 digikamcameraclient.1
MANCOMPRESSED=	yes

.include <bsd.port.pre.mk>

pre-configure::
	${REINPLACE_CMD} -e 's@-lpthread@${PTHREAD_LIBS}@g' ${WRKSRC}/configure

.include <bsd.port.post.mk>
