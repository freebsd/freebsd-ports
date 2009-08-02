# New ports collection makefile for:	ruby-xmms2
# Date created:				18 Mar 2006
# Whom:					Alexander Botero-Lowry <alex@foxybanana.com>
#
# $FreeBSD$
#

PORTREVISION=	2
CATEGORIES=	audio ruby
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Ruby Bindings for XMMS2

LIB_DEPENDS+=	xmmsclient.4:${PORTSDIR}/audio/xmms2

MASTERDIR=	${.CURDIR}/../xmms2

USE_RUBY=	yes
USE_GNOME=	glib20

PLIST=		${.CURDIR}/pkg-plist

XMMS2_SLAVE=	ruby

.include "${MASTERDIR}/Makefile"
