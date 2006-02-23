# New ports collection makefile for:	CommonC++
# Date created:				25 July 2000
# Whom:					David Sugar <dyfet@gnu.org>
#
# $FreeBSD$
#

PORTNAME=	commoncpp2
PORTVERSION=	1.3.21
PORTREVISION=	1
PORTEPOCH=	2
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	gnutelephony

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GNU project portable class framework for C++

USE_GNOME=	gnomehack gnometarget

.if !defined(WITHOUT_LIBXML2)
USE_GNOME+=	libxml2
.else
CONFIGURE_ARGS=	--without-libxml2
.endif

USE_GETOPT_LONG=yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
USE_GCC=	3.4
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}" \
		ac_cv_path_DOXYGEN=no
INSTALLS_SHLIB=	yes

INFO=		commoncpp2

CPPFLAGS=	-I${LOCALBASE}/include ${PTHREAD_CFLAGS}
LDFLAGS=	-L${LOCALBASE}/lib ${PTHREAD_LIBS}

.include <bsd.port.mk>
