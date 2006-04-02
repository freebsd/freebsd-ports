# New ports collection makefile for:	ruby-xmms2
# Date created:				18 Mar 2006
# Whom:					Alexander Botero-Lowry <alex@foxybanana.com>
#
# $FreeBSD$
#

CATEGORIES=	audio ruby
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}

MAINTAINER=	alex@foxybanana.com
COMMENT=	Ruby Bindings for XMMS2

BUILD_DEPENDS+=	${LOCALBASE}/lib/libxmmsclient.so:${PORTSDIR}/audio/xmms2
RUN_DEPENDS+=	${LOCALBASE}/lib/libxmmsclient.so:${PORTSDIR}/audio/xmms2

MASTERDIR=	${.CURDIR}/../xmms2

USE_RUBY=	yes
USE_GNOME=	glib20

PLIST=		${.CURDIR}/pkg-plist

SCONS_TARGET=	src/clients/lib/ruby/xmmsclient.so \
		src/clients/lib/ruby/xmmsclient_glib.so
XMMS2_SLAVE=	ruby

do-install:
	@cd ${WRKSRC} && ${INSTALL_PROGRAM} src/clients/lib/ruby/xmmsclient.so \
	${RUBY_SITEARCHLIBDIR}/xmmsclient.so
	@cd ${WRKSRC} && ${INSTALL_PROGRAM} \
	src/clients/lib/ruby/xmmsclient_glib.so \
	${RUBY_SITEARCHLIBDIR}/xmmsclient_glib.so

.include "${MASTERDIR}/Makefile"
