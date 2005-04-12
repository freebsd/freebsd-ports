# New ports collection makefile for:	oneko
# Date created:		5 December 1994
# Whom:			asami
#
# $FreeBSD$
#

PORTNAME=	oneko
PORTVERSION=	2.0b
PORTREVISION=	3
CATEGORIES=	games
MASTER_SITES=	http://www02.so-net.ne.jp/~nsasaki/oneko/ \
		http://www.net24.ne.jp/~ryo2/archives/:ryo2 \
		http://www2u.biglobe.ne.jp/~hsaka/distfiles/:hsaka
DISTFILES=	oneko-2.0b.tar.gz \
		oneko-2.0b-pop1.1-patch.tar.gz \
		oneko-2.0b-tip1.7.tar.gz:ryo2 \
		oneko-2.0b-sender0.5.tar.gz:hsaka \
		oneko-2.0b-bsd0.2.tar.gz:hsaka
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	candy@kgc.co.jp
COMMENT=	A cat chasing a mouse all over the screen

BUILD_DEPENDS=	nkf:${PORTSDIR}/japanese/nkf

GNU_CONFIGURE=	yes
USE_X_PREFIX=	yes
MAN6=		oneko.6
MANLANG=	"" ja
WRKSRC=		${WRKDIR}/${PORTNAME}
INSTALL_TARGET=	install install.man
MAKE_ARGS=	MANSUFFIX=6 \
		MANDIR=${PREFIX}/man/man6 \
		JMANDIR=${PREFIX}/man/ja/man6

do-patch:
	@(cd ${WRKSRC}; \
	${PATCH} -p1 < ../oneko-2.0b-pop1.1.patch ; \
	${PATCH} -p1 < oneko-2.0b-tip1.7.patch ; \
	${PATCH} -p1 < ../oneko-2.0b-sender0.5.patch ; \
	${PATCH} -p1 < ../oneko-2.0b-bsd0.2.patch )

.include <bsd.port.mk>
