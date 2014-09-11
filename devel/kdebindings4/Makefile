# $FreeBSD$

PORTNAME=	kdebindings
PORTVERSION=	${KDE4_VERSION}
PORTREVISION=	2
CATEGORIES=	devel kde
DISTFILES=	# none

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KDE bindings (meta port)

USE_KDE4=	kdeprefix
NO_BUILD=	yes
NO_INSTALL=	yes
NO_MTREE=	yes

OPTIONS_DEFINE=	PERL PYTHON RUBY
OPTIONS_DEFAULT=	${OPTIONS_DEFINE}

PERL_DESC=	Perl bindings
PERL_USE=	KDE4=perlkde_run

PYTHON_DESC=	Python bindings
PYTHON_RUN_DEPENDS=	${KDE4_PREFIX}/lib/kde4/krosspython.so:${PORTSDIR}/devel/py-krosspython
PYTHON_USE=	KDE4=pykde4_run,pykdeuic4_run

RUBY_DESC=	Ruby bindings
RUBY_RUN_DEPENDS=	${KDE4_PREFIX}/lib/kde4/krossruby.so:${PORTSDIR}/devel/ruby-krossruby
RUBY_USE=	KDE4=korundum_run

.include <bsd.port.mk>
