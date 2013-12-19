# Created by: Alexander Botero-Lowry <alex@foxybanana.com>
# $FreeBSD$

PORTREVISION=	4
CATEGORIES=	audio ruby
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Ruby Bindings for XMMS2

LIB_DEPENDS+=	libxmmsclient.so:${PORTSDIR}/audio/xmms2

MASTERDIR=	${.CURDIR}/../xmms2

USE_RUBY=	yes
NO_STAGE=	yes
USE_GNOME=	glib20

PLIST=		${.CURDIR}/pkg-plist

XMMS2_SLAVE=	ruby

.include "${MASTERDIR}/Makefile"
