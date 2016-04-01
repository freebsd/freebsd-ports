# $FreeBSD$

PORTNAME=	fnccheck
PORTVERSION=	3.2.0
PORTREVISION=	3
CATEGORIES=	devel
MASTER_SITES=	SF/${PORTNAME}
DISTNAME=	FunctionCheck-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Profiling library/utilities for C/C++ programs

LICENSE=	GPLv2 LGPL21
LICENSE_COMB=	multi

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
