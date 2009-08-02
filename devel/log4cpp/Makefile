# ex:ts=8
# New ports collection makefile for:	log4cpp
# Date created:			May 1, 2001
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	log4cpp
DISTVERSION=	1.0
CATEGORIES=	devel
MASTER_SITES=	SF

MAINTAINER=	clsung@FreeBSD.org
COMMENT=	A library of C++ classes for flexible logging

USE_AUTOTOOLS=	libtool:22
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="${PTHREAD_CFLAGS}" LDFLAGS="${PTHREAD_LIBS}"
CONFIGURE_ARGS=	--with-pthreads --disable-html-docs
USE_LDCONFIG=	yes

.include "Makefile.man"
.include <bsd.port.pre.mk>

.if exists (${LOCALBASE}/bin/doxygen) || !defined (NOPORTDOCS)
BUILD_DEPENDS+=	doxygen:${PORTSDIR}/devel/doxygen
.else
NOPORTDOCS=		true
CONFIGURE_ARGS+=	--disable-doxygen
.endif

.if !exists (${LOCALBASE}/bin/doxygen) && !defined (NOPORTDOCS)
pre-everything::
	@${ECHO_CMD}
	@${ECHO_CMD} By default, this port uses doxygen to build its documentation.\
It currently is not present your system, and if you do not want to install it, abort\
this build by hitting CTRL+C and re-run the installation with -DNOPORTDOCS | ${FMT} 74
	@${ECHO_CMD}
	@sleep 3
.endif

post-patch:
	@${REINPLACE_CMD} -e 's| -pedantic||g' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|(libdir)/pkgconfig|(prefix)/libdata/pkgconfig|' ${WRKSRC}/Makefile.in

.include <bsd.port.post.mk>
