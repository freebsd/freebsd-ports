# New ports collection makefile for:   fnccheck
# Date created:        22 January 2001
# Whom:                George Reid <greid@ukug.uk.freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	fnccheck
PORTVERSION=	3.2.0
CATEGORIES=	devel
MASTER_SITES=	SF/${PORTNAME}
DISTNAME=	FunctionCheck-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A profiling library/utilities for C/C++ programs

LICENSE=	GPLv2 LGPL21
LICENSE_COMB=	multi

USE_BINUTILS=	yes
USE_AUTOTOOLS=	libtoolize aclocal automake autoconf
LIBTOOLIZE_ARGS=--force
ACLOCAL_ARGS=	-I ${LOCALBASE}/share/aclocal
AUTOMAKE_ARGS=	--force-missing --add-missing --foreign
USE_LDCONFIG=	yes
MAKE_JOBS_SAFE=	yes

CPPFLAGS+=	-I${LOCALBASE}/include ${PTHREAD_CFLAGS}
LDFLAGS+=	-L${LOCALBASE}/lib ${PTHREAD_LIBS}

STRIP=		# none

INFO=		libfc

post-patch:
	@${FIND} ${WRKSRC} -name "Makefile.am" | ${XARGS} ${REINPLACE_CMD} -e \
		's|-ldl -lpthread|| ; \
		 s|-lbfd$$|-lbfd -liberty| ; \
		 s|-Wall -O3|-Wall|'
	@${REINPLACE_CMD} -e \
		'/^SUBDIRS/s|test||' ${WRKSRC}/Makefile.am

.include <bsd.port.mk>
