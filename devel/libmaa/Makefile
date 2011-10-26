# Ports collection makefile for:  libmaa
# Date created:			  2008/01/26
# Whom:				  chinsan
#
# $FreeBSD$
#

PORTNAME=	libmaa
PORTVERSION=	1.3.1
PORTEPOCH=	1
CATEGORIES=	devel
MASTER_SITES=	SF/dict/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Provides a few data structures and helpful functions

ALL_TARGET=	lib
CONFIGURE_ARGS=	--without-local-zlib --with-cflags="${CFLAGS}" \
		--with-etcdir=${PREFIX}/etc
CPPFLAGS+=	-I${LOCALBASE}/include
GNU_CONFIGURE=	yes
LDFLAGS+=	-L${LOCALBASE}/lib
USE_AUTOTOOLS=	libtool
USE_GMAKE=	yes
USE_LDCONFIG=	yes

DOCS=		COPYING.LIB README doc/libmaa.600dpi.ps
PLIST_FILES=	include/maa.h \
		lib/libmaa.a \
		lib/libmaa.la \
		lib/libmaa.so \
		lib/libmaa.so.3
PORTDOCS=	${DOCS:T}

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}/
	@cd ${WRKSRC} && ${INSTALL_DATA} ${DOCS} ${DOCSDIR}/
.endif

.include <bsd.port.mk>
