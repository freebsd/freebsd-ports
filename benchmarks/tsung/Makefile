# Created by: Sergey Skvortsov <skv@protey.ru>
# $FreeBSD$

PORTNAME=	tsung
PORTVERSION=	1.6.0
CATEGORIES=	benchmarks sysutils
MASTER_SITES=	http://tsung.erlang-projects.org/dist/

MAINTAINER=	linpct@gmail.com
COMMENT=	Multi-protocol distributed load testing tool

LICENSE=	GPLv2

BUILD_DEPENDS=	erlc:lang/erlang
RUN_DEPENDS=	erl:lang/erlang

USE_PERL5=	run

GNU_CONFIGURE=	yes
USES=		gmake perl5 python:run shebangfix
SHEBANG_FILES=	src/*.pl.in src/tsung-plotter/tsung/tsung.py

PLIST_SUB=	PORTVERSION=${PORTVERSION}

OPTIONS_DEFINE=	DOCS EXAMPLES

post-patch:
	@${REINPLACE_CMD} -e 's|MAN_DIR   = $$(datadir)/man/man1/|MAN_DIR   = $$(prefix)/man/man1/| ; \
		s|CONFDIR   = $$(docdir)/examples|CONFDIR   = $$(prefix)/share/examples/tsung| ; \
		s|install: doc|install: tsung doc|' \
		${WRKSRC}/Makefile.in

.include <bsd.port.mk>
