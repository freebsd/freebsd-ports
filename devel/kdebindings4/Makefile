# $FreeBSD$

PORTNAME=	kdebindings
PORTVERSION=	${KDE4_VERSION}
PORTREVISION=	1
CATEGORIES=	devel kde
MASTER_SITES=	# empty
DISTFILES=	# none

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KDE bindings (meta port)

USE_KDE4=	kdeprefix
NO_BUILD=	yes

OPTIONS_DEFINE=	PERL PYTHON RUBY
OPTIONS_DEFAULT=	${OPTIONS_DEFINE}

PERL_DESC=	Perl bindings
PYTHON_DESC=	Python bindings
RUBY_DESC=	Ruby bindings

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MPERL}
USE_KDE4+=	perlkde_run
.endif

.if ${PORT_OPTIONS:MPYTHON}
RUN_DEPENDS+=	${KDE4_PREFIX}/lib/kde4/krosspython.so:${PORTSDIR}/devel/py-krosspython
USE_KDE4+=	pykde4_run pykdeuic4_run
.endif

.if ${PORT_OPTIONS:MRUBY}
RUN_DEPENDS+=	${KDE4_PREFIX}/lib/kde4/krossruby.so:${PORTSDIR}/devel/ruby-krossruby
USE_KDE4+=	korundum_run
.endif

do-install:
	${DO_NADA}

.include <bsd.port.mk>
