# New ports collection makefile for:	Ruby-iconv
# Date created:		7 Aug 2000
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	iconv
PORTVERSION=	${RUBY_PORTVERSION}
PORTREVISION=	${RUBY_PORTREVISION}
PORTEPOCH=	1
CATEGORIES=	converters ruby
MASTER_SITES=	#empty
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTFILES=	# empty
DISTNAME=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An iconv wrapper class for Ruby

BUILD_DEPENDS=	${NONEXISTENT}:${PORTSDIR}/${RUBY_PORT}:patch

USE_ICONV=	yes

USE_RUBY=	yes
USE_RUBY_EXTCONF=	yes

MAKE_ARGS+=	sitelibdir='$$(rubylibdir)'

INSTALL_TARGET=	site-install

PLIST_FILES=	${RUBY_ARCHLIBDIR:S,${PREFIX},,:S,^/,,}/iconv.so

.include <bsd.port.pre.mk>

RUBY_WRKDIR!=	cd ${PORTSDIR}/${RUBY_PORT}; ${MAKE} -V WRKDIR

do-extract:
	${MKDIR} ${WRKDIR}
	${LN} -sf ${RUBY_WRKDIR}/${PORTNAME} ${WRKDIR}/

.include <bsd.port.post.mk>
