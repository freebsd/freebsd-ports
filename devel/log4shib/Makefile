# ex:ts=8
# New ports collection makefile for:	log4shib
# Date created:				Feb 13 2008
# Whom:					vanilla
#
# $FreeBSD$
#

PORTNAME=	log4shib
DISTVERSION=	1.0.4
CATEGORIES=	devel
MASTER_SITES=	http://shibboleth.internet2.edu/downloads/${PORTNAME}/${DISTVERSION}/

MAINTAINER=	vanilla@FreeBSD.org
COMMENT=	A library of C++ classes for flexible logging

USE_AUTOTOOLS=	libtool:22
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
USE_GNOME=	pkgconfig gnometarget gnomehack
CONFIGURE_ENV=	CPPFLAGS="${PTHREAD_CFLAGS}" LDFLAGS="${PTHREAD_LIBS}"
CONFIGURE_ARGS=	--with-pthreads --disable-html-docs --disable-doxygen
USE_LDCONFIG=	yes

post-patch:
	@${REINPLACE_CMD} -e 's| -pedantic||g' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|(libdir)/pkgconfig|(prefix)/libdata/pkgconfig|' ${WRKSRC}/Makefile.in

.include <bsd.port.mk>
