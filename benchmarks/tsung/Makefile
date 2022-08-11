PORTNAME=	tsung
DISTVERSION=	1.7.0
CATEGORIES=	benchmarks sysutils
MASTER_SITES=	http://tsung.erlang-projects.org/dist/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Multi-protocol distributed load testing tool

LICENSE=	GPLv2

BUILD_DEPENDS=	erlc:lang/erlang
RUN_DEPENDS=	erl:lang/erlang

USES=		gmake perl5 python:run shebangfix
USE_PERL5=	run

SHEBANG_FILES=	src/*.pl.in src/tsung-plotter/tsung/tsung.py \
		src/tsung-plotter/tsplot.py.in

GNU_CONFIGURE=	yes

PLIST_SUB=	PORTVERSION=${PORTVERSION}

OPTIONS_DEFINE=	EXAMPLES

PORTEXAMPLES=	*

post-patch:
	@${REINPLACE_CMD} -e 's|MAN_DIR   = $$(datadir)/man/man1/|MAN_DIR   = $$(prefix)/man/man1/| ; \
		s|CONFDIR   = $$(docdir)/examples|CONFDIR   = $$(prefix)/share/examples/tsung| ; \
		s|install: doc|install: tsung doc|' \
		${WRKSRC}/Makefile.in

.include <bsd.port.mk>
