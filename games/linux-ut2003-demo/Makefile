# New ports collection makefile for:	ut2003-demo
# Date created:				31 Aug 2005
# Whom:					Alejandro Pulver <alejandro@varnet.biz>
#
# $FreeBSD$
#

PORTNAME=	ut2003-demo
PORTVERSION=	2206
CATEGORIES=	games linux
MASTER_SITES=	${MASTER_SITE_GENTOO}
MASTER_SITE_SUBDIR=	distfiles
PKGNAMEPREFIX=	linux-
DISTNAME=	ut2003demo-lnx-${PORTVERSION}
EXTRACT_SUFX=	.sh.bin

MAINTAINER=	alepulver@FreeBSD.org
COMMENT=	Unreal Tournament 2003 demo

USE_LINUX=	yes
USE_LINUX_APPS=	xorglibs
NO_PACKAGE=	Distfile is 130MB, set FORCE_PACKAGE if you really want to build this package
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

.include <bsd.port.pre.mk>

.if defined(WITH_NVIDIA_GL)
RUN_DEPENDS+=	${LINUXBASE}/usr/lib/libGL.so.1:${PORTSDIR}/x11/nvidia-driver
.else
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
		| ${SED} -e 's|^|${UTDIR_REL}/|' >> ${PLIST} && \
	${FIND} ${LIBDIRS} -type d ! -empty | ${SORT} -r \
		| ${SED} -e 's|^|@dirrm ${UTDIR_REL}/|' >> ${PLIST}

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/ut2003-demo ${PREFIX}/bin

	cd ${WRKSRC} && \
	${FIND} ${LIBDIRS} -type d ! -empty -exec \
		${MKDIR} "${UTDIR}/{}" \; && \
	${FIND} ${LIBDIRS} -type f -exec \
		${INSTALL_DATA} "{}" "${UTDIR}/{}" \;

	-${CHOWN} ${BINOWN}:${BINGRP} ${UTDIR}/Benchmark/*.sh ${UTDIR}/System/*-bin
	${CHMOD} ${BINMODE} ${UTDIR}/Benchmark/*.sh ${UTDIR}/System/*-bin

	-${CHOWN} ${LIBOWN}:${LIBGRP} ${UTDIR}/System/*.so*
	${CHMOD} ${LIBMODE} ${UTDIR}/System/*.so*

	${MKDIR} ${DATADIR}
.for f in Help/UT2003Logo.bmp Unreal.xpm
	${INSTALL_DATA} ${WRKSRC}/${f} ${DATADIR}
.endfor

.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.  for f in README.linux Help/ReadMe-* eula/*
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.  endfor
.endif

.include <bsd.port.post.mk>
