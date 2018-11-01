# Created by: Yukihiro Nakai <nakai@FreeBSD.org>
# $FreeBSD$

PORTNAME=	jmode
PORTVERSION=	0.6.7
PORTREVISION=	9
CATEGORIES=	japanese
MASTER_SITES=	OSDN/anthy/5467

MAINTAINER=	nobutaka@FreeBSD.org
COMMENT?=	XIM server for Anthy input method

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

NOT_FOR_ARCHS=	aarch64 mips mips64 powerpc64 sparc64

LIB_DEPENDS=	libanthy.so:japanese/anthy

USES=		gettext-runtime gnome
USE_GNOME=	gtk12
USE_XORG=	x11 xext xi

GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

.include <bsd.port.mk>
