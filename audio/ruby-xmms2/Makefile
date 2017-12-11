# Created by: Alexander Botero-Lowry <alex@foxybanana.com>
# $FreeBSD$

PORTREVISION=	4
CATEGORIES=	audio ruby
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Ruby Bindings for XMMS2

LIB_DEPENDS+=	libxmmsclient.so:audio/xmms2

MASTERDIR=	${.CURDIR}/../xmms2

CONFIGURE_TARGET=	configure
USE_RUBY=	yes
USE_GNOME=	glib20

BROKEN_RUBY22=	yes
BROKEN_RUBY23=	yes
BROKEN_RUBY24=	yes

DEPRECATED=     Does not build with current versions of ruby
EXPIRATION_DATE=	2018-01-12

PLIST=		${.CURDIR}/pkg-plist

XMMS2_SLAVE=	ruby

.include "${MASTERDIR}/Makefile"
