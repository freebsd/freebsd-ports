PORTNAME=	fnccheck
PORTVERSION=	3.2.0
PORTREVISION=	5
CATEGORIES=	devel
MASTER_SITES=	SF/${PORTNAME}
DISTNAME=	FunctionCheck-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Profiling library/utilities for C/C++ programs
WWW=		https://sourceforge.net/projects/fnccheck/

LICENSE=	GPLv2 LGPL21
LICENSE_COMB=	multi

DEPRECATED=	BROKEN for more than an year and last upstream release was in 2012
EXPIRATION_DATE=	2023-11-30
BROKEN=		does not build: /usr/local/include/libiberty/libiberty.h:317:74: error: expected function body after function declarator

BUILD_DEPENDS=	gnulibiberty>=2.19.1:devel/gnulibiberty
LIB_DEPENDS=	libbfd.so:devel/libbfd

USES=		autoreconf libtool
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

CPPFLAGS+=	-I${LOCALBASE}/include
LIBS+=		-L${LOCALBASE}/lib

STRIP=		# none

INFO=		libfc

post-patch:
	@${FIND} ${WRKSRC} -name "Makefile.am" | ${XARGS} ${REINPLACE_CMD} -e \
		's|-ldl|| ; \
		 s|-Wall -O3|-Wall|'
	@${REINPLACE_CMD} -e \
		'/^SUBDIRS/s|test||' ${WRKSRC}/Makefile.am

.include <bsd.port.mk>
