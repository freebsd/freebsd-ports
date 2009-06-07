# New ports collection makefile for:	ut2004-demo
# Date created:			31 Mar 2005
# Whom:				Jean-Yves Lefort <jylefort@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	ut2004-demo
PORTVERSION=	3334
CATEGORIES=	games linux
MASTER_SITES=	${MASTER_SITE_GENTOO} \
		http://ftp.games.skynet.be/pub/misc/
MASTER_SITE_SUBDIR=	distfiles		# for MASTER_SITE_GENTOO
PKGNAMEPREFIX=	linux-
DISTNAME=	ut2004-lnx-demo${PORTVERSION}
EXTRACT_SUFX=	.run

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Unreal Tournament 2004 demo

ONLY_FOR_ARCHS=	i386 amd64
USE_LINUX=	yes
USE_LINUX_APPS=	xorglibs
NO_PACKAGE=	Distfile size is 275MB, set FORCE_PACKAGE if you really want to build this package
RESTRICTED=	Redistribution is limited, see license
NO_BUILD=	yes
NO_WRKSUBDIR=	yes

UTDIR=		${PREFIX}/lib/${PORTNAME}
UTDIR_REL=	${UTDIR:S,^${PREFIX}/,,}

PLIST=		${WRKDIR}/pkg-plist

SUB_FILES=	ut2004-demo
SUB_LIST=	UTDIR="${UTDIR}"

PLIST_FILES=	bin/ut2004-demo \
		%%DATADIR%%/UT2004Logo.bmp %%DATADIR%%/ut2004.xpm
PLIST_DIRS=	${UTDIR_REL} %%DATADIR%%
PORTDOCS=	*

LIBDIRS=	Animations Benchmark ForceFeedback KarmaData Maps Music \
		Sounds Speech StaticMeshes System Textures Web

.include <bsd.port.pre.mk>

.if defined(WITH_NVIDIA_GL)
RUN_DEPENDS+=	${LINUXBASE}/usr/lib/libGL.so.1:${PORTSDIR}/x11/nvidia-driver
.else
USE_LINUX_APPS+=dri
.endif

do-extract:
	@${MKDIR} ${WRKSRC}
	@cd ${WRKSRC} && ${TAIL} -c +8664 ${_DISTDIR}/${DISTFILES} | ${TAR} zxf -
.for f in linux-x86.tar.bz2 ut2004demo.tar.bz2
	@cd ${WRKSRC} && ${TAR} yxf ${f}
.endfor
	@cd ${WRKSRC} && ${TAR} zxf setupstuff.tar.gz

pre-install:
	@${RM} -f ${PLIST}
	@cd ${WRKSRC} && \
	${FIND} ${LIBDIRS} -type f | ${SORT} \
		| ${SED} -e 's|^|${UTDIR_REL}/|' >> ${PLIST} && \
	${FIND} ${LIBDIRS} -type d ! -empty | ${SORT} -r \
		| ${SED} -e 's|^|@dirrm ${UTDIR_REL}/|' >> ${PLIST}

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/ut2004-demo ${PREFIX}/bin

	cd ${WRKSRC} && \
	${FIND} ${LIBDIRS} -type d ! -empty -exec \
		${MKDIR} "${UTDIR}/{}" \; && \
	${FIND} ${LIBDIRS} -type f -exec \
		${INSTALL_DATA} "{}" "${UTDIR}/{}" \;

	-${CHOWN} ${BINOWN}:${BINGRP} ${UTDIR}/System/*-bin
	${CHMOD} ${BINMODE} ${UTDIR}/System/*-bin

	-${CHOWN} ${LIBOWN}:${LIBGRP} ${UTDIR}/System/*.so*
	${CHMOD} ${LIBMODE} ${UTDIR}/System/*.so*

	${MKDIR} ${DATADIR}
.for f in Help/UT2004Logo.bmp ut2004.xpm
	${INSTALL_DATA} ${WRKSRC}/${f} ${DATADIR}
.endfor

.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for f in Help/Manual.pdf README.linux
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.post.mk>
