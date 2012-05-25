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

OPTIONS=	PERL "Perl bindings" on \
		PYTHON "Python bindings" on \
		RUBY "Ruby bindings" on

.include <bsd.port.options.mk>

.if !defined(WITHOUT_PERL)
USE_KDE4+=	perlkde_run
.endif

.if !defined(WITHOUT_PYTHON)
RUN_DEPENDS+=	${KDE4_PREFIX}/lib/kde4/krosspython.so:${PORTSDIR}/devel/kdebindings4-python-krosspython
USE_KDE4+=	pykde4_run pykdeuic4_run
.endif

.if !defined(WITHOUT_RUBY)
RUN_DEPENDS+=	${KDE4_PREFIX}/lib/kde4/krossruby.so:${PORTSDIR}/devel/kdebindings4-ruby-krossruby
USE_KDE4+=	korundum_run
.endif

do-install:
	${DO_NADA}

.include <bsd.port.mk>
