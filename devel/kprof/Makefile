# ex:ts=8
# Ports collection makefile for:	kprof
# Date Created:			 	24 December 2001
# Whom:					Paul Marquis <pmarquis@pobox.com>
#
# $FreeBSD$
#

PORTNAME=	kprof
PORTVERSION=	1.3.1
PORTREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	pmarquis@pobox.com
COMMENT=	A profiling tool for KDE

USE_KDELIBS_VER=	3
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	KDB2HTML=${PREFIX}/bin/kdb2html
USE_GMAKE=	yes
MAKE_ENV=	${CONFIGURE_ENV}

.include <bsd.port.mk>
