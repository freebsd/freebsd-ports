# Created by: asami
# $FreeBSD$

PORTNAME=	oneko
PORTVERSION=	2.0b
PORTREVISION=	5
CATEGORIES=	games
MASTER_SITES=	http://www.3bit.co.jp/~sasaki/oneko/ \
		http://www.net24.ne.jp/~ryo2/archives/:ryo2 \
		http://www2u.biglobe.ne.jp/~hsaka/distfiles/:hsaka
DISTFILES=	oneko-2.0b.tar.gz \
		oneko-2.0b-pop1.1-patch.tar.gz \
		oneko-2.0b-tip1.7.tar.gz:ryo2 \
		oneko-2.0b-sender0.5.tar.gz:hsaka \
		oneko-2.0b-bsd0.2.tar.gz:hsaka
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	candy@kgc.co.jp
COMMENT=	Cat chasing a mouse all over the screen

BUILD_DEPENDS=	nkf:japanese/nkf

CONFLICTS=	oneko-1.*

GNU_CONFIGURE=	yes
USE_XORG=	x11 xpm xmu
WRKSRC=		${WRKDIR}/${PORTNAME}
INSTALL_TARGET=	install install.man
MAKE_ARGS=	MANSUFFIX=6 \
		MANDIR=${PREFIX}/man/man6 \
		JMANDIR=${PREFIX}/man/ja/man6

EXTRA_PATCHES=	${WRKDIR}/oneko-2.0b-pop1.1.patch:-p1 \
		${WRKSRC}/oneko-2.0b-tip1.7.patch:-p1 \
		${WRKDIR}/oneko-2.0b-sender0.5.patch:-p1 \
		${WRKDIR}/oneko-2.0b-bsd0.2.patch:-p1

.include <bsd.port.mk>
