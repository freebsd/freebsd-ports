# New ports collection makefile for:	cmucl-extra
# Date created:				13 June 2002
# Whom:					Scott Flatman <sf@dsinw.com>
#
# $FreeBSD$

PORTNAME=	cmucl-extra
PORTVERSION=	18e
CATEGORIES=	lang
MASTER_SITES=	ftp://cmucl.cons.org/pub/lisp/cmucl/release/18e/ \
		${MASTER_SITE_LOCAL}
DISTNAME=	cmucl-18e-x86-freebsd.extra
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	sf@slappy.org
COMMENT=	Optional extras for the CMU implementation of Common Lisp

BUILD_DEPENDS=	lisp:${PORTSDIR}/lang/cmucl

ONLY_FOR_ARCHS=	i386
USE_BZIP2=	yes
NO_WRKSUBDIR=	yes
NO_BUILD=	yes

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 500000
LIB_DEPENDS+=	c.4:${PORTSDIR}/misc/compat4x
.endif

do-install:
	-${MKDIR} ${PREFIX}/lib/cmucl
	(cd ${WRKDIR} && tar fc - lib) | (cd ${PREFIX} && tar fx -)

.include <bsd.port.post.mk>
