# ex:ts=8
# Ports collection makefile for:	libcwd
# Date created:			Nov 10, 2003
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	libcwd
PORTVERSION=	0.99.31
PORTREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	The C++ Debugging Support Library

USE_GCC=	3.1
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-threading
USE_GMAKE=	yes
INSTALLS_SHLIB=	yes

# dirty hack
post-configure:
	@${CP} -f ${WRKSRC}/include/sys.ho ${WRKSRC}/include/sys.h

.include <bsd.port.mk>
