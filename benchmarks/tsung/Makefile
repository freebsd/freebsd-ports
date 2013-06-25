# Created by: Sergey Skvortsov <skv@protey.ru>
# $FreeBSD$

PORTNAME=	tsung
PORTVERSION=	1.5.0
CATEGORIES=	benchmarks sysutils
MASTER_SITES=	http://tsung.erlang-projects.org/dist/

MAINTAINER=	linpct@gmail.com
COMMENT=	Multi-protocol distributed load testing tool

LICENSE=	GPLv2

BUILD_DEPENDS=	erlc:${PORTSDIR}/lang/erlang
RUN_DEPENDS=	erl:${PORTSDIR}/lang/erlang

USE_PERL5_RUN=	yes
USE_PYTHON_RUN=	yes

GNU_CONFIGURE=	yes
USE_GMAKE=	yes

PLIST_SUB=	PORTVERSION=${PORTVERSION}

MAN1=	tsplot.1 tsung-recorder.1 tsung.1

post-patch-script:
	@${REINPLACE_CMD} -e 's|MAN_DIR   = $$(datadir)/man/man1/|MAN_DIR   = $$(prefix)/man/man1/|' \
		${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e 's|CONFDIR   = $$(docdir)/examples|CONFDIR   = $$(prefix)/share/examples/tsung|' \
		${WRKSRC}/Makefile.in

.include <bsd.port.mk>
