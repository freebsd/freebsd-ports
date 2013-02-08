# Created by George Reid <greid@ukug.uk.freebsd.org>
# $FreeBSD$

PORTNAME=	fnccheck
PORTVERSION=	3.2.0
CATEGORIES=	devel
MASTER_SITES=	SF/${PORTNAME}
DISTNAME=	FunctionCheck-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Profiling library/utilities for C/C++ programs

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

.include <bsd.port.options.mk>

# should be same as binutils
.if ${PORT_OPTIONS:MNLS}
USE_GETTEXT=	yes
LDFLAGS+=	-lintl
.endif

post-patch:
	@${FIND} ${WRKSRC} -name "Makefile.am" | ${XARGS} ${REINPLACE_CMD} -e \
		's|-ldl -lpthread|| ; \
		 s|-lbfd$$|-lbfd -liberty| ; \
		 s|-Wall -O3|-Wall|'
	@${REINPLACE_CMD} -e \
		'/^SUBDIRS/s|test||' ${WRKSRC}/Makefile.am

.include <bsd.port.mk>
