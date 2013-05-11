# Created by: David Yeske <dyeske@yahoo.com>
# $FreeBSD$

PORTNAME=	ode
PORTVERSION=	0.11.1
PORTEPOCH=	1
CATEGORIES=	devel
MASTER_SITES=	SF/opende/ODE/${PORTVERSION}

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Articulated rigid body dynamics library

CONFLICTS=	ode-devel-[0-9].*

USE_BZIP2=	yes
USE_GL=		yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes

CONFIGURE_ENV=	LIBS="-L${LOCALBASE}/lib"

OPTIONS_DEFINE=	GIMPACT GYROSCOPIC DOUBLE OU
OPTIONS_DEFAULT=	GYROSCOPIC
GIMPACT_DESC=		Enable gimpact instead of opcode support
GYROSCOPIC_DESC=	Configure ODE to work with gyroscopic term
DOUBLE_DESC=		Enable double precision (BROKEN with GIMPACT)
OU_DESC=		Enable Thread-local storage (Experimental)

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

.include <bsd.port.pre.mk>

.if ${ARCH} == "amd64" || ${ARCH} == "ia64"
CFLAGS+=	-fPIC -DPIC
.endif

.if ${PORT_OPTIONS:MGIMPACT) && defined(WITH_DOUBLE}
IGNORE=	currently double precision is not supported by gimpact
.endif

.if ! ${PORT_OPTIONS:MGIMPACT}
CONFIGURE_ARGS+=	--with-trimesh=opcode
.else
CONFIGURE_ARGS+=	--with-trimesh=gimpact
.endif

.if ! ${PORT_OPTIONS:MGYROSCOPIC}
CONFIGURE_ARGS+=	--disable-gyroscopic
.endif

.if ${PORT_OPTIONS:MDOUBLE}
CONFIGURE_ARGS+=	--enable-double-precision
.endif

.if ${PORT_OPTIONS:MOU}
CONFIGURE_ARGS+=	--enable-ou
.else
CONFIGURE_ARGS+=	--disable-ou
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
		> ${PREFIX}/include/ode/config.h

.include <bsd.port.post.mk>
