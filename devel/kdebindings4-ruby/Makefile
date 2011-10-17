# New ports collection makefile for:	kdebindings4-ruby
# Date created:				1 September 2011
# Whom:					Alberto Villa <avilla@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	kdebindings
PORTVERSION=	${KDE4_VERSION}
CATEGORIES=	devel kde
MASTER_SITES=	# empty
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTFILES=	# empty

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Meta port of Ruby bindings for KDE

USE_KDE4=	kdeprefix
USE_RUBY=	yes
RUBY_NO_BUILD_DEPENDS=	yes
RUBY_NO_RUN_DEPENDS=	yes
NO_BUILD=	yes

OPTIONS=	KORUNDUM "KDE bindings (requires QTRUBY)" on \
		KROSSRUBY "Kross Ruby scripting library (broken with Ruby 1.9)" on \
		QTRUBY "Qt bindings" on

.include <bsd.port.options.mk>

.if !defined(WITHOUT_KORUNDUM)
RUN_DEPENDS+=	${KDE4_PREFIX}/lib/kde4/krubypluginfactory.so:${PORTSDIR}/devel/kdebindings4-ruby-korundum
.endif

.if !defined(WITHOUT_QTRUBY) || !defined(WITHOUT_KORUNDUM)
RUN_DEPENDS+=	${KDE4_PREFIX}/lib/libqtruby4shared.so:${PORTSDIR}/devel/kdebindings4-ruby-qtruby
.endif

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_KROSSRUBY) && ${RUBY_VER} !=  1.9
RUN_DEPENDS+=	${KDE4_PREFIX}/lib/kde4/krossruby.so:${PORTSDIR}/devel/kdebindings4-ruby-krossruby
.endif

do-install:
	${DO_NADA}

.include <bsd.port.post.mk>
