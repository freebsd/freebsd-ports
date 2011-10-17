# New ports collection makefile for:	kdebindings4-kross-interpreters
# Date created:				1 September 2011
# Whom:					Alberto Villa <avilla@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	kross-interpreters
PORTVERSION=	${KDE4_VERSION}
CATEGORIES=	devel kde
MASTER_SITES=	# empty
PKGNAMEPREFIX=	kdebindings-
DISTFILES=	# empty

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Meta port of Kross scripting libraries for KDE 4

USE_KDE4=	kdeprefix
USE_RUBY=	yes
RUBY_NO_BUILD_DEPENDS=	yes
RUBY_NO_RUN_DEPENDS=	yes
NO_BUILD=	yes

OPTIONS=	KROSSPYTHON "Kross Python scripting library" on \
		KROSSRUBY "Kross Ruby scripting library (broken with Ruby 1.9)" on

.include <bsd.port.options.mk>

.if !defined(WITHOUT_KROSSPYTHON)
RUN_DEPENDS+=	${KDE4_PREFIX}/lib/kde4/krosspython.so:${PORTSDIR}/devel/kdebindings4-python-krosspython
.endif

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_KROSSRUBY) && ${RUBY_VER} != 1.9
RUN_DEPENDS+=	${KDE4_PREFIX}/lib/kde4/krossruby.so:${PORTSDIR}/devel/kdebindings4-ruby-krossruby
.endif

do-install:
	${DO_NADA}

.include <bsd.port.post.mk>
