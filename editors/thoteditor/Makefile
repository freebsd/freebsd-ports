# New ports collection makefile for:	thot
# Version required:	2.1e
# Date created:		1 Aug 1997
# Whom:			Pedro Giffuni (orig)
#
# $FreeBSD$
#

DISTNAME=	thoteditor-src-2.1e
PKGNAME=	thoteditor-2.1
CATEGORIES=	editors www
MASTER_SITES=	ftp://ftp.inrialpes.fr/pub/opera/sources/thot/ \
		${MASTER_SITE_SUNSITE} \
		ftp://ftp.ruhr-uni-bochum.de/local/jk.collection/thot/ \
		ftp://ftp.uni-stuttgart.de/pub/comm/infosystems/www/clients/amaya/thot/ \
		ftp://ftp.netlab.is.tsukuba.ac.jp/pub/editors/opera.inrialpes.fr/sources/thot/ \
		ftp://ftp.agix.net/pub/infosystems/www/clients/amaya/thot/
MASTER_SITE_SUBDIR=	apps/editors/X/thot

MAINTAINER=	chuckr@FreeBSD.org

THOT_SUBDIR=	Target
REQUIRES_MOTIF=	yes
WRKSRC=		$(WRKDIR)/Thot/$(THOT_SUBDIR)

BROKEN=		initialization issues not finished yet

REQUIRES_MOTIF=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-thot --enable-plugin --without-insure --without-amaya --disable-java --disable-intr --disable-jit --disable-math --disable-ilu
USE_GMAKE=	yes
ALL_TARGET=	all schemas

do-configure:
	(cd $(WRKSRC);../configure $(CONFIGURE_ARGS))

post-extract:
	(cd $(WRKDIR)/Thot;$(MKDIR) $(THOT_SUBDIR))

post-install:
	${MKDIR} ${PREFIX}/share/thot/doc

.include <bsd.port.mk>
