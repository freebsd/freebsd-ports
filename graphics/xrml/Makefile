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

MAINTAINER=	tiamat@comset.net
COMMENT=	Extensible scene graph library based on VRML'97

WRKSRC=		${WRKDIR}/XRML

USE_GMAKE=	yes
USE_X_PREFIX=	yes
USE_MESA=	yes
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
USE_GCC=2.95
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
	${INSTALL_DATA} ${WRKSRC}/include/*.H ${PREFIX}/include/xrml
	${INSTALL_DATA} ${WRKSRC}/include/*.h ${PREFIX}/include/xrml
	@${MKDIR} ${PREFIX}/include/xrml/cso
	${INSTALL_DATA} ${WRKSRC}/include/cso/* ${PREFIX}/include/xrml/cso
	@${MKDIR} ${PREFIX}/include/xrml/mgf
	${INSTALL_DATA} ${WRKSRC}/include/mgf/* ${PREFIX}/include/xrml/mgf
	@${MKDIR} ${PREFIX}/include/xrml/nff
	${INSTALL_DATA} ${WRKSRC}/include/nff/* ${PREFIX}/include/xrml/nff
	@${MKDIR} ${PREFIX}/include/xrml/vrml2_utf8
	${INSTALL_DATA} ${WRKSRC}/include/vrml2_utf8/* ${PREFIX}/include/xrml/vrml2_utf8

	${INSTALL_PROGRAM} ${WRKSRC}/bin/* ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/lib/libxrml.so.0.5 ${PREFIX}/lib/libxrml.so.0
	${LN} -fs libxrml.so.0 ${PREFIX}/lib/libxrml.so
	@${STRIP_CMD} ${WRKSRC}/lib/*.a
	${INSTALL_DATA} ${WRKSRC}/lib/*.a ${PREFIX}/lib

.ifdef (WITH_EXAMPLES)
	@${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/TEST/*.wrl ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/TEST/*.ppm ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/TEST/*.gz ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/TEST/*.mgf ${EXAMPLESDIR}
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
	${INSTALL_DATA} ${WRKSRC}/DOC/VRML97/Images/* ${DOCSDIR}/VRML97/Images
	@${MKDIR} ${DOCSDIR}/VRML97/part1
	${INSTALL_DATA} ${WRKSRC}/DOC/VRML97/part1/* ${DOCSDIR}/VRML97/part1
	${LN} -s VRML97 ${DOCSDIR}/VRML
.endif

.include <bsd.port.post.mk>
