# New ports collection makefile for:	linux-ac3d
# Date created:		12 July 2002
# Whom:			Igor Pokrovsky <tiamat@telegraph.spb.ru>
#
# $FreeBSD$
#

PORTNAME=	ac3d
PORTVERSION=	3.6
CATEGORIES=	graphics linux
MASTER_SITES=	http://inivis.swmirror.com/
PKGNAMEPREFIX=	linux-
DISTNAME=	ac3d${PORTVERSION:S/.//}lx
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Easy to use and powerful 3D graphics modeller (trial version)

.ifdef(INSTALL_DYNLINKED_VERSION)
LIB_DEPENDS=	${LINUXBASE}/usr/X11R6/libGLU.so.1:${PORTSDIR}/graphics/linux_mesa3
.endif

USE_LINUX=	yes
NO_BUILD=	yes
ONLY_FOR_ARCHS=	i386
WRKSRC=		${WRKDIR}/ac3dlx

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
	@${MKDIR} ${DATADIR}/lib/tcl8.3
	@${INSTALL_DATA} ${WRKSRC}/lib/tcl8.3/tclIndex \
		${DATADIR}/lib/tcl8.3
	@${INSTALL_DATA} ${WRKSRC}/lib/tcl8.3/*.tcl ${DATADIR}/lib/tcl8.3
	@${INSTALL_DATA} ${WRKSRC}/lib/tcl8.3/license.terms \
		${DATADIR}/lib/tcl8.3
	@${MKDIR} ${DATADIR}/lib/tk8.3
	@${INSTALL_DATA} ${WRKSRC}/lib/tk8.3/tclIndex ${DATADIR}/lib/tk8.3
	@${INSTALL_DATA} ${WRKSRC}/lib/tk8.3/*.tcl ${DATADIR}/lib/tk8.3
	@${INSTALL_DATA} ${WRKSRC}/lib/tk8.3/license.terms \
		${DATADIR}/lib/tk8.3
	@${MKDIR} ${DATADIR}/tcl
	@${INSTALL_DATA} ${WRKSRC}/tcl/*.tcl ${DATADIR}/tcl
	@${INSTALL_DATA} ${WRKSRC}/font.ac ${DATADIR}
	@${INSTALL_DATA} ${WRKSRC}/fontwire.ac ${DATADIR}
.ifndef	(NOPORTDOCS)
# docs
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/LICENCE ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/IMPORTANT ${DOCSDIR}
# examples
	@${MKDIR} ${EXAMPLESDIR}
	@${INSTALL_DATA} ${WRKSRC}/models/* ${EXAMPLESDIR}
.endif

post-install:
	@${SED} -e 's|/usr/local/|${PREFIX}/|' ${PKGMESSAGE}

.include <bsd.port.mk>
