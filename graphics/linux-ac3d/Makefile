# New ports collection makefile for:	linux-ac3d
# Date created:		12 July 2002
# Whom:			Igor Pokrovsky <tiamat@comset.net>
#
# $FreeBSD$
#

PORTNAME=	ac3d
PORTVERSION=	5.0.21
CATEGORIES=	graphics linux
MASTER_SITES=	http://inivis.swmirror.com/
PKGNAMEPREFIX=	linux-
DISTNAME=	${PORTNAME}lx${PORTVERSION:S/.//g}
EXTRACT_SUFX=	.tgz

MAINTAINER=	ip@doom.homeunix.org
COMMENT=	Easy to use and powerful 3D graphics modeller (trial version)

.ifdef(INSTALL_DYNLINKED_VERSION)
LIB_DEPENDS=	${LINUXBASE}/usr/libGLU.so.1:${PORTSDIR}/graphics/linux_mesa3
.endif
RUN_DEPENDS=	${LINUXBASE}/usr/X11R6/lib/libXrender.so.1:${PORTSDIR}/x11/linux-XFree86-libs \
		${LINUXBASE}/usr/lib/libjpeg.so.62:${PORTSDIR}/graphics/linux-jpeg \
		${LINUXBASE}/usr/lib/libpng.so.2:${PORTSDIR}/graphics/linux-png10 \
		${LINUXBASE}/usr/lib/libtiff.so.3:${PORTSDIR}/graphics/linux-tiff

RESTRICTED=	"no distribution permitted"
NO_CDROM=	${RESTRICTED}

NO_BUILD=	yes
ONLY_FOR_ARCHS=	i386
WRKSRC=		${WRKDIR}/${PORTNAME}lx

SUB_FILES=	pkg-message
SUB_LIST=	PORTNAME="${PORTNAME}"

.ifndef(INSTALL_DYNLINKED_VERSION)
PLIST_SUB=	DYNAMIC_VERSION="@comment "	\
		STATIC_VERSION=""
PROGRAM=	${PORTNAME}s
.else
PLIST_SUB=	DYNAMIC_VERSION=""		\
		STATIC_VERSION="@comment "
PROGRAM=	${PORTNAME}
.endif

# Linux binary should not be stripped by INSTALL_PROGRAM
# because as a side effect it brands the binary as FreeBSD.
STRIP=

.ifndef(INSTALL_DYNLINKED_VERSION)
pre-everything::
	@${ECHO_MSG} 'Define INSTALL_DYNLINKED_VERSION=yes to install'
	@${ECHO_MSG} 'a dynamically linked (against linux MesaGL)'
	@${ECHO_MSG} 'version of the program.'
	@${ECHO_MSG} 'It may be useful with hardware accelerated MesaGL.'
	@${ECHO_MSG} ''
.endif

pre-install:
# Generate startup script
	@${ECHO_CMD} "#!${SH}" > ${WRKDIR}/${PORTNAME}.sh
	@${ECHO_CMD} "${SETENV} AC3D_HOME=\"${DATADIR}\" \
		${PREFIX}/bin/real-${PROGRAM}" >> \
		${WRKDIR}/${PORTNAME}.sh

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PROGRAM} \
		${PREFIX}/bin/real-${PROGRAM}
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME}.sh ${PREFIX}/bin

# Install small Tcl/Tk distribution
# Tcl/Tk, installed from ports tree will also make a job,
# but AC3D wants AC3D_HOME to point to directory with
# Tcl/Tk scripts library (which is ${LOCALBASE}/lib for version
# from ports).
# data
	@${MKDIR} ${DATADIR}
	@${MKDIR} ${DATADIR}/lib
	@${MKDIR} ${DATADIR}/lib/tcl8.4
	${INSTALL_DATA} ${WRKSRC}/lib/tcl8.4/tclIndex ${DATADIR}/lib/tcl8.4
	${INSTALL_DATA} ${WRKSRC}/lib/tcl8.4/*.tcl ${DATADIR}/lib/tcl8.4
	@${MKDIR} ${DATADIR}/lib/tk8.4
	${INSTALL_DATA} ${WRKSRC}/lib/tk8.4/tclIndex ${DATADIR}/lib/tk8.4
	${INSTALL_DATA} ${WRKSRC}/lib/tk8.4/*.tcl ${DATADIR}/lib/tk8.4
	@${MKDIR} ${DATADIR}/tcl
.for i in tcl xbm
	${INSTALL_DATA} ${WRKSRC}/tcl/*.${i} ${DATADIR}/tcl
.endfor

# fonts
.for i in font fontwire
	${INSTALL_DATA} ${WRKSRC}/${i}.ac ${DATADIR}
.endfor

# plugins
	@${MKDIR} ${DATADIR}/plugins
	${INSTALL_PROGRAM} ${WRKSRC}/plugins/*.p ${DATADIR}/plugins
	${INSTALL_DATA} ${WRKSRC}/plugins/*.tcl ${DATADIR}/plugins

.ifndef	(NOPORTDOCS)
# docs
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/LICENCE ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/IMPORTANT ${DOCSDIR}
	@${MKDIR} ${DOCSDIR}/manual
	${INSTALL_DATA} ${WRKSRC}/manual/*.htm ${DOCSDIR}/manual
	@${MKDIR} ${DOCSDIR}/manual/main_files
.for i in gif jpg png
	${INSTALL_DATA} ${WRKSRC}/manual/main_files/*.${i} \
		${DOCSDIR}/manual/main_files
.endfor
	@${MKDIR} ${DOCSDIR}/manual/top_files
	${INSTALL_DATA} ${WRKSRC}/manual/top_files/*.png \
		${DOCSDIR}/manual/top_files
# examples
	@${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/models/samples/* ${EXAMPLESDIR}
.endif

	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
