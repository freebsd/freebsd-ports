# New ports collection makefile for:	kdebindings4
# Date created:		2008-08-19
# Whom:			Max Brazhnikov <makc@issp.ac.ru>
#
# $FreeBSD$
#

PORTNAME=	kdebindings
PORTVERSION=	${KDE4_VERSION}
CATEGORIES=	devel kde
MASTER_SITES=	# empty
DISTFILES=	# none

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KDE bindings meta port

USE_KDE4=	kdeprefix
USE_PYTHON=	yes
PYTHON_NO_DEPENDS=	yes
USE_RUBY=	yes
RUBY_NO_BUILD_DEPENDS=	yes
RUBY_NO_RUN_DEPENDS=	yes
NO_BUILD=	yes

OPTIONS=	PYTHON "Python bindings" on \
		RUBY "Ruby bindings" on

.include <bsd.port.options.mk>

.if !defined(WITHOUT_PYTHON)
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}kdebindings>=4.1.0:${PORTSDIR}/devel/kdebindings4-python
.endif

.if !defined(WITHOUT_RUBY)
RUN_DEPENDS+=	${RUBY_PKGNAMEPREFIX}kdebindings>=4.7.0:${PORTSDIR}/devel/kdebindings4-ruby
.endif

do-install:
	${DO_NADA}

.include <bsd.port.mk>
