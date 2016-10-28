# Created by: Stefan Zehl <sec@42.org>
# $FreeBSD$

PORTNAME=	libsidplay
PORTVERSION=	1.36.59
PORTREVISION=	1
CATEGORIES=	audio emulators
MASTER_SITES=	http://bsd-geek.de/FreeBSD/distfiles/ \
		LOCAL/ehaupt

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Commodore SID-chip emulator library to play SID music files

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	sid_cv_have_ios_binary=yes
INSTALL_TARGET=	install-strip
USES=		libtool tar:tgz
USE_LDCONFIG=	yes

.include <bsd.port.pre.mk>

.if ${ARCH} == "i386"
CONFIGURE_ARGS=	--enable-optendian --enable-optfixpoint
.endif

.include <bsd.port.post.mk>
