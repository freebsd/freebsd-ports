# New ports collection makefile for:	cmucl-extra
# Date created:				13 June 2002
# Whom:					Scott Flatman <sf@dsinw.com>
#
# $FreeBSD$

PORTNAME=	cmucl-extra
PORTVERSION=	19a
CATEGORIES=	lang
MASTER_SITES=	ftp://ftp.common-lisp.net/pub/project/cmucl/release/19a/ \
		http://www.pmsf.de/pub/cmucl/release/19a/ \
		ftp://ftp.averillpark.net/cmucl/release/19a/ \
		ftp://ftp.linux.org.uk/pub/lisp/cmucl/release/19a/ \
		ftp://ftp.tepus.com/pub/project/cmucl/release/19a/
DISTNAME=	cmucl-19a-x86-FreeBSD.extra
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
	cd ${WRKDIR} && ${FIND} lib | \
		${CPIO} -pdm -L -R ${LIBOWN}:${LIBGRP} ${PREFIX}

.include <bsd.port.post.mk>
