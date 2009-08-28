# Ports collection makefile for:  libmaa
# Date created:			  2008/01/26
# Whom:				  chinsan
#
# $FreeBSD$
#

PORTNAME=	libmaa
PORTVERSION=	1.1.1
PORTEPOCH=	1
CATEGORIES=	devel
MASTER_SITES=	SF/dict/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Provides a few data structures and helpful functions

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--without-local-zlib --with-cflags="${CFLAGS}" \
		--with-etcdir=${PREFIX}/etc
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
USE_GMAKE=	yes
USE_AUTOTOOLS=	libtool:22
USE_LDCONFIG=	yes

ALL_TARGET=	lib

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in COPYING.LIB README
	${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
	${INSTALL_DATA} ${WRKSRC}/doc/libmaa.600dpi.ps ${DOCSDIR}
.endif

.include <bsd.port.mk>
