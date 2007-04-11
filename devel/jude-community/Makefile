# New ports collection makefile for:	jude_take
# Date created:				19 April 2004
# Whom:					Yoshihiko Sarumaru <mistral@imasy.or.jp>
#
# $FreeBSD$
#

PORTNAME=	jude-community
PORTVERSION=	3.2.1
CATEGORIES=	devel java
MASTER_SITES=	# you have to register yourself as a member to download
DISTNAME=	${PORTNAME}-${PORTVERSION:S!.!_!g}
EXTRACT_SUFX=	.zip

MAINTAINER=	mistral@imasy.or.jp
COMMENT=	A Java/UML Object-Oriented Design Tool

USE_ZIP=	yes
USE_JAVA=	yes
# HTML export doesn't work with JDK 5.0.
# Expect that, Jude Community 3.1 works fine with JDK 5.0
# work around to use JDK 5.0: symlink or copy tools.jar from JDK 1.4.
JAVA_VERSION=	1.4
# It doesn't work well with linux-sun-jdk14
# I haven't tested with the jdks of blackdown or ibm
JAVA_OS=	native
NO_BUILD=	yes

RESTRICTED=	See http://jude.change-vision.com/jude-web/notes/ProductLicenseAgreement.html

WRKSRC=		${WRKDIR}/${PORTNAME:S!-!_!}

DOWNLOAD_URL=	http://jude.change-vision.com/jude-web/download/index.html

PLIST_FILES=	bin/jude share/${PORTNAME}/mozilla
DATA_FILES=	${PORTNAME}.jar jude-api.jar JudeDefaultModel.jude \
		JudeDefaultModel_ja.jude jude-gui_en.properties_org \
		jude.ico jude-doc.ico Welcome.jude Welcome_ja.jude
.for file in ${DATA_FILES}
PLIST_FILES+=	share/${PORTNAME}/${file}
.endfor
PLIST_FILES+=	share/${PORTNAME}/tools.jar
PLIST_DIRS=	share/${PORTNAME}

.if !defined(NOPORTDOCS)
PORTDOCS+=	README-e.txt README.txt ReleaseNote-e.html ReleaseNote.html \
		ProductInformation.txt
.endif

.include <bsd.port.pre.mk>

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
.for datafile in ${DATA_FILES}
	${INSTALL_DATA} ${WRKSRC}/${datafile} ${DATADIR}
.endfor
	# ExportHTML needs lib/tools.jar to be copied
	${LN} -s ${JAVA_HOME}/lib/tools.jar ${DATADIR}

.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for docfile in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${docfile} ${DOCSDIR}
.endfor
	@ ${MKDIR} ${DOCSDIR}/api
	@ cd ${WRKSRC}/api && ${FIND} . | \
		${CPIO} --quiet -pdm -L -R ${SHAREOWN}:${SHAREGRP} ${DOCSDIR}/api
	@ cd ${PREFIX} && ${FIND} share/doc/${PORTNAME}/api -type f -print | \
		${SORT} -r >> ${TMPPLIST}
	@ cd ${PREFIX} && ${FIND} share/doc/${PORTNAME}/api -type d -print | \
		${SORT} -r |  ${SED} -e 's#^#@dirrm #' >> ${TMPPLIST}
.endif

.include <bsd.port.post.mk>
