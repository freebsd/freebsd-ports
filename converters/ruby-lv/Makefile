# New ports collection makefile for:	Ruby-lv
# Date created:		24 October 2002
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	lv
PORTVERSION=	0.12
CATEGORIES=	converters ruby
MASTER_SITES=	${MASTER_SITE_RUBY}
MASTER_SITE_SUBDIR=	contrib
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTNAME=	ruby-${PORTNAME}-${PORTVERSION}
DIST_SUBDIR=	ruby

MAINTAINER=	knu@FreeBSD.org
COMMENT=	A Ruby library to use LV's encoding conversion engine

EXTRACT_DEPENDS=	${NONEXISTENT}:${PORTSDIR}/${LV_PORT}:configure

LV_PORT=	misc/lv
LV_WRKSRC_CMD=	cd ${PORTSDIR}/${LV_PORT} && ${MAKE} -V WRKSRC

USE_RUBY=	yes
USE_RUBY_EXTCONF=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
INSTALL_TARGET=	site-install

DOCS_EN=	ChangeLog README doc/api-en/*
DOCS_JA=	README.ja doc/api-ja/*

.include <bsd.port.pre.mk>

.if ${ARCH} == "amd64"
BROKEN=		"Does not build on amd64 (Needs to link against shared library)"
.endif

post-extract:
	${CP} -Rp `${LV_WRKSRC_CMD}` ${WRKSRC}/lv
	${LN} -sf . ${WRKSRC}/lv/src
	${LN} -sf . ${WRKSRC}/lv/build

post-patch:
	cd ${WRKSRC}/lv; ${PATCH} Makefile < ${WRKSRC}/lv4491.patch

pre-configure:
	cd ${WRKSRC}/lv; ${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_ARGS} liblv.a

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${RUBY_MODDOCDIR}/ja
.for f in ${DOCS_EN}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_MODDOCDIR}/
.endfor
.for f in ${DOCS_JA}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_MODDOCDIR}/ja/
.endfor
.endif

.include <bsd.port.post.mk>
