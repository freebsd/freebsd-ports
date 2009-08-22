# New ports collection makefile for:	ode
# Date created:				11 Oct 2003
# Whom:					David Yeske <dyeske@yahoo.com>
#
# $FreeBSD$
#

PORTNAME=	ode
PORTVERSION=	0.11
PORTEPOCH=	1
CATEGORIES=	devel
MASTER_SITES=	SF/opende/ODE/${PORTVERSION}
DISTNAME=	${PORTNAME}-${PORTVERSION}

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Articulated rigid body dynamics library

CONFLICTS=	ode-devel-[0-9].*

USE_BZIP2=	yes
USE_GL=		yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes

CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib"

OPTIONS=	GIMPACT	"Enable gimpact instead of opcode support" off \
		GYROSCOPIC "Configure ODE to work with gyroscopic term" on \
		DOUBLE  "Enable double precision (BROKEN with GIMPACT)" off \
		OU	"Enable Thread-local storage (Experimental)" off

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

.include <bsd.port.pre.mk>

.if ${ARCH} == "amd64" || ${ARCH} == "ia64"
CFLAGS+=	-fPIC -DPIC
.endif

.if defined(WITH_GIMPACT) && defined(WITH_DOUBLE)
IGNORE=	currently double precision is not supported by gimpact
.endif

.if !defined(WITH_GIMPACT)
CONFIGURE_ARGS+=	--with-trimesh=opcode
.else
CONFIGURE_ARGS+=	--with-trimesh=gimpact
.endif

.if defined(WITHOUT_GYROSCOPIC)
CONFIGURE_ARGS+=	--disable-gyroscopic
.endif

.if defined(WITH_DOUBLE)
CONFIGURE_ARGS+=	--enable-double-precision
.endif

.if defined(WITH_OU)
CONFIGURE_ARGS+=	--enable-ou
.else
CONFIGURE_ARGS+=	--disable-ou
.endif

post-patch:
	@${REINPLACE_CMD} -e '/if test/ s|==|=|' -e 's|^\( *CFLAGS=\)|#\1|;' \
		-e 's|^\( *CPPFLAGS=\)|#\1|' -e 's|^\( *CXXFLAGS=\)|#\1|' \
		${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|__isnanf||g; s|__isnan||g' -e 's|-lpthread|${PTHREAD_LIBS}|g' \
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
