# New ports collection makefile for:	linux-ac3d
# Date created:		12 July 2002
# Whom:			Igor Pokrovsky <tiamat@comset.net>
#
# $FreeBSD$
#

PORTNAME=	ac3d
PORTVERSION=	6.430
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
RUN_DEPENDS+=	${LINUXBASE}/usr/lib/libGL.so.1:${PORTSDIR}/x11/nvidia-driver
USE_LINUX_APPS+=libglu
.else
USE_LINUX_APPS+=dri
.endif

RESTRICTED=	no distribution permitted

ONLY_FOR_ARCHS=	i386 amd64
# needs f8 or higher
USE_LINUX=	yes
USE_LINUX_APPS+=	jpeg png10 tiff xorglibs
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
	${MKDIR} ${DATADIR}/lib/tcl8.5
	${INSTALL_DATA} ${WRKSRC}/lib/tcl8.5/license.terms ${DATADIR}/lib/tcl8.5
	${INSTALL_DATA} ${WRKSRC}/lib/tcl8.5/tclIndex ${DATADIR}/lib/tcl8.5
	${INSTALL_DATA} ${WRKSRC}/lib/tcl8.5/*.tcl ${DATADIR}/lib/tcl8.5
	${MKDIR} ${DATADIR}/lib/tk8.5
	${INSTALL_DATA} ${WRKSRC}/lib/tk8.5/license.terms ${DATADIR}/lib/tk8.5
	${INSTALL_DATA} ${WRKSRC}/lib/tk8.5/tclIndex ${DATADIR}/lib/tk8.5
	${INSTALL_DATA} ${WRKSRC}/lib/tk8.5/*.tcl ${DATADIR}/lib/tk8.5
	${MKDIR} ${DATADIR}/lib/tk8.5/ttk
	${INSTALL_DATA} ${WRKSRC}/lib/tk8.5/ttk/*.tcl ${DATADIR}/lib/tk8.5/ttk
	${MKDIR} ${DATADIR}/tcl

.for i in tcl
	${INSTALL_DATA} ${WRKSRC}/tcl/*.${i} ${DATADIR}/tcl
.endfor

#images
	${MKDIR} ${DATADIR}/tcl/images
	${MKDIR} ${DATADIR}/tcl/images/toolbar

.for i in gif png
	${INSTALL_DATA} ${WRKSRC}/tcl/images/*.${i} ${DATADIR}/tcl/images
.endfor

.for i in png
	${INSTALL_DATA} ${WRKSRC}/tcl/images/toolbar/*.${i} ${DATADIR}/tcl/images/toolbar
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
	${MKDIR} ${EXAMPLESDIR}/SecondLife

.for i in ac tga
	${INSTALL_DATA} ${WRKSRC}/models/SecondLife/*.${i} ${EXAMPLESDIR}/SecondLife
.endfor

	${MKDIR} ${EXAMPLESDIR}/SecondLife/avatar
	${INSTALL_DATA} ${WRKSRC}/models/SecondLife/avatar/* ${EXAMPLESDIR}/SecondLife/avatar

.include <bsd.port.mk>
