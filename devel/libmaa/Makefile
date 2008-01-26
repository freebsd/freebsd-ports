# Ports collection makefile for:  libmaa
# Date created:			  2008/01/26
# Whom:				  chinsan
#
# $FreeBSD$
#

PORTNAME=	libmaa
PORTVERSION=	1.10.10
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	dict
DISTNAME=	dictd-${PORTVERSION}

MAINTAINER=	chinsan@FreeBSD.org
COMMENT=	Provides a few data structures and helpful functions

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--without-local-zlib --with-cflags="${CFLAGS}" \
		--with-etcdir=${PREFIX}/etc
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
USE_GMAKE=	yes
USE_AUTOTOOLS=	libtool:15
USE_LDCONFIG=	yes

WRKSRC=		${WRKDIR}/dictd-${PORTVERSION}/libmaa
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
