# New ports collection makefile for:	ruby-xmms2-ecore
# Date created:				23 Jun 2006
# Whom:					Alexander Botero-Lowry <alex@foxybanana.com>
#
# $FreeBSD$
#

CATEGORIES=	audio ruby
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
PKGNAMESUFFIX=	-ecore

MAINTAINER=	alex@foxybanana.com
COMMENT=	Ruby ecore mainloop bindings for XMMS2

BUILD_DEPENDS+=	${RUBY_SITEARCHLIBDIR}/xmmsclient.so:${PORTSDIR}/audio/ruby-xmms2
RUN_DEPENDS+=	${RUBY_SITEARCHLIBDIR}/xmmsclient.so:${PORTSDIR}/audio/ruby-xmms2

MASTERDIR=	${.CURDIR}/../xmms2

USE_RUBY=	yes
USE_GNOME=	glib20
USE_LDCONFIG=	yes

PLIST=		${.CURDIR}/pkg-plist

SCONS_TARGET=	src/clients/lib/xmmsclient-ecore/libxmmsclient-ecore.so \
		src/clients/lib/ruby/xmmsclient_ecore.so
XMMS2_SLAVE=	ruby-ecore

do-install:
	@cd ${WRKSRC} && ${INSTALL_PROGRAM} \
	src/clients/lib/ruby/xmmsclient_ecore.so \
	${RUBY_SITEARCHLIBDIR}/xmmsclient_ecore.so
	@cd ${WRKSRC} && ${INSTALL_PROGRAM} \
	src/clients/lib/xmmsclient-ecore/libxmmsclient-ecore.so \
	${LOCALBASE}/lib/libxmmsclient-ecore.so

.include "${MASTERDIR}/Makefile"
