# New ports collection makefile for:	renderpark
# Date created:		24 July 2002
# Whom:			Igor Pokrovsky <tiamat@telegraph.spb.ru>
#
# $FreeBSD$
#

PORTNAME=	renderpark
PORTVERSION=	3.3
PORTREVISION=	2
CATEGORIES=	graphics
MASTER_SITES=	ftp://ftp.cs.kuleuven.ac.be/pub/graphics/software/RenderPark/
DISTNAME=	RenderPark
.ifdef (WITH_SCENES)
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} Scenes${EXTRACT_SUFX}
.endif
DIST_SUBDIR=	${DISTNAME}

MAINTAINER=	ip@doom.homeunix.org
COMMENT=	System for physically based photo-realistic image synthesis

LIB_DEPENDS=	glut.4:${PORTSDIR}/graphics/libglut

.ifdef (WITH_XRML)
LIB_DEPENDS+=	xrml.0:${PORTSDIR}/graphics/xrml
.endif

WRKSRC=		${WRKDIR}/${DISTNAME}
WRKSRC2=	${WRKDIR}/Scenes

USE_GMAKE=	yes
USE_X_PREFIX=	yes
USE_MOTIF=	yes

.include <bsd.port.pre.mk>

.if ${OSVERSION} > 500000
USE_GCC=	2.95
NOT_FOR_ARCHS=	amd64 sparc64 ia64
.endif

.if !defined(WITH_SCENES)
PLIST_SUB=	WITH_SCENES="@comment "
.else
PLIST_SUB=	WITH_SCENES=""
.endif

pre-everything::
.ifndef (WITH_XRML)
	@${ECHO_MSG} "Defining WITH_XRML=yes will allow you to read XRML input files"
.endif
.ifndef (WITH_SCENES)
	@${ECHO_MSG} "Define WITH_SCENES=yes to install additional scenes package"
.endif

pre-patch:
	@${RM} -f ${WRKSRC}/Config.site
	@${CP} -f ${WRKSRC}/Config.FreeBSD ${WRKSRC}/Config.site
	${SETENV} ${SCRIPTS_ENV} \
		  REINPLACE_CMD="${REINPLACE_CMD}" \
		  FIND="${FIND}" \
		  GREP="${GREP}" \
	${SH} ${SCRIPTDIR}/cpp2c.sh

post-patch:
.ifdef (WITH_XRML)
	@${ECHO_CMD} "" >> ${WRKSRC}/Config.site
	@${ECHO_CMD} "####################################################" >> ${WRKSRC}/Config.site
	@${ECHO_CMD} "# VRML input support (requires XRML library)" >> ${WRKSRC}/Config.site
	@${ECHO_CMD} "VRMLHOME = ${X11BASE}" >> ${WRKSRC}/Config.site
	@${ECHO_CMD} "VRMLFLAGS = -I${X11BASE}/include/xrml" >> ${WRKSRC}/Config.site
	@${ECHO_CMD} "VRMLLIB = -L${X11BASE}/lib -lxrml" >> ${WRKSRC}/Config.site
.endif
	@${REINPLACE_CMD} -e 's|%%CC%%|${CC}|g ; \
			      s|%%CXX%%|${CXX}|g ;\
			      s|%%CFLAGS%%|${CFLAGS}|g' ${WRKSRC}/Config.site

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/rpk ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/${DISTNAME} ${PREFIX}/lib/X11/app-defaults
	@${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/SCENES/*.mgf ${EXAMPLESDIR}

.ifdef (WITH_SCENES)
	@${MKDIR} ${EXAMPLESDIR}/Scenes
	${INSTALL_DATA} ${WRKSRC2}/*.mgf ${EXAMPLESDIR}/Scenes
	${INSTALL_DATA} ${WRKSRC2}/README ${EXAMPLESDIR}/Scenes
	@${MKDIR} ${EXAMPLESDIR}/Scenes/Hospital
	${INSTALL_DATA} ${WRKSRC2}/Hospital/*.mgf ${EXAMPLESDIR}/Scenes/Hospital
	@${MKDIR} ${EXAMPLESDIR}/Scenes/Materials
	${INSTALL_DATA} ${WRKSRC2}/Materials/*.mgf ${EXAMPLESDIR}/Scenes/Materials
.endif

.ifndef (NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/DOC/*.* ${DOCSDIR}
	@${MKDIR} ${DOCSDIR}/SourceCode
	${INSTALL_DATA} ${WRKSRC}/DOC/SourceCode/* ${DOCSDIR}/SourceCode
	@${MKDIR} ${DOCSDIR}/UserGuide
	${INSTALL_DATA} ${WRKSRC}/DOC/UserGuide/* ${DOCSDIR}/UserGuide
.endif

.include <bsd.port.post.mk>
