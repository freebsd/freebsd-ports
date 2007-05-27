# New ports collection makefile for:	cpp-xmms2
# Date created:				06 Jul 2006
# Whom:					Alexander Botero-Lowry <alex@foxybanana.com>
#
# $FreeBSD$
#

CATEGORIES=	audio
PKGNAMEPREFIX=	cpp-

MAINTAINER=	alexbl@FreeBSD.org
COMMENT=	C++ Bindings for XMMS2

LIB_DEPENDS+=	boost_signals.3:${PORTSDIR}/devel/boost \
				xmmsclient.2:${PORTSDIR}/audio/xmms2

MASTERDIR=	${.CURDIR}/../xmms2
USE_LDCONFIG=	yes
USE_GNOME=	glib20

PLIST=		${.CURDIR}/pkg-plist

XMMS2_SLAVE=	cpp

.include "${MASTERDIR}/Makefile"
