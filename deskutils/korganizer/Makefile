# New ports collection makefile for:   korganizer
# Date created:        23 May 1998
# Whom:                Hans Petter Bieker <hanspb@persbraten.vgs.no>
#
# $FreeBSD$
#

PORTNAME=	korganizer
PORTVERSION=	1.1.2
CATEGORIES=	deskutils kde
MASTER_SITES=	$(MASTER_SITE_KDE)
MASTER_SITE_SUBDIR=	stable/1.1.2/distribution/tar/generic/source/bz2

USE_KDELIBS_VER=1
USE_BZIP2=	yes
GNU_CONFIGURE=	yes
USE_BISON=	yes
USE_GMAKE=	yes
CONFIGURE_ENV=	CXXFLAGS="$(CFLAGS)" \
		INSTALL_SCRIPT="install -c -m 555"

pre-configure:
	${RM} -rf -- $(WRKSRC)/src/.deps $(WRKSRC)/config.cache

.include <bsd.port.mk>
