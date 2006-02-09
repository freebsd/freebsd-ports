# New ports collection makefile for:	Crystal Space 3d
# Date created:		2005-11-19
# Whom:			Jose Alonso Cardenas Marquez <acardenas@bsd.org.pe>
#
# $FreeBSD$
#

PORTNAME=	crystalspace
PORTVERSION=	0.99
PORTREVISION=	2
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	crystal
DISTNAME=	cs-pseudo-stable-2006-01-27

MAINTAINER=	acardenas@bsd.org.pe
COMMENT=	Free and portable 3D Game Development Kit

BUILD_DEPENDS=	nasm:${PORTSDIR}/devel/nasm
LIB_DEPENDS=	png.5:${PORTSDIR}/graphics/png \
		jpeg.9:${PORTSDIR}/graphics/jpeg \
		aa.1:${PORTSDIR}/graphics/aalib \
		openal.0:${PORTSDIR}/audio/openal

USE_X_PREFIX=	yes
USE_BZIP2=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
USE_GCC=	3.4+
USE_GL=		yes
LDFLAGS=	-L${LOCALBASE}/lib -L${X11BASE}/lib ${PTHREAD_LIBS}
CPPFLAGS=	-I${LOCALBASE}/include -I${X11BASE}/include
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
MAKE_ENV=	CC="${CC}" CFLAGS="${CFLAGS} ${CXX}" LDFLAGS="${LDFLAGS}" CPPFLAGS="${CPPFLAGS}"
CONFIGURE_ARGS+=	--enable-cpu-specific-optimizations=no
DOCSDIR=	share/doc/${PORTNAME}-${PORTVERSION}
WRKSRC=		${WRKDIR}/CS

OPTIONS=	DEBUG	"Build with debugging information"	on \
		PYTHON	"PYTHON interface"	on \
		PERL	"PERL interface"	on \
		LCMS	"Little Color Management System support"	on \
		MNG	"MNG/JNG graphic files support"	on \
		MIKMOD	"MIKMOD support" on \
		VORBIS	"Ogg/Vorbis sound plugin support"	on \
		3DS	"3DS files support"	on \
		ODE	"Plugin providing physics through ODE"	on \
		FREETYPE2	"FREETYPE2 support"	on \
		CAL3D	"Skeletal based 3D character animation support"	on \
		SDL	"SDL support"	on \
		CACA	"LIBCACA support"	on \
		CPPUNIT	"The C++ Unit Test Library"	on \
		BFD	"Universal BFD library from the GNU binutils"	on

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
BROKEN=		"Does not compile"
.endif

.if ${ARCH} == "sparc64"
BROKEN=		"Does not compile on sparc64"
.endif

.if !defined(WITHOUT_DEBUG)
CONFIGURE_ARGS+=	--enable-debug=yes
.else
CONFIGURE_ARGS+=	--enable-debug=no
.endif

.if !defined(WITHOUT_PYTHON)
USE_PYTHON=	yes
.include <${PORTSDIR}/Mk/bsd.python.mk>
.else
CONFIGURE_ARGS+=	--without-python
.endif

.if !defined(WITHOUT_PERL)
USE_PERL5=	yes
.else
CONFIGURE_ARGS+=	--without-perl
.endif

.if !defined(WITHOUT_LCMS)
LIB_DEPENDS+=	lcms.1:${PORTSDIR}/graphics/lcms
.else
CONFIGURE_ARGS+=	--without-lcms
.endif

.if !defined(WITHOUT_MNG)
LIB_DEPENDS+=	mng.1:${PORTSDIR}/graphics/libmng
.else
CONFIGURE_ARGS+=	--without-mng
.endif

.if !defined(WITHOUT_MIKMOD)
LIB_DEPENDS+=	mikmod.2:${PORTSDIR}/audio/libmikmod
.else
CONFIGURE_ARGS+=	--without-mikmod
.endif

.if !defined(WITHOUT_VORBIS)
LIB_DEPENDS+=	vorbis:${PORTSDIR}/audio/libvorbis
.else
CONFIGURE_ARGS+=	--without-ogg \
			--without-vorbis
.endif

.if !defined(WITHOUT_3DS)
LIB_DEPENDS+=	3ds.1:${PORTSDIR}/graphics/lib3ds
.else
CONFIGURE_ARGS+=	--without-3ds
.endif

.if !defined(WITHOUT_ODE)
BUILD_DEPENDS+=	${X11BASE}/lib/libode.a:${PORTSDIR}/devel/ode-devel
CONFIGURE_ARGS+=	--with-ode=${X11BASE}
.else
CONFIGURE_ARGS+=	--without-ode
.endif

.if !defined(WITHOUT_FREETYPE2)
LIB_DEPENDS+=	freetype.9:${PORTSDIR}/print/freetype2
.else
CONFIGURE_ARGS+=	--without-freetype2
.endif

.if !defined(WITHOUT_CAL3D)
LIB_DEPENDS+=	cal3d.11:${PORTSDIR}/graphics/cal3d-devel
.else
CONFIGURE_ARGS+=	--without-cal3d
.endif

.if !defined(WITHOUT_SDL)
USE_SDL=	sdl
.else
CONFIGURE_ARGS+=	--without-sdl
.endif

.if !defined(WITHOUT_CACA)
BUILD_DEPENDS+=	${LOCALBASE}/lib/libcaca.a:${PORTSDIR}/graphics/libcaca
.else
CONFIGURE_ARGS+=	--without-caca
.endif

.if !defined(WITHOUT_CPPUNIT)
LIB_DEPENDS+=	cppunit-1.10:${PORTSDIR}/devel/cppunit
.else
CONFIGURE_ARGS+=	--without-cppunit
.endif

.if !defined(WITHOUT_BFD)
BUILD_DEPENDS+=	${LOCALBASE}/lib/libbfd.a:${PORTSDIR}/devel/libbfd
.else
CONFIGURE_ARGS+=	--without-bfd
.endif

pre-configure:
	@${REINPLACE_CMD} -e 's,sdl-config,sdl11-config,g' ${WRKSRC}/configure

post-configure:
.if defined(NOPORTDOCS)
	@${REINPLACE_CMD} -e 42,44d ${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e 26d ${WRKSRC}/Jamfile
	@${REINPLACE_CMD} -e 79d ${WRKSRC}/Jamfile
.endif

.include <bsd.port.post.mk>
