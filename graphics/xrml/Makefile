# New ports collection makefile for:	xrml
# Date created:		23 July 2002
# Whom:			Igor Pokrovsky <tiamat@telegraph.spb.ru>
#
# $FreeBSD$
#

PORTNAME=	xrml
PORTVERSION=	0.5.3
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	ftp://ftp.cs.kuleuven.ac.be/pub/graphics/software/RenderPark/
DISTNAME=	${PORTNAME}
DIST_SUBDIR=	RenderPark

MAINTAINER=	ip@doom.homeunix.org
COMMENT=	Extensible scene graph library based on VRML'97

WRKSRC=		${WRKDIR}/${PORTNAME:U}

USE_GMAKE=	yes
USE_X_PREFIX=	yes
USE_GL=		yes
USE_MOTIF=	yes
USE_REINPLACE=	yes
INSTALLS_SHLIB=	yes

.if !defined(WITH_EXAMPLES)
PLIST_SUB=	WITH_EXAMPLES="@comment "
.else
PLIST_SUB=	WITH_EXAMPLES=""
.endif

.include <bsd.port.pre.mk>

.if ${OSVERSION} > 500000
USE_GCC=	2.95
NOT_FOR_ARCHS=	amd64 sparc64 ia64
.endif

.ifndef (WITH_EXAMPLES)
pre-everything::
	@${ECHO_MSG} "You can define WITH_EXAMPLES=yes to install example VRML files"
.endif

pre-patch:
	@${CP} -f ${WRKSRC}/Config.Linux ${WRKSRC}/Config.site
post-patch:
	@${REINPLACE_CMD} -e 's|%%CC%%|${CC}|g ; \
			      s|%%CXX%%|${CXX}|g ; \
			      s|%%CXXFLAGS%%|${CXXFLAGS}|g ; \
			      s|%%X11BASE%%|${X11BASE}|g' ${WRKSRC}/Config.site

pre-build:
	${GMAKE} -C ${WRKSRC}/FILTERS link_includes
	${GMAKE} -C ${WRKSRC}/XRML link_includes
	@${RM} -f ${WRKSRC}/PROGS/vrmldump/deps

do-install:
	@${MKDIR} ${PREFIX}/include/xrml
	${INSTALL_DATA} ${WRKSRC}/include/*.[hH] ${PREFIX}/include/xrml
.for i in cso mgf nff vrml2_utf8
	@${MKDIR} ${PREFIX}/include/xrml/${i}
	${INSTALL_DATA} ${WRKSRC}/include/${i}/* ${PREFIX}/include/xrml/${i}
.endfor

	${INSTALL_PROGRAM} ${WRKSRC}/bin/* ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/lib/libxrml.so.0.5 ${PREFIX}/lib/libxrml.so.0
	${LN} -fs libxrml.so.0 ${PREFIX}/lib/libxrml.so
	@${STRIP_CMD} ${WRKSRC}/lib/*.a
	${INSTALL_DATA} ${WRKSRC}/lib/*.a ${PREFIX}/lib

.ifdef (WITH_EXAMPLES)
	@${MKDIR} ${EXAMPLESDIR}
.for i in wrl ppm gz mgf
	${INSTALL_DATA} ${WRKSRC}/TEST/*.${i} ${EXAMPLESDIR}
.endfor
	${INSTALL_DATA} ${WRKSRC}/TEST/plotfunc.c ${EXAMPLESDIR}
.endif

.ifndef (NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/DOC/*.html ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/DOC/nodeapi ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/DOC/nodegen ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/DOC/status ${DOCSDIR}
	@${MKDIR} ${DOCSDIR}/PhBRML
	${INSTALL_DATA} ${WRKSRC}/DOC/PhBRML/*.html ${DOCSDIR}/PhBRML
	${INSTALL_DATA} ${WRKSRC}/DOC/PhBRML/2ndtextured.gif ${DOCSDIR}/PhBRML
	${INSTALL_DATA} ${WRKSRC}/DOC/PhBRML/*.wrl ${DOCSDIR}/PhBRML
	@${MKDIR} ${DOCSDIR}/VRML97
	${INSTALL_DATA} ${WRKSRC}/DOC/VRML97/*.html ${DOCSDIR}/VRML97
	@${MKDIR} ${DOCSDIR}/VRML97/Images
.for i in gif jpg
	${INSTALL_DATA} ${WRKSRC}/DOC/VRML97/Images/*.${i} ${DOCSDIR}/VRML97/Images
.endfor
	@${MKDIR} ${DOCSDIR}/VRML97/part1
.for i in html wrl wav
	${INSTALL_DATA} ${WRKSRC}/DOC/VRML97/part1/*.${i} ${DOCSDIR}/VRML97/part1
.endfor
	${LN} -sf VRML97 ${DOCSDIR}/VRML
.endif

.include <bsd.port.post.mk>
