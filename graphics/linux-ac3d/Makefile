# New ports collection makefile for:	linux-ac3d
# Date created:		12 July 2002
# Whom:			Igor Pokrovsky <tiamat@comset.net>
#
# $FreeBSD$
#

PORTNAME=	ac3d
PORTVERSION=	6.0
CATEGORIES=	graphics linux
MASTER_SITES=	http://www.ac3d.org/ac3d/download/release6/
PKGNAMEPREFIX=	linux-
DISTNAME=	${PORTNAME}lx${PORTVERSION:R}
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Easy to use and powerful 3D graphics modeller (trial version)

RUN_DEPENDS=	${LINUXBASE}/usr/lib/libjpeg.so.62:${PORTSDIR}/graphics/linux-jpeg \
		${LINUXBASE}/usr/lib/libpng.so.2:${PORTSDIR}/graphics/linux-png10 \
		${LINUXBASE}/usr/lib/libtiff.so.3:${PORTSDIR}/graphics/linux-tiff \
		${LINUXBASE}/usr/X11R6/lib/libGLU.so.1:${PORTSDIR}/graphics/linux_dri

.ifdef(WITH_NVIDIA_GL)
RUN_DEPENDS+=	${LINUXBASE}/usr/lib/libGL.so.1:${PORTSDIR}/x11/nvidia-driver
.endif

RESTRICTED=	no distribution permitted

ONLY_FOR_ARCHS=	i386
USE_LINUX=	yes
USE_X_PREFIX=	yes
NO_BUILD=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}lx

SUB_FILES=	ac3d

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ac3d ${PREFIX}/libexec
	${INSTALL_SCRIPT} ${WRKDIR}/ac3d ${PREFIX}/bin

# Install small Tcl/Tk distribution
# Tcl/Tk, installed from ports tree will also make a job,
# but AC3D wants AC3D_HOME to point to directory with
# Tcl/Tk scripts library (which is ${LOCALBASE}/lib for version
# from ports).
# data
	${MKDIR} ${DATADIR}/lib/tcl8.4
	${INSTALL_DATA} ${WRKSRC}/lib/tcl8.4/tclIndex ${DATADIR}/lib/tcl8.4
	${INSTALL_DATA} ${WRKSRC}/lib/tcl8.4/*.tcl ${DATADIR}/lib/tcl8.4
	${MKDIR} ${DATADIR}/lib/tk8.4
	${INSTALL_DATA} ${WRKSRC}/lib/tk8.4/tclIndex ${DATADIR}/lib/tk8.4
	${INSTALL_DATA} ${WRKSRC}/lib/tk8.4/*.tcl ${DATADIR}/lib/tk8.4
	${MKDIR} ${DATADIR}/tcl
.for i in tcl xbm
	${INSTALL_DATA} ${WRKSRC}/tcl/*.${i} ${DATADIR}/tcl
.endfor

# fonts
.for i in font fontwire
	${INSTALL_DATA} ${WRKSRC}/${i}.ac ${DATADIR}
.endfor

# plugins
	${MKDIR} ${DATADIR}/plugins
	${INSTALL_PROGRAM} ${WRKSRC}/plugins/*.p ${DATADIR}/plugins
	${INSTALL_DATA} ${WRKSRC}/plugins/*.tcl ${DATADIR}/plugins

# docs
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/LICENSE ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/IMPORTANT ${DOCSDIR}
	${MKDIR} ${DOCSDIR}/manual
	${INSTALL_DATA} ${WRKSRC}/manual/*.htm[l] ${DOCSDIR}/manual
	${MKDIR} ${DOCSDIR}/manual/man_files
.for i in gif jpg
	${INSTALL_DATA} ${WRKSRC}/manual/man_files/*.${i} \
		${DOCSDIR}/manual/man_files
.endfor
	${MKDIR} ${DOCSDIR}/manual/top_files
	${INSTALL_DATA} ${WRKSRC}/manual/top_files/*.gif \
		${DOCSDIR}/manual/top_files
.endif

# examples
	${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/models/samples/* ${EXAMPLESDIR}

.include <bsd.port.mk>
