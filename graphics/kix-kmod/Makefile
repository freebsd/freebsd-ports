# Created by: Jonathan Belson <jon@witchspace.com>
# $FreeBSD$

PORTNAME=       kix
PORTVERSION=	1.0
PORTREVISION=	1
CATEGORIES=     graphics
MASTER_SITES=   http://homepage.ntlworld.com/jon.belson/files/kix-1.0.tar.gz \
	LOCAL/pgollucci
PKGNAMESUFFIX=	-kmod

MAINTAINER=	jon@witchspace.com
COMMENT=	A graphical screensaver kernel module

NO_STAGE=	yes

USES=		kmod
.include <bsd.port.pre.mk>

MAKE_ENV+=	WERROR=
PLIST_FILES=	lib/kix_saver.ko
SUB_FILES=	pkg-message

do-install:
	${INSTALL_KLD} ${WRKSRC}/kix_saver.ko ${PREFIX}/lib

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
