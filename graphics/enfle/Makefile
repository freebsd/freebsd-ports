# New ports collection makefile for:	enfle
# Version required:	19991102
# Date created:		Tue Sep 28 02:25:17 JST 1999
# Whom:			Yuuki SAWADA <mami@whale.cc.muroran-it.ac.jp>
#
# $FreeBSD$
#

DISTNAME=	enfle-19991102
CATEGORIES=	graphics
MASTER_SITES=	http://enfle.fennel.org/ \
		ftp://ftp.goldmoon.org:1200/pub/FreeBSD/distfiles/

MAINTAINER=	mami@whale.cc.muroran-it.ac.jp

BUILD_DEPENDS=	bzip2:${PORTSDIR}/archivers/bzip2
LIB_DEPENDS=    png.3:${PORTSDIR}/graphics/png \
		jpeg.9:${PORTSDIR}/graphics/jpeg

USE_GMAKE=	yes
USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-all-plugins --disable-static \
		--enable-plugins-dir

MAN1=		enfle.1

post-install:
	${INSTALL_MAN} ${WRKSRC}/enfle.1 ${PREFIX}/man/man1

.include <bsd.port.mk>
