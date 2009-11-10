# New ports collection makefile for:	CommonC++
# Date created:				25 July 2000
# Whom:					David Sugar <dyfet@gnu.org>
#
# $FreeBSD$
#

PORTNAME=	commoncpp
PORTVERSION=	1.7.3
PORTEPOCH=	2
CATEGORIES=	devel
MASTER_SITES=	GNU
DISTNAME=	${PORTNAME:S/$/2/}-${PORTVERSION}

MAINTAINER=	acm@FreeBSD.org
COMMENT=	GNU project portable class framework for C++

USE_LDCONFIG=	yes
USE_GNOME=	gnomehack gnometarget
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}" \
		ac_cv_path_DOXYGEN=no

INFO=		commoncpp2

CPPFLAGS=	-I${LOCALBASE}/include ${PTHREAD_CFLAGS}
LDFLAGS=	-L${LOCALBASE}/lib ${PTHREAD_LIBS}

.include <bsd.port.mk>
