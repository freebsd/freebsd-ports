# Created by: Yukihiro Nakai <nakai@FreeBSD.org>
# $FreeBSD$

PORTNAME=	jmode
PORTVERSION=	0.6.7
PORTREVISION=	9
CATEGORIES=	japanese
MASTER_SITES=	SFJP/anthy/5467

MAINTAINER=	nobutaka@FreeBSD.org
COMMENT?=	XIM server for Anthy input method

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libanthy.so:japanese/anthy

USE_GNOME=	gtk12
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

NOT_FOR_ARCHS=	aarch64 amd64 mips mips64 powerpc64 sparc64

.include <bsd.port.mk>
