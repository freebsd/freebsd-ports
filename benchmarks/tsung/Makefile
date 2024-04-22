PORTNAME=	tsung
DISTVERSION=	1.8.0
PORTREVISION=	1
CATEGORIES=	benchmarks sysutils
MASTER_SITES=	http://tsung.erlang-projects.org/dist/

MAINTAINER=	Clockwork6400@protonmail.com
COMMENT=	Multi-protocol distributed load testing tool
WWW=		http://tsung.erlang-projects.org/

LICENSE=	GPLv2

BUILD_DEPENDS=	erlc:lang/erlang
RUN_DEPENDS=	erl:lang/erlang

USES=		gmake perl5 python:run shebangfix
USE_PERL5=	run

SHEBANG_FILES=	src/*.pl.in src/tsung-plotter/tsplot.py.in \
		src/tsung-plotter/tsung/tsung.py

GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share

PLIST_SUB=	PORTVERSION=${PORTVERSION}

PORTEXAMPLES=	*

OPTIONS_DEFINE=	EXAMPLES

post-patch:
	@${REINPLACE_CMD} -e 's|MAN_DIR   = $$(datadir)/man/man1/|MAN_DIR   = $$(prefix)/share/man/man1/| ; \
		s|CONFDIR   = $$(docdir)/examples|CONFDIR   = $$(prefix)/share/examples/tsung| ; \
		s|install: doc|install: tsung doc|' \
		${WRKSRC}/Makefile.in

.include <bsd.port.mk>
