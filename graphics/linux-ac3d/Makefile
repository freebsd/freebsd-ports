# New ports collection makefile for:	linux-ac3d
# Date created:		12 July 2002
# Whom:			Igor Pokrovsky <tiamat@comset.net>
#
# $FreeBSD$
#

PORTNAME=	ac3d
PORTVERSION=	4.0f
CATEGORIES=	graphics linux
MASTER_SITES=	http://inivis.swmirror.com/
PKGNAMEPREFIX=	linux-
DISTNAME=	${PORTNAME}lx${PORTVERSION:R}
EXTRACT_SUFX=	.tgz

MAINTAINER=	ip@doom.homeunix.org
COMMENT=	Easy to use and powerful 3D graphics modeller (trial version)

.ifdef(INSTALL_DYNLINKED_VERSION)
LIB_DEPENDS=	${LINUXBASE}/usr/X11R6/libGLU.so.1:${PORTSDIR}/graphics/linux_mesa3
.endif

USE_LINUX=	yes
NO_BUILD=	yes
ONLY_FOR_ARCHS=	i386
WRKSRC=		${WRKDIR}/${PORTNAME}lx

PKGMESSAGE=	${WRKDIR}/pkg-message

.ifndef(INSTALL_DYNLINKED_VERSION)
PLIST_SUB=	DYNAMIC_VERSION="@comment "	\
		STATIC_VERSION=""
PROGRAM=	ac3ds
.else
PLIST_SUB=	DYNAMIC_VERSION=""		\
		STATIC_VERSION="@comment "
PROGRAM=	ac3d
.endif

# Linux binary should not be stripped by INSTALL_PROGRAM
# because as a side effect it brands the binary as FreeBSD.
STRIP=

.ifndef(INSTALL_DYNLINKED_VERSION)
pre-everything::
	@${ECHO_MSG} 'Define INSTALL_DYNLINKED_VERSION=yes to install'
	@${ECHO_MSG} 'a dynamically linked (against linux MesaGL)'
	@${ECHO_MSG} 'version of the program.'
	@${ECHO_MSG} 'It may be useful with hardware accellerated MesaGL'
	@${ECHO_MSG} ''
.endif

post-patch:
	@${CAT} pkg-message | \
		${SED} -e 's|%%PORTNAME%%|${PORTNAME}|; \
			   s|%%PREFIX%%|${PREFIX}|; \
			   s|%%EXAMPLESDIR%%|${EXAMPLESDIR}|' > ${PKGMESSAGE}

pre-install:
# Generate startup script
	@${ECHO_CMD} "#!${SH}" > ${WRKDIR}/ac3d.sh
	@${ECHO_CMD} "${SETENV} AC3D_HOME=\"${DATADIR}\" \
		${PREFIX}/bin/real-${PROGRAM}" >> \
		${WRKDIR}/ac3d.sh

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/${PROGRAM} \
		${PREFIX}/bin/real-${PROGRAM}
	@${INSTALL_SCRIPT} ${WRKDIR}/ac3d.sh ${PREFIX}/bin/ac3d.sh

# Install small Tcl/Tk distribution
# Tcl/Tk, installed from ports tree will also make a job,
# but AC3D wants AC3D_HOME to point to directory with
# Tcl/Tk scripts library (which is ${LOCALBASE}/lib for version
# from ports).
# data
	@${MKDIR} ${DATADIR}
	@${MKDIR} ${DATADIR}/lib
	@${MKDIR} ${DATADIR}/lib/tcl8.4
	@${INSTALL_DATA} ${WRKSRC}/lib/tcl8.4/tclIndex ${DATADIR}/lib/tcl8.4
	@${INSTALL_DATA} ${WRKSRC}/lib/tcl8.4/*.tcl ${DATADIR}/lib/tcl8.4
	@${MKDIR} ${DATADIR}/lib/tk8.4
	@${INSTALL_DATA} ${WRKSRC}/lib/tk8.4/tclIndex ${DATADIR}/lib/tk8.4
	@${INSTALL_DATA} ${WRKSRC}/lib/tk8.4/*.tcl ${DATADIR}/lib/tk8.4
	@${MKDIR} ${DATADIR}/tcl
	@${INSTALL_DATA} ${WRKSRC}/tcl/*.tcl ${DATADIR}/tcl

# fonts
.for i in font fontwire
	${INSTALL_DATA} ${WRKSRC}/${i}.ac ${DATADIR}
.endfor

.ifndef	(NOPORTDOCS)
# docs
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/LICENCE ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/IMPORTANT ${DOCSDIR}
# examples
	@${MKDIR} ${EXAMPLESDIR}
	@${INSTALL_DATA} ${WRKSRC}/models/samples/* ${EXAMPLESDIR}
	@${CAT} ${PKGMESSAGE}
.endif

.include <bsd.port.mk>
