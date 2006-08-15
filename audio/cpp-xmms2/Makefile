# New ports collection makefile for:	cpp-xmms2
# Date created:				06 Jul 2006
# Whom:					Alexander Botero-Lowry <alex@foxybanana.com>
#
# $FreeBSD$
#

CATEGORIES=	audio
PKGNAMEPREFIX=	cpp-

MAINTAINER=	alex@foxybanana.com
COMMENT=	C++ Bindings for XMMS2

LIB_DEPENDS=	boost_signals.3:${PORTSDIR}/devel/boost
BUILD_DEPENDS=	${LOCALBASE}/lib/libxmmsclient.so:${PORTSDIR}/audio/xmms2
RUN_DEPENDS=	${LOCALBASE}/lib/libxmmsclient.so:${PORTSDIR}/audio/xmms2

MASTERDIR=	${.CURDIR}/../xmms2
USE_LDCONFIG=	yes

PLIST_FILE=		${.CURDIR}/pkg-plist

SCONS_TARGET=	src/clients/lib/xmmsclient++/libxmmsclient++.so \
		src/clients/lib/xmmsclient++-glib//libxmmsclient++-glib.so
XMMS2_SLAVE=	cpp

do-install:
	@cd ${WRKSRC} && ${INSTALL_PROGRAM} \
		src/clients/lib/xmmsclient++/libxmmsclient++.so \
		${TARGETDIR}/lib/libxmmsclient++.so
	@cd ${WRKSRC} && ${INSTALL_PROGRAM} \
		src/clients/lib/xmmsclient++-glib/libxmmsclient++-glib.so \
		${TARGETDIR}/lib/libxmmsclient++-glib.so

.include "${MASTERDIR}/Makefile"
