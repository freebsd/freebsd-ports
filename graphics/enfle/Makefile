# New ports collection makefile for:	enfle
# Date created:		Tue Sep 28 02:25:17 JST 1999
# Whom:			Yuki Sawada <samy@goldmoon.org>
#
# $FreeBSD$
#

PORTNAME=	enfle
PORTVERSION=	20000615
CATEGORIES=	graphics
MASTER_SITES=	http://enfle.fennel.org/ \
		http://www3.big.or.jp/~sian/linux/products/enfle/ \
		ftp://ftp.goldmoon.org/pub/FreeBSD/ports/distfiles/

MAINTAINER=	samy@goldmoon.org

LIB_DEPENDS=	png.3:${PORTSDIR}/graphics/png \
		jpeg.9:${PORTSDIR}/graphics/jpeg \
		bz2.1:${PORTSDIR}/archivers/bzip2 \
		arc.1:${PORTSDIR}/archivers/libarc

USE_BZIP2=	yes
USE_X_PREFIX=	yes
USE_LIBTOOL=	yes
CONFIGURE_ARGS=	--enable-all-plugins \
		--enable-plugins-dir \
		--disable-static

MAN1=		enfle.1

post-install:
	${INSTALL_MAN} ${WRKSRC}/enfle.1 ${PREFIX}/man/man1

.include <bsd.port.mk>
