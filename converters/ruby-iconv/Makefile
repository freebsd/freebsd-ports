# Created by: Akinori MUSHA aka knu <knu@idaemons.org>
# $FreeBSD$

PORTNAME=	iconv
PORTVERSION=	${RUBY_PORTVERSION}
PORTREVISION=	${RUBY_PORTREVISION}
PORTEPOCH=	1
CATEGORIES=	converters ruby
MASTER_SITES=	#empty
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTFILES=	# empty
DISTNAME=	${PORTNAME}

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	iconv wrapper class for Ruby

FETCH_DEPENDS=	${NONEXISTENT}:${PORTSDIR}/${RUBY_PORT}:patch

USES=		iconv
MAKE_ARGS=	INSTALL_PROG="${INSTALL_PROGRAM}" \
		INSTALL_DATA="${INSTALL_DATA}"

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
