# New ports collection makefile for:	cpp-xmms2
# Date created:				06 Jul 2006
# Whom:					Alexander Botero-Lowry <alex@foxybanana.com>
#
# $FreeBSD$
#

PORTREVISION=	6
CATEGORIES=	audio
PKGNAMEPREFIX=	cpp-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	C++ Bindings for XMMS2

LIB_DEPENDS+=	boost_signals.4:${PORTSDIR}/devel/boost-libs \
		xmmsclient.6:${PORTSDIR}/audio/xmms2

MASTERDIR=	${.CURDIR}/../xmms2
USE_LDCONFIG=	yes
USE_GNOME=	glib20

PLIST=		${.CURDIR}/pkg-plist

XMMS2_SLAVE=	cpp

.include "${MASTERDIR}/Makefile"
