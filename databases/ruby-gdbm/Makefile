# New ports collection makefile for:	ruby-gdbm
# Date created:		24 Aug 2000
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	gdbm
PORTVERSION=	${RUBY_PORTVERSION}
PORTREVISION=	3
PORTEPOCH=	1
CATEGORIES=	databases ruby
MASTER_SITES=	# none
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTFILES=	# none

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A Ruby extension to GDBM library

BUILD_DEPENDS=	${NONEXISTENT}:${PORTSDIR}/${RUBY_PORT}:patch
LIB_DEPENDS=	gdbm.4:${PORTSDIR}/databases/gdbm

PLIST_FILES=	%%RUBY_ARCHLIBDIR%%/gdbm.so
USE_RUBY=	yes
USE_RUBY_EXTCONF=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}

.include <bsd.port.pre.mk>

MAKE_ARGS=	sitelibdir='$$(rubylibdir)'

do-extract:
	${MKDIR} ${WRKDIR}
	${LN} -sf `cd ${PORTSDIR}/${RUBY_PORT}; ${MAKE} -V WRKDIR`/${PORTNAME} ${WRKDIR}/

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
