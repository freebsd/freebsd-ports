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
NO_BUILD=	yes
# NO_INSTALL=	yes

# OPTIONS+=	CSHARP "C# bindings" on
# OPTIONS+=	JAVA "Java bindings" on
# OPTIONS+=	PHP "PHP bindings" on
OPTIONS+=	PYTHON "Python bindings" on
OPTIONS+=	RUBY "Ruby bindings" on

.include <bsd.port.options.mk>

# .if !defined(WITHOUT_CSHARP)
# RUN_DEPENDS+=	kdebindings-csharp>=4.1.0:${PORTSDIR}/devel/kdebindings4-csharp
# .endif
#
# .if !defined(WITHOUT_JAVA)
# RUN_DEPENDS+=	kdebindings-java>=4.1.0:${PORTSDIR}/devel/kdebindings4-java
# .endif
#
# .if !defined(WITHOUT_PHP)
# RUN_DEPENDS+=	kdebindings-php>=4.1.0:${PORTSDIR}/devel/kdebindings4-php
# .endif

.if !defined(WITHOUT_PYTHON)
RUN_DEPENDS+=	kdebindings-python>=4.1.0:${PORTSDIR}/devel/kdebindings4-python
.endif

.if !defined(WITHOUT_RUBY)
RUN_DEPENDS+=	${KDE4_PREFIX}/bin/krubyapplication:${PORTSDIR}/devel/kdebindings4-ruby
.endif

do-install:
	${DO_NADA}

.include <bsd.port.mk>
