# New ports collection makefile for:	cmucl-extra
# Date created:				13 June 2002
# Whom:					Scott Flatman <sf@dsinw.com>
#
# $FreeBSD$

PORTNAME=       cmucl-extra
PORTVERSION=    18d
CATEGORIES=     lang
MASTER_SITES=   ftp://cvs2.cons.org/pub/lisp/cmucl/release/18d/ \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=     cracauer
DISTNAME=       cmucl-18d-x86-FreeBSD.extra

MAINTAINER=     sf@dsinw.com

USE_BZIP2=	yes
NO_WRKSUBDIR=   yes
NO_BUILD=       yes

do-install:
	-${MKDIR} ${PREFIX}/lib/cmucl
	(cd ${WRKDIR} && tar fc - lib) | (cd ${PREFIX} && tar fx -)

.include <bsd.port.mk>
