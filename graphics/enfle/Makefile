# New ports collection makefile for:	enfle
# Version required:	20000220
# Date created:		Tue Sep 28 02:25:17 JST 1999
# Whom:			Yuuki SAWADA <mami@whale.cc.muroran-it.ac.jp>
#
# $FreeBSD$
#

DISTNAME=	enfle-20000220
CATEGORIES=	graphics
MASTER_SITES=	http://enfle.fennel.org/ \
		ftp://ftp.goldmoon.org/pub/FreeBSD/ports/distfiles/

MAINTAINER=	mami@whale.cc.muroran-it.ac.jp

LIB_DEPENDS=	png.3:${PORTSDIR}/graphics/png \
		jpeg.9:${PORTSDIR}/graphics/jpeg

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-all-plugins \
		--enable-plugins-dir \
		--disable-static \
		--enable-archiver="-libarc" \
		--disable-mitshm

MAN1=		enfle.1

post-install:
	${INSTALL_MAN} ${WRKSRC}/enfle.1 ${PREFIX}/man/man1

.include <bsd.port.mk>
