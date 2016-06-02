# $FreeBSD$

PORTNAME=	kdebindings
PORTVERSION=	${KDE4_VERSION}
CATEGORIES=	devel kde

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KDE bindings (meta port)

USE_KDE4=	# blank, needed to get KDE4_VERSION
USES=		metaport

OPTIONS_DEFINE=	PERL PYTHON RUBY
OPTIONS_DEFAULT=	${OPTIONS_DEFINE}

PERL_DESC=	Perl bindings
PERL_USE=	KDE4=perlkde_run

PYTHON_DESC=	Python bindings
PYTHON_RUN_DEPENDS=	${KDE4_PREFIX}/lib/kde4/krosspython.so:devel/py-krosspython
PYTHON_USE=	KDE4=pykde4_run,pykdeuic4_run

RUBY_DESC=	Ruby bindings
RUBY_RUN_DEPENDS=	${KDE4_PREFIX}/lib/kde4/krossruby.so:devel/ruby-krossruby
RUBY_USE=	KDE4=korundum_run

.include <bsd.port.mk>
