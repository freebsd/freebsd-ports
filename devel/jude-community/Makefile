# New ports collection makefile for:	jude_take
# Date created:				19 April 2004
# Whom:					Yoshihiko Sarumaru <mistral@imasy.or.jp>
#
# $FreeBSD$
#

PORTNAME=	jude-community
PORTVERSION=	5.2.1
PORTREVISION=	1
CATEGORIES=	devel java
MASTER_SITES=	# you have to register yourself as a member to download
DISTNAME=	${PORTNAME}-${PORTVERSION:S!.!_!g}

MAINTAINER=	mistral@imasy.or.jp
COMMENT=	A Java/UML Object-Oriented Design Tool

USE_ZIP=	yes

# Export HTML function can be used with JDK 1.4 only.
# (But it can work with JDK 1.5 + copying JDK 1.4 tools.jar to ${DATADIR})
OPTIONS=	EXPORT_HTML "Enable Exporting HTML function (needs JDK1.4)" Off

.include <bsd.port.pre.mk>

# In case you are going to use JDK1.5+ in Japanese environment, make sure
# you have prepared following command to avoid from font problem:
# ln -s ${LOCALBASE}/lib/X11/fonts/TrueType \
#     ${LOCALBASE}/diablo-jdk1.5.0/jre/lib/fonts/fallback
.if defined(WITH_EXPORT_HTML)
JAVA_VERSION=	1.4
.else
JAVA_VERSION=	1.4+
.endif

USE_JAVA=	yes
JAVA_OS=	native
NO_BUILD=	yes

.include "${PORTSDIR}/Mk/bsd.java.mk"

RESTRICTED=	See http://jude.change-vision.com/jude-web/notes/ProductLicenseAgreement.html

WRKSRC=		${WRKDIR}/${PORTNAME:S!-!_!}

DOWNLOAD_URL=	http://jude.change-vision.com/jude-web/download/index.html

PLIST_FILES=	bin/jude share/${PORTNAME}/mozilla
DATA_FILES=	${PORTNAME}.jar jude-api.jar jude-gui_en.properties_org \
		jude.ico jude-doc.ico Welcome.jude Welcome_ja.jude \
		template/project/Java1.4.jude template/project/Java5.jude

.for file in ${DATA_FILES}
PLIST_FILES+=	share/${PORTNAME}/${file}
.endfor
.if defined(WITH_EXPORT_HTML)
PLIST_FILES+=	share/${PORTNAME}/tools.jar
.endif
PLIST_DIRS=	share/${PORTNAME}/template/project \
		share/${PORTNAME}/template \
		share/${PORTNAME}

.if !defined(NOPORTDOCS)
PORTDOCS+=	README-e.txt README.txt ReleaseNote-e.html ReleaseNote.html \
		ProductInformation.txt
.endif

.if !exists(${DISTDIR}/${DISTNAME}${EXTRACT_SUFX})
IGNORE=		needs you to fetch manually the distribution file\
		from ${DOWNLOAD_URL}, \
		then place it in ${DISTDIR} and run make again
.endif

post-patch:
	${REINPLACE_CMD} -e "s!%%JAVA_HOME%%!${JAVA_HOME}!; \
	                     s!%%DATADIR%%!${DATADIR}!" ${WRKSRC}/jude
.if !defined(NOPORTDOCS)
	${REINPLACE_CMD} 's/png\\/png\//' ${WRKSRC}/api/*/doc/index.html
.endif

do-install:
	${MKDIR} ${DATADIR}
	${INSTALL_SCRIPT} ${WRKSRC}/jude ${PREFIX}/bin
	${INSTALL_SCRIPT} ${FILESDIR}/mozilla ${DATADIR}
	(cd ${WRKSRC} && ${COPYTREE_SHARE} "${DATA_FILES}" ${DATADIR})
.if defined(WITH_EXPORT_HTML)
	# ExportHTML needs lib/tools.jar of JDK1.4
	${LN} -s ${JAVA_HOME}/lib/tools.jar ${DATADIR}
.endif
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for docfile in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${docfile} ${DOCSDIR}
.endfor
	${MKDIR} ${DOCSDIR}/api
	(cd ${WRKSRC}/api && ${COPYTREE_SHARE} \* ${DOCSDIR}/api)
	@ cd ${PREFIX} && ${FIND} share/doc/${PORTNAME}/api -type f -print | \
		${SORT} -r >> ${TMPPLIST}
	@ cd ${PREFIX} && ${FIND} share/doc/${PORTNAME}/api -type d -print | \
		${SORT} -r |  ${SED} -e 's#^#@dirrm #' >> ${TMPPLIST}
.endif

.include <bsd.port.post.mk>
