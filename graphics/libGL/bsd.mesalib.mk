# bsd.mesalib.mk - shared code between MesaLib ports.
#
# !!! Here be dragons !!! (they seem to be everywhere these days)
#
# Remember to upgrade the following ports everytime you bump MESAVERSION:
#
#    - graphics/libEGL
#    - graphics/libGL
#    - grahpics/libglesv2
#    - graphics/dri
#
# $FreeBSD$

.MAKE.FreeBSD_UL=	yes

MESAVERSION=	${MESABASEVERSION}${MESASUBVERSION:C/^(.)/.\1/}
MESADISTVERSION=${MESABASEVERSION}${MESASUBVERSION:C/^(.)/-\1/}

.if defined(WITH_NEW_XORG)
MESABASEVERSION=	9.1.7
# if there is a subversion, include the '-' between 7.11-rc2 for example.
MESASUBVERSION=		
PLIST_SUB+=	OLD="@comment " NEW=""
.else
MESABASEVERSION=	7.6.1
MESASUBVERSION=		
PLIST_SUB+=	OLD="" NEW="@comment "
.endif

MASTER_SITES=	ftp://ftp.freedesktop.org/pub/mesa/${MESABASEVERSION}/
DISTFILES=	MesaLib-${MESADISTVERSION}${EXTRACT_SUFX}
MAINTAINER?=	x11@FreeBSD.org

BUILD_DEPENDS+=	makedepend:${PORTSDIR}/devel/makedepend \
		python2:${PORTSDIR}/lang/python2 \
		${PYTHON_SITELIBDIR}/libxml2.py:${PORTSDIR}/textproc/py-libxml2

USES=		bison gmake pathfix pkgconfig shebangfix
USE_PYTHON_BUILD=-2.7
USE_BZIP2=	yes
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

.if ${OSVERSION} < 1000033
BUILD_DEPENDS+=	${LOCALBASE}/bin/flex:${PORTSDIR}/textproc/flex
CONFIGURE_ENV+=ac_cv_prog_LEX=${LOCALBASE}/bin/flex
.endif

.if defined(WITH_NEW_XORG)
USE_AUTOTOOLS=	autoconf:env automake:env libtool:env
# probably be shared lib, and in it own port.
CONFIGURE_ARGS+=        --enable-shared-glapi=no
# we need to reapply these patches because we doing wierd stuff with autogen
REAPPLY_PATCHES= \
		${PATCHDIR}/patch-configure \
		${PATCHDIR}/patch-src_egl_main_Makefile.in \
		${PATCHDIR}/patch-src_glx_Makefile.in \
		${PATCHDIR}/patch-src_mapi_es2api_Makefile.in \
		${PATCHDIR}/patch-src_mapi_shared-glapi_Makefile.in \
		${PATCHDIR}/patch-src_mesa_drivers_dri_common_Makefile.in \
		${PATCHDIR}/patch-src_mesa_drivers_dri_common_xmlpool_Makefile.in \
		${PATCHDIR}/patch-src_mesa_libdricore_Makefile.in

python_OLD_CMD=	"/usr/bin/env[[:space:]]python"
python_CMD=	${LOCALBASE}/bin/python2
SHEBANG_FILES=	src/gallium/*/*/*.py src/gallium/tools/trace/*.py \
		src/gallium/drivers/svga/svgadump/svga_dump.py \
		src/glsl/tests/compare_ir src/mapi/glapi/gen/*.py \
		src/mapi/mapi/mapi_abi.py
.else
CONFIGURE_ARGS+=--disable-glut --disable-glw --disable-glu

ALL_TARGET=		default
.endif

MASTERDIR=		${.CURDIR}/../../graphics/libGL
.if defined(WITH_NEW_XORG)
PATCHDIR=		${MASTERDIR}/files
.else
PATCHDIR=		${MASTERDIR}/files-old
.endif
DESCR=			${.CURDIR}/pkg-descr
PLIST=			${.CURDIR}/pkg-plist
WRKSRC=			${WRKDIR}/Mesa-${MESADISTVERSION}

COMPONENT=		${PORTNAME:L:C/^lib//:C/mesa-//}

.if ${COMPONENT:Mglesv2} == ""
CONFIGURE_ARGS+=	--disable-gles2
.else
CONFIGURE_ARGS+=	--enable-gles2
.endif

.if ${COMPONENT:Megl} == ""
CONFIGURE_ARGS+=	--disable-egl
.else
CONFIGURE_ARGS+=	--enable-egl
.endif

.if ${COMPONENT:Mdri} == ""
CONFIGURE_ARGS+=--with-dri-drivers=no
CONFIGURE_ARGS+=--enable-gallium-llvm=no --without-gallium-drivers
.else
# done in the dri port
.endif

.if !defined(WITH_NEW_XORG)
.if defined(WITHOUT_XCB)
CONFIGURE_ARGS+=	--disable-xcb
.else
CONFIGURE_ARGS+=	--enable-xcb
.endif
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|-ffast-math|${FAST_MATH}|' -e 's|x86_64|amd64|' \
		${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|/etc/|${PREFIX}/etc/|g' \
		${WRKSRC}/src/mesa/drivers/dri/common/xmlconfig.c
.if !defined(WITH_NEW_XORG)
	@${REINPLACE_CMD} -e 's|python|${PYTHON_CMD}|' \
		${WRKSRC}/src/gallium/auxiliary/util/Makefile
	@${REINPLACE_CMD} -e 's|[$$](INSTALL_LIB_DIR)/pkgconfig|${PREFIX}/libdata/pkgconfig|' \
		${WRKSRC}/src/glu/Makefile \
		${WRKSRC}/src/mesa/Makefile \
		${WRKSRC}/src/mesa/drivers/dri/Makefile
.else
	@${REINPLACE_CMD} -e 's|#!/use/bin/python|#!${LOCALBASE}/bin/python2|g' \
		${WRKSRC}/src/mesa/drivers/dri/common/xmlpool/gen_xmlpool.py \
		${WRKSRC}/src/glsl/builtins/tools/*.py
	@${REINPLACE_CMD} -e 's|!/use/bin/python2|!${LOCALBASE}/bin/python2|g' \
		${WRKSRC}/src/mesa/main/get_hash_generator.py \
		${WRKSRC}/src/mapi/glapi/gen/gl_enums.py \
		${WRKSRC}/src/mapi/glapi/gen/gl_table.py \

.endif

pre-configure:
# workaround for stupid rerunning configure in do-build step
# xxx
.if defined(WITH_NEW_XORG)
	cd ${WRKSRC} && env NOCONFIGURE=1 sh autogen.sh
. for file in ${REAPPLY_PATCHES}
	@cd ${WRKSRC} && ${PATCH} -p0 --quiet  < ${file}
. endfor
# make sure the pkg-config files are installed in the correct place.
# this was reverted by running autogen.sh
	@${FIND} ${WRKSRC} -name Makefile.in -type f | ${XARGS} ${REINPLACE_CMD} -e \
		's|[(]libdir[)]/pkgconfig|(prefix)/libdata/pkgconfig|g' ;
.endif

