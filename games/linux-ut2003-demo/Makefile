# Created by: Alejandro Pulver <alejandro@varnet.biz>
# $FreeBSD$

PORTNAME=	ut2003-demo
PORTVERSION=	2206
CATEGORIES=	games linux
MASTER_SITES=	GENTOO
PKGNAMEPREFIX=	linux-
DISTNAME=	ut2003demo-lnx-${PORTVERSION}
EXTRACT_SUFX=	.sh.bin

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Unreal Tournament 2003 demo

USE_LINUX=	yes
USE_LINUX_APPS=	sdl12 xorglibs
RESTRICTED=	Redistribution is limited, see license
NO_BUILD=	yes
NO_WRKSUBDIR=	yes

UTDIR=		${PREFIX}/lib/${PORTNAME}
UTDIR_REL=	${UTDIR:S,^${PREFIX}/,,}

PLIST=		${WRKDIR}/pkg-plist

SUB_FILES=	ut2003-demo
SUB_LIST=	UTDIR="${UTDIR}"

PLIST_FILES=	bin/ut2003-demo \
		%%DATADIR%%/UT2003Logo.bmp %%DATADIR%%/Unreal.xpm
PLIST_DIRS=	${UTDIR_REL} %%DATADIR%%
PORTDOCS=	*

LIBDIRS=	Animations Benchmark ForceFeedback KarmaData Maps Music \
		Sounds StaticMeshes System Textures Web

OPTIONS_DEFINE=	DOCS NVIDIA_GL

NVIDIA_GL_RUN_DEPENDS=	${LINUXBASE}/usr/lib/libGL.so.1:x11/nvidia-driver

.include <bsd.port.options.mk>

.if ! ${PORT_OPTIONS:MNVIDIA_GL}
USE_LINUX_APPS+=dri
.endif

do-extract:
	@${MKDIR} ${WRKSRC}
	@cd ${WRKSRC} && ${TAIL} -c +6360 ${_DISTDIR}/${DISTFILES} | ${TAR} zxf -
	@cd ${WRKSRC} && ${TAR} yxf ut2003lnx_demo.tar.bz2
	@cd ${WRKSRC} && ${TAR} zxf setupstuff.tar.gz

pre-install:
	@${RM} -f ${PLIST}
	@cd ${WRKSRC} && \
	${FIND} ${LIBDIRS} -type f | ${SORT} \
		| ${SED} -e 's|^|${UTDIR_REL}/|' >> ${PLIST}

	# This fix an error with the libSDL included in the ut2003 package
	@${ECHO_CMD} "@exec cp ${LINUXBASE}/usr/lib/libSDL-1.2.so.0 ${UTDIR}/System/" \
		>> ${PLIST}

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/ut2003-demo ${STAGEDIR}${PREFIX}/bin

	cd ${WRKSRC} && \
	${FIND} ${LIBDIRS} -type d ! -empty -exec \
		${MKDIR} "${STAGEDIR}${UTDIR}/{}" \; && \
	${FIND} ${LIBDIRS} -type f -exec \
		${INSTALL_DATA} "{}" "${STAGEDIR}${UTDIR}/{}" \;
	${CHMOD} ${BINMODE} ${STAGEDIR}${UTDIR}/Benchmark/*.sh ${STAGEDIR}${UTDIR}/System/*-bin
	${CHMOD} ${LIBMODE} ${STAGEDIR}${UTDIR}/System/*.so*
	@${MKDIR} ${STAGEDIR}${DATADIR}
.for f in Help/UT2003Logo.bmp Unreal.xpm
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${DATADIR}
.endfor
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for f in README.linux Help/ReadMe-* eula/*
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
