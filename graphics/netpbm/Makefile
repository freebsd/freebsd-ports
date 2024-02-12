PORTNAME=	netpbm
DISTVERSION=	11.04.02
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	LOCAL/leres/netpbm

MAINTAINER=	leres@FreeBSD.org
COMMENT=	Toolkit for conversion of images between different formats
WWW=		https://netpbm.sourceforge.net/

LICENSE=	GPLv2 IJG LGPL21 MIT PD
LICENSE_COMB=	multi
LICENSE_NAME_IJG=	Independent JPEG Group License
LICENSE_FILE_IJG=	${WRKSRC}/doc/copyright_summary
LICENSE_PERMS_IJG=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

LIB_DEPENDS=	libjasper.so:graphics/jasper \
		libjbig.so:graphics/jbigkit \
		libpng.so:graphics/png \
		libtiff.so:graphics/tiff

USES=		cpe gmake jpeg perl5 shebangfix tar:xz
USE_LDCONFIG=	yes
CPE_VENDOR=	netpbm_project

SVN_REV=	r4709

SHEBANG_FILES=	buildtools/makeman converter/pbm/pbmtox10bm \
		editor/pnmflip editor/pnmquant editor/ppmfade \
		editor/ppmquant editor/ppmshadow generator/ppmrainbow \
		test/*.test test/Available-Testprog test/Execute-Tests

MAKEFILE=	GNUmakefile
MAKE_ARGS=	BINMODE=${BINMODE} \
		CC=${CC} \
		DATADIR=${DATADIR} \
		DATAMODE=${_SHAREMODE} \
		DIRMODE=755 \
		MANMODE=${MANMODE} \
		pkgdir=${STAGEDIR}${PREFIX} \
		SHAREMODE=${SHAREMODE}
INSTALL_TARGET=	install.bin install.lib install.data install.hdr

OPTIONS_DEFINE=		SVGTOPAM X11
OPTIONS_SUB=		yes

SVGTOPAM_DESC=	Build svgtopam
X11_DESC=	Build pamx
SVGTOPAM_USES=	gnome
SVGTOPAM_USE=	gnome=libxml2
X11_USES=	xorg
X11_USE=	xorg=x11,xau,xcb,xdmcp

post-patch:
	${REINPLACE_CMD} -e 's|misc|share/netpbm|g' ${WRKSRC}/common.mk
.ifdef WITH_PIE
.for dn in buildtools test
	${REINPLACE_CMD} -e '/^all:/s/^/CFLAGS_FOR_BUILD+=${PIE_CFLAGS}\n/' \
	    ${WRKSRC}/${dn}/Makefile
.endfor
.endif

#
# To roll snapshot: make BOOTSTRAP= makesum
#
#.if defined(BOOTSTRAP) && !exists(${DISTDIR}/${DISTNAME}${EXTRACT_SUFX})
.if defined(BOOTSTRAP)
.if ${WITH_SUBVERSION_VER:U} == LTS
FETCH_DEPENDS+=	svn:devel/subversion-lts
.else
FETCH_DEPENDS+=	svn:devel/subversion
.endif
WRKDIR=		${WRKDIRPREFIX}${.CURDIR}/work/.bootstrap

do-fetch:
	${RM} -rf ${WRKDIR}
	${MKDIR} ${WRKDIR}
	svn export -r${SVN_REV} \
	    https://svn.code.sf.net/p/${PORTNAME}/code/advanced ${WRKSRC}
	${TAR} -jcf ${DISTDIR}/${DISTNAME}${EXTRACT_SUFX} -C${WRKDIR} \
	    ${DISTNAME}
	${RM} -rf ${WRKDIR}
.endif

# Disable building svgtopam by default.  It is the only program that
# requires libxml2 and it is not useful in this day and age according
# to the author.  See the top of converter/other/svgtopam.c for more
# details.
post-patch-SVGTOPAM-off:
	${REINPLACE_CMD} '/svgtopam/d' ${WRKSRC}/converter/other/Makefile

post-patch-X11-off:
	${REINPLACE_CMD} '/pamx/d' ${WRKSRC}/other/Makefile

do-configure:
	${CAT} ${WRKSRC}/config.mk.in ${FILESDIR}/config.mk > \
	    ${WRKSRC}/config.mk

post-install:
	cd ${STAGEDIR}${PREFIX}/lib && ${LN} -sf libnetpbm.so.11 libnetpbm.so
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libnetpbm.so
	${RM} ${STAGEDIR}${PREFIX}/bin/manweb
	${INSTALL_DATA} ${WRKSRC}/lib/util/pm_c_util.h ${WRKSRC}/pm_config.h \
	    ${STAGEDIR}${PREFIX}/include/netpbm
	${RMDIR} ${STAGEDIR}${PREFIX}/sharedlink

.include <bsd.port.mk>
