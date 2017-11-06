# Created by: Jonathan Belson <jon@witchspace.com>
# $FreeBSD$

PORTNAME=	kix
PORTVERSION=	1.0
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	http://homepage.ntlworld.com/jon.belson/files/ \
		LOCAL/pgollucci
PKGNAMESUFFIX=	-kmod

MAINTAINER=	jon@witchspace.com
COMMENT=	Graphical screensaver kernel module

BROKEN_powerpc64=	fails to compile: pcpu.h: size of array '__assert_0' is negative

USES=		kmod

MAKE_ENV+=	WERROR=
PLIST_FILES=	lib/kix_saver.ko
SUB_FILES=	pkg-message

do-install:
	${INSTALL_KLD} ${WRKSRC}/kix_saver.ko ${STAGEDIR}${PREFIX}/lib

.include <bsd.port.mk>
