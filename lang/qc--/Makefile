# ex:ts=8
# Ports collection makefile for:	qc--
# Date created:			Nov 10, 2003
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	qc--
PORTVERSION=	20031201
CATEGORIES=	lang
MASTER_SITES=	http://www.cminusminus.org/rsync/dist/
DISTNAME=	${PORTNAME}${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	The Quick C-- Compiler

BROKEN=		"Does not fetch"
DEPRECATED=	${BROKEN}
EXPIRATION_DATE=2004-06-18

BUILD_DEPENDS=	ocamlc:${PORTSDIR}/lang/ocaml \
		notangle:${PORTSDIR}/devel/noweb \
		latex:${PORTSDIR}/print/teTeX \
		mk:${PORTSDIR}/devel/mk \
		gsed:${PORTSDIR}/textproc/gsed
LIB_DEPENDS=	lua.5:${PORTSDIR}/lang/lua

USE_PERL5_BUILD=	yes
HAS_CONFIGURE=	yes

MAN1=	camlburg.1 camlburgfix.1 nofake.1 ocamlerror.1 \
	qc--.1 qc--internals.1 qc--interp.1

do-build:
	@(cd ${WRKSRC} && mk timestamps && mk all.opt)

do-install:
	@(cd ${WRKSRC} && mk install.opt)

.include <bsd.port.mk>
