# New ports collection makefile for:	npth
# Date Created:				2012-08-12
# Whom:					Jason E. Hale <bsdkaffee@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	npth
PORTVERSION=	0.91
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNUPG}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	bsdkaffee@gmail.com
COMMENT=	New GNU Portable Threads

LICENSE=	LGPL3 GPLv2
LICENSE_COMB=	dual

USE_BZIP2=	yes
USE_AUTOTOOLS=	libtool
GNU_CONFIGURE=	yes
CONFIGURE_ENV+=	ac_cv_search_pthread_create=""
CFLAGS+=	${PTHREAD_CFLAGS}
LDFLAGS+=	${PTHREAD_LIBS}
MAKE_JOBS_SAFE=	yes
USE_LDCONFIG=	yes

.include <bsd.port.mk>
