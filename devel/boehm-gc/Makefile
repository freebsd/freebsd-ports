# New ports collection makefile for:	boehm-gc
# Version required:	4.10
# Date created:		15 November 1996
# Whom:			Mike McGaughey <mmcg@cs.monash.edu.au>
#
# $Id: Makefile,v 1.3 1998/10/12 15:47:43 jseger Exp $
#

DISTNAME=	gc4.12
PKGNAME=	boehm-gc-4.12
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.parc.xerox.com/pub/gc/ \
		http://reality.sgi.com/employees/boehm_mti/gc_source/

MAINTAINER=	mmcg@cs.monash.edu.au

FETCH_BEFORE_ARGS=	-b

WRKSRC=		${WRKDIR}/gc
MAN3=		gc.3
ALL_TARGET=	FreeBSD-pkg-all
INSTALL_TARGET=	FreeBSD-pkg-install
MAKE_ENV+=	CP="${CP}"
MAKE_ENV+=	INSTALL_DATA="${INSTALL_DATA}"
MAKE_ENV+=	INSTALL_MAN="${INSTALL_MAN}"

.include <bsd.port.mk>
