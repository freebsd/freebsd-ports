# New ports collection makefile for:	CommonC++
# Date created:				25 July 2000
# Whom:					David Sugar <dyfet@gnu.org>
#
# $FreeBSD$
#

PORTNAME=	commoncpp2
PORTVERSION=	1.2.7
PORTEPOCH=	1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	gnutelephony

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GNU project portable class framework for C++

USE_GNOME=	gnomehack gnometarget libxml2
USE_GETOPT_LONG=	yes
USE_GMAKE=	yes
USE_LIBTOOL_VER=	15
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}" \
		ac_cv_path_DOXYGEN=no
INSTALLS_SHLIB=	yes

INFO=		commoncpp2

CPPFLAGS=	-I${LOCALBASE}/include ${PTHREAD_CFLAGS}
LDFLAGS=	-L${LOCALBASE}/lib ${PTHREAD_LIBS}

.include <bsd.port.mk>
