# New ports collection makefile for:	ruby-xmms2-ecore
# Date created:				23 Jun 2006
# Whom:					Alexander Botero-Lowry <alex@foxybanana.com>
#
# $FreeBSD$
#

CATEGORIES=	audio ruby
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
PKGNAMESUFFIX=	-ecore

MAINTAINER=	alexbl@FreeBSD.org
COMMENT=	Ruby ecore mainloop bindings for XMMS2

BUILD_DEPENDS+=	${RUBY_SITEARCHLIBDIR}/xmmsclient_ext.so:${PORTSDIR}/audio/ruby-xmms2
RUN_DEPENDS+=	${RUBY_SITEARCHLIBDIR}/xmmsclient_ext.so:${PORTSDIR}/audio/ruby-xmms2

MASTERDIR=	${.CURDIR}/../xmms2

USE_RUBY=	yes
USE_GNOME=	glib20
USE_EFL=	ecore
USE_LDCONFIG=	yes

PLIST=		${.CURDIR}/pkg-plist

BROKEN=	Fails to configure (can not find ecore-config)

XMMS2_SLAVE=	ruby-ecore

.include "${MASTERDIR}/Makefile"
