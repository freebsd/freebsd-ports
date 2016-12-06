# $FreeBSD$

PORTNAME=	openbor
PORTVERSION=	3.0.r4390
CATEGORIES=	games
MASTER_SITES=	LOCAL/jbeich \
		https://svn.code.sf.net/p/${PORTNAME}/engine/engine/:svn

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Moddable fighting game engine (aka Beats of Rage)

LICENSE=	BSD3CLAUSE

LIB_DEPENDS=	libpng.so:graphics/png \
		libvpx.so:multimedia/libvpx

USES=		dos2unix gmake pkgconfig tar:xz
USE_SDL=	gfx2
DOS2UNIX_FILES=	Makefile
MAKE_ENV=	BUILD_LINUX=1 SDKPATH="${LOCALBASE}" \
		GCC_TARGET="${CONFIGURE_TARGET:S/amd64/x86_64/}"
MAKE_ARGS=	CC="${CC}" LIBRARIES="${LOCALBASE}/lib" \
		TARGET_ARCH=${ARCH:S/i386/x86/} ARCHFLAGS="" \
		TARGET_FINAL='${TARGET}' BUILD_MMX=""
LDFLAGS+=	-Wl,--as-needed
PLIST_FILES=	bin/${PORTNAME} \
		share/pixmaps/${PORTNAME}.png
PORTDOCS=	README

DESKTOP_ENTRIES="OpenBOR" \
		"" \
		"${PORTNAME}" \
		"${PORTNAME}" \
		"Game;ArcadeGame;" \
		""

OPTIONS_DEFINE=		TREMOR
OPTIONS_DEFAULT=	${MACHINE_CPU:tu:MSOFTFP:S/SOFTFP/TREMOR/}
OPTIONS_DEFINE_i386=	MMX
OPTIONS_DEFAULT_i386=	MMX # runtime detection

MMX_BUILD_DEPENDS=	yasm:devel/yasm
MMX_MAKE_ARGS=		BUILD_MMX=1

TREMOR_LIB_DEPENDS=	libvorbisidec.so:audio/libtremor
TREMOR_MAKE_ARGS=	BUILD_TREMOR=1 BUILD_VORBIS=""
TREMOR_LIB_DEPENDS_OFF=	libvorbisfile.so:audio/libvorbis

#
# To update snapshot: make makesum BOOTSTRAP=
# Specific snapshot:  make makesum SVN_FETCH= PORTVERSION=1.0.r1234
#
.if defined(BOOTSTRAP)
# XXX SED and _MASTER_SITES_svn aren't defined yet
SED?=		/usr/bin/sed
SVN_REV!=	${SETENV} LC_ALL=C svn info \
			${MASTER_SITES:M*\:svn:S/:svn//} | \
		${SED} -n 's/^Last Changed Rev: //p'
PORTVERSION:=	${PORTVERSION:R}.r${SVN_REV}
.else
SVN_REV?=	${PORTVERSION:E:S/r//}
.endif

.if defined(BOOTSTRAP) || defined(SVN_FETCH)
FETCH_DEPENDS+=	svn:devel/subversion

do-fetch:
	${MKDIR} ${WRKDIR}
	svn export -r${SVN_REV} ${_MASTER_SITES_svn} ${WRKSRC}
	(cd ${WRKDIR} && ${TAR} cJvf \
		${_DISTDIR}/${DISTNAME}${EXTRACT_SUFX} \
		--uid 0 --gid 0 ${DISTNAME})
	${REINPLACE_CMD} -i '' '/^PORTVERSION=/s/r.*/r${SVN_REV}/' \
		${MASTERDIR}/Makefile
. if ${USER} == ${MAINTAINER:C/@.*//}
	-scp ${_DISTDIR}/${DISTNAME}${EXTRACT_SUFX} \
		freefall.freebsd.org:public_distfiles/
. endif
.endif

post-patch:
	@${REINPLACE_CMD} -e 's/ -O[0-9]//; s/ -g//; s/ -Werror//' \
		-e 's/ -fomit-frame-pointer//' \
		-e 's/ -freorder-blocks//' \
		-e 's/ -Wno-unused-result//' \
		-e 's/ -Wl,-rpath,$$(LIBRARIES)//' \
		-e '/echo/!s/	@/	/' \
		-e 's/$$(LIBS)/$$(LDFLAGS) &/' \
		${WRKSRC}/Makefile
	@${GREP} -Flr 'malloc.h' ${WRKSRC} | ${XARGS} ${REINPLACE_CMD} \
		's,malloc\.h,stdlib.h,'
	@${REINPLACE_CMD} -e 's/^function \(.*\) {/\1() {/' \
		-e 's/^get_revnum/VERSION_BUILD=${SVN_REV}/' \
		${WRKSRC}/version.sh

do-configure:
	(cd ${WRKSRC} && ${SH} ./version.sh)

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/OpenBOR.elf \
		${STAGEDIR}${PREFIX}/bin/${PORTNAME}
	${INSTALL_DATA} ${WRKSRC}/resources/OpenBOR_Icon_128x128.png \
		${STAGEDIR}${PREFIX}/share/pixmaps/${PORTNAME}.png
	(cd ${WRKSRC} && ${COPYTREE_SHARE} \
		"${PORTDOCS}" ${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
