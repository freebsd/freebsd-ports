# New ports collection makefile for:	Ruby-iconv
# Date created:		7 Aug 2000
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	iconv
PORTVERSION=	${REAL_PORTVERSION}
CATEGORIES=	converters ruby
MASTER_SITES=	${REAL_MASTER_SITES}
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}

MAINTAINER=	knu@FreeBSD.org
COMMENT=	An iconv wrapper class for Ruby

USE_ICONV=	yes

USE_RUBY=	yes
USE_RUBY_EXTCONF=	yes

INSTALL_TARGET=	site-install

.include <bsd.port.pre.mk>

.if ${RUBY_VER} >= 1.7
REAL_PORTVERSION=	${RUBY_PORTVERSION}
DISTNAME=		${PORTNAME}
DISTFILES=		# empty

MAKE_ARGS+=	      sitelibdir='$$(rubylibdir)'

BUILD_DEPENDS+=	${NONEXISTENT}:${PORTSDIR}/${RUBY_PORT}:patch

do-extract:
	${MKDIR} ${WRKDIR}
	${LN} -sf `cd ${PORTSDIR}/${RUBY_PORT}; ${MAKE} -V WRKDIR`/${PORTNAME} ${WRKDIR}/

.else
REAL_PORTVERSION=	0.5
REAL_MASTER_SITES=	http://member.nifty.ne.jp/nokada/archive/
DIST_SUBDIR=		ruby

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${RUBY_MODDOCDIR}
.for f in *.html iconv.rlog rd.css
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_MODDOCDIR}/
.endfor
.endif
.endif

.include <bsd.port.post.mk>
