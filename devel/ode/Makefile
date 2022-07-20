PORTNAME=	ode
PORTVERSION=	0.13
PORTREVISION=	4
PORTEPOCH=	1
CATEGORIES=	devel
MASTER_SITES=	SF/opende/ODE/${PORTVERSION}

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Articulated rigid body dynamics library

LICENSE=	LGPL21 BSD3CLAUSE
LICENSE_COMB=	dual

USES=		tar:bzip2 libtool pathfix
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-shared
TEST_TARGET=	check
USE_CXXSTD=	c++03

OPTIONS_DEFINE=		GIMPACT DOUBLE OU DEMOS

GIMPACT_DESC=		Enable gimpact instead of opcode support
DOUBLE_DESC=		Enable double precision (BROKEN with GIMPACT)
OU_DESC=		Enable Thread-local storage (Experimental)
DEMOS_DESC=		Build demos (not installed)

GIMPACT_PREVENTS=	DOUBLE
GIMPACT_CONFIGURE_ON=	--with-trimesh=gimpact
GIMPACT_CONFIGURE_OFF=	--with-trimesh=opcode
DOUBLE_CONFIGURE_ENABLE=double-precision
OU_CONFIGURE_ENABLE=	ou
DEMOS_CONFIGURE_ENABLE=	demos
DEMOS_USES=		gl localbase pkgconfig
DEMOS_USE=		GL=gl,glu

post-patch:
	@${REINPLACE_CMD} -e '/if test/ s|==|=|' -e 's|^\( *CFLAGS=\)|#\1|;' \
		-e 's|^\( *CPPFLAGS=\)|#\1|' -e 's|^\( *CXXFLAGS=\)|#\1|' \
		-e 's|CPPFLAGS+=" |CPPFLAGS="$$CPPFLAGS |' \
		${WRKSRC}/configure
	@${FIND} ${WRKSRC} -type f -name Makefile.in -print0 | ${XARGS} -0 ${REINPLACE_CMD} \
		-e '/^DEFAULT_INCLUDES/ s|$$| -I$$(top_builddir)/include|' \
		-e '/CFLAGS/ s|-O[12]||'
	@${REINPLACE_CMD} 's|<malloc.h>|<stdlib.h>|g' \
		${WRKSRC}/build/config-default.h ${WRKSRC}/ou/src/ou/malloc.cpp

post-install:
	${SED} -e '/PACKAGE/ s|^|//|; /VERSION/ s|^|//|' ${WRKSRC}/ode/src/config.h \
		> ${STAGEDIR}${PREFIX}/include/ode/config.h

.include <bsd.port.mk>
