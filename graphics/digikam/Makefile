# New ports collection makefile for:	digikam
# Date created: 			3 February 2003
# Whom:					Arjan van Leeuwen <avleeuwen@piwebs.com>
#
# $FreeBSD$
#

PORTNAME=	digikam
PORTVERSION=	0.7.2
CATEGORIES=	graphics kde
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	avleeuwen@piwebs.com
COMMENT=	Photo album manager for KDE with gphoto2 backend

LIB_DEPENDS=	kexif.1:${PORTSDIR}/graphics/libkexif \
		kipi.0:${PORTSDIR}/graphics/libkipi \
		gphoto2.2:${PORTSDIR}/graphics/libgphoto2 \
		Imlib2.3:${PORTSDIR}/graphics/imlib2 \
		gdbm.3:${PORTSDIR}/databases/gdbm
RUN_DEPENDS=	dcraw:${PORTSDIR}/graphics/dcraw

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_KDELIBS_VER=3
USE_REINPLACE=	yes
CONFIGURE_ARGS+=--program-prefix=''
INSTALLS_SHLIB=	yes

.include <bsd.port.pre.mk>

post-patch:
	@${REINPLACE_CMD} -e 's|-O2||g' ${WRKSRC}/${CONFIGURE_SCRIPT}
	@${REINPLACE_CMD} -e 's@-lpthread@${PTHREAD_LIBS}@g' ${WRKSRC}/${CONFIGURE_SCRIPT}

.include <bsd.port.post.mk>
