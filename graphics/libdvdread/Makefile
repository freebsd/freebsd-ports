# New ports collection makefile for:	libdvdread
# Date created:				24 Jun 2001
# Whom:					Marc van Woerkom <3d@freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	libdvdread
PORTVERSION=	0.9.2
CATEGORIES=	graphics
MASTER_SITES=	http://www.dtek.chalmers.se/groups/dvd/dist/

MAINTAINER=	3d@FreeBSD.org

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
INSTALLS_SHLIB=	yes

DOC_FILES=	AUTHORS NEWS README TODO

# optional CFLAGS safeness
.if !defined(WITH_OPTIMIZED_CFLAGS)
USE_AUTOCONF=	yes
EXTRA_PATCHES=	${FILESDIR}/extra-patch-configure.in
.endif

pre-everything::
.if !defined(WITH_OPTIMIZED_CFLAGS)
	@${ECHO_MSG} "====> If you want to enable optimizations, please define WITH_OPTIMIZED_CFLAGS"
.endif

post-configure:
	@${LN} -sf ${LOCALBASE}/bin/libtool ${WRKSRC}

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in ${DOC_FILES}
	@${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
