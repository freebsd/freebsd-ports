# New ports collection makefile for:	enfle
# Date created:		Tue Sep 28 02:25:17 JST 1999
# Whom:			Yuuki SAWADA <yuuki@goldmoon.org>
#
# $FreeBSD$
#

PORTNAME=	enfle
PORTVERSION=	20000403
CATEGORIES=	graphics
MASTER_SITES=	http://enfle.fennel.org/ \
		ftp://ftp.goldmoon.org/pub/FreeBSD/ports/distfiles/

MAINTAINER=	yuuki@goldmoon.org

LIB_DEPENDS=	png.3:${PORTSDIR}/graphics/png \
		jpeg.9:${PORTSDIR}/graphics/jpeg

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-all-plugins \
		--enable-plugins-dir \
		--enable-archiver="-libarc" \
		--disable-static

MAN1=		enfle.1

post-install:
	${INSTALL_MAN} ${WRKSRC}/enfle.1 ${PREFIX}/man/man1

.include <bsd.port.mk>
