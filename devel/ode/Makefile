# Created by: David Yeske <dyeske@yahoo.com>
# $FreeBSD$

PORTNAME=	ode
PORTVERSION=	0.11.1
PORTREVISION=	2
PORTEPOCH=	1
CATEGORIES=	devel
MASTER_SITES=	SF/opende/ODE/${PORTVERSION}

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Articulated rigid body dynamics library

LICENSE=	LGPL21 BSD3CLAUSE
LICENSE_COMB=	dual

USES=		tar:bzip2 gmake libtool
USE_GL=		yes
GNU_CONFIGURE=	yes

OPTIONS_DEFINE=		GIMPACT GYROSCOPIC DOUBLE OU
OPTIONS_DEFAULT=	GYROSCOPIC

GIMPACT_DESC=		Enable gimpact instead of opcode support
GYROSCOPIC_DESC=	Configure ODE to work with gyroscopic term
DOUBLE_DESC=		Enable double precision (BROKEN with GIMPACT)
OU_DESC=		Enable Thread-local storage (Experimental)

GIMPACT_CONFIGURE_ON=	--with-trimesh=gimpact
GIMPACT_CONFIGURE_OFF=	--with-trimesh=opcode
GYROSCOPIC_CONFIGURE_ENABLE=	gyroscopic
DOUBLE_CONFIGURE_ENABLE=	double-precision
OU_CONFIGURE_ENABLE=		ou

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

.include <bsd.port.pre.mk>

.if ${ARCH} == "amd64" || ${ARCH} == "ia64"
CFLAGS+=	-fPIC -DPIC
.endif

.if ${PORT_OPTIONS:MGIMPACT} && ${PORT_OPTIONS:MDOUBLE}
IGNORE=		currently double precision is not supported by gimpact
.endif

post-patch:
	@${REINPLACE_CMD} -e '/if test/ s|==|=|' -e 's|^\( *CFLAGS=\)|#\1|;' \
		-e 's|^\( *CPPFLAGS=\)|#\1|' -e 's|^\( *CXXFLAGS=\)|#\1|' \
		-e 's|CPPFLAGS+=" |CPPFLAGS="$$CPPFLAGS |' \
		${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|__isnanf||g; s|__isnan||g' \
		${WRKSRC}/configure
	@${REINPLACE_CMD} -e '/^traplib_PROGRAMS / d' ${WRKSRC}/ode/src/Makefile.in
	@${FIND} ${WRKSRC} -type f -name Makefile.in -print0 | ${XARGS} -0 ${REINPLACE_CMD} \
		-e '/^DEFAULT_INCLUDES/ s|$$| -I$$(top_builddir)/include|' \
		-e '/CFLAGS/ s|-O[12]||'
	@${FIND} ${WRKSRC} -type f -print0 | ${XARGS} -0 ${REINPLACE_CMD} \
		-i "" -e 's|malloc.h|stdlib.h|g'

post-install:
	${SED} -e '/PACKAGE/ s|^|//|; /VERSION/ s|^|//|' ${WRKSRC}/ode/src/config.h \
		> ${STAGEDIR}${PREFIX}/include/ode/config.h

.include <bsd.port.post.mk>
