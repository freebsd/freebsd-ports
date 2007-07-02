# New ports collection makefile for:	digikam
# Date created: 			3 February 2003
# Whom:					Arjan van Leeuwen <avleeuwen@piwebs.com>
#
# $FreeBSD$
#

PORTNAME=	digikam
DISTVERSION=	0.9.2
CATEGORIES=	graphics kde
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ale@FreeBSD.org
COMMENT=	Photo album manager for KDE with gphoto2 backend

LIB_DEPENDS=	tiff.4:${PORTSDIR}/graphics/tiff \
		kipi.1:${PORTSDIR}/graphics/libkipi \
		gphoto2.2:${PORTSDIR}/graphics/libgphoto2 \
		kexiv2.2:${PORTSDIR}/graphics/libkexiv2 \
		lcms.1:${PORTSDIR}/graphics/lcms \
		kdcraw.1:${PORTSDIR}/graphics/libkdcraw \
		png.5:${PORTSDIR}/graphics/png \
		sqlite3.8:${PORTSDIR}/databases/sqlite3 \
		jasper.4:${PORTSDIR}/graphics/jasper

USE_BZIP2=	yes
USE_AUTOTOOLS=	libtool:15
CONFIGURE_ARGS=	--mandir=${PREFIX}/man
USE_GMAKE=	yes
USE_KDELIBS_VER=3
USE_GETTEXT=	yes
USE_LDCONFIG=	yes
INSTALLS_ICONS=	yes

MAN1=		digitaglinktree.1

post-patch:
	@${REINPLACE_CMD} -e 's|-O2||g;s|-fno-schedule-insns -fno-inline||g' \
		${WRKSRC}/${CONFIGURE_SCRIPT}
	@${REINPLACE_CMD} -e 's@-lpthread@${PTHREAD_LIBS}@g' ${WRKSRC}/${CONFIGURE_SCRIPT}
	@${REINPLACE_CMD} 's/install-data-local: install-apidox/install-data-local:/' \
		${WRKSRC}/digikam/Makefile.in ${WRKSRC}/digikam/digikam/Makefile.in

.include <bsd.port.mk>
