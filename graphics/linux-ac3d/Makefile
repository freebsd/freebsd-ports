# New ports collection makefile for:	linux-ac3d
# Date created:		12 July 2002
# Whom:			Igor Pokrovsky <tiamat@comset.net>
#
# $FreeBSD$
#

PORTNAME=	ac3d
PORTVERSION=	6.205
CATEGORIES=	graphics linux
MASTER_SITES=	http://www.inivis.com/ac3d/download/release6/ \
		http://freebsd.unixfreunde.de/sources/ \
		http://kwiki.dragon2.net/distfiles/
PKGNAMEPREFIX=	linux-
DISTNAME=	${PORTNAME}lx${PORTVERSION:R}${PORTVERSION:E}
EXTRACT_SUFX=	.tgz

MAINTAINER=	hernan.di.pietro@gmail.com
COMMENT=	Easy to use and powerful 3D graphics modeller (trial version)

.ifdef(WITH_NVIDIA_GL)
RUN_DEPENDS+=	${LINUXBASE}/usr/lib/libGL.so.1:${PORTSDIR}/x11/nvidia-driver \
		${LINUXBASE}/usr/X11R6/lib/libGLU.so.1:${PORTSDIR}/graphics/linux-libGLU
.else
USE_LINUX_APPS+=dri
.endif

RESTRICTED=	no distribution permitted

ONLY_FOR_ARCHS=	i386 amd64
USE_LINUX=	yes
USE_LINUX_APPS=	jpeg png10 tiff xorglibs
NO_BUILD=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}lx

SUB_FILES=	ac3d ac3ds

PORTDOCS=	*

DESKTOP_ENTRIES="AC3D" \
		"Edit 3D models" \
		"ac3d" \
		"ac3d" \
		"" \
		false

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ac3d ${PREFIX}/libexec
	${INSTALL_SCRIPT} ${WRKDIR}/ac3d ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/ac3ds ${PREFIX}/libexec
	${INSTALL_SCRIPT} ${WRKDIR}/ac3ds ${PREFIX}/bin

	${MKDIR} ${PREFIX}/share/pixmaps
	${INSTALL_DATA} ${WRKSRC}/manual/top_files/image002.png \
		${PREFIX}/share/pixmaps/ac3d.png

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

.for i in tcl
	${INSTALL_DATA} ${WRKSRC}/tcl/*.${i} ${DATADIR}/tcl
.endfor

#images
	${MKDIR} ${DATADIR}/tcl/images
.for i in gif
	${INSTALL_DATA} ${WRKSRC}/tcl/images/*.${i} ${DATADIR}/tcl/images
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
	cd ${WRKSRC} && \
		${FIND} manual -type d -exec ${MKDIR} "${DOCSDIR}/{}" \; && \
		${FIND} manual -type f -exec ${INSTALL_DATA} "{}" "${DOCSDIR}/{}" \;
.endif

# examples
	${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/models/samples/* ${EXAMPLESDIR}

.include <bsd.port.mk>
