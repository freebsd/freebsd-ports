# New ports collection makefile for:	jude_take
# Date created:				19 April 2004
# Whom:					Yoshihiko Sarumaru <mistral@imasy.or.jp>
#
# $FreeBSD$
#

PORTNAME=	jude_take
PORTVERSION=	1.3
CATEGORIES=	devel
MASTER_SITES=	# you have to answer some enquetes to download
DISTNAME=	${PORTNAME}${PORTVERSION:S/./_/g}
EXTRACT_SUFX=	.zip

MAINTAINER=	mistral@imasy.or.jp
COMMENT=	A Java/UML Object-Oriented Design Tool

USE_ZIP=	yes
USE_JAVA=	1.4+
# It doesn't work well with linux-sun-jdk14
# I haven't tested with the jdks of blackdown or ibm
JAVA_OS=	native
NO_BUILD=	yes
USE_REINPLACE=	yes

RESTRICTED=	"See http://objectclub.esm.co.jp/Jude/permission_e.html"
NO_CDROM=	${RESTRICTED}

WRKSRC=		${WRKDIR}/${PORTNAME}

DOWNLOAD_URL=	http://objectclub.esm.co.jp/Jude/enquete_e.html

.if !defined(NOPORTDOCS)
PORTDOCS=	README-e.txt README.txt Release_Note-e.html Release_Note.html
.endif

.include <bsd.port.pre.mk>

.if !exists(${DISTDIR}/${DISTNAME}${EXTRACT_SUFX})
IGNORE=	"You must manually fetch the distribution file ${DISTNAME}${EXTRACT_SUFX} from ${DOWNLOAD_URL}, place it in ${DISTDIR} and then run make again"
.endif

post-patch:
	${REINPLACE_CMD} -e "s!%%JAVA_HOME%%!${JAVA_HOME}!" ${WRKSRC}/jude

do-install:
	${MKDIR} ${DATADIR}
	${INSTALL_SCRIPT} ${WRKSRC}/jude ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/jude-take.jar ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/JudeDefaultModel.jude ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/jude.ico ${DATADIR}
	# ExportHTML needs lib/tools.jar to be copied
	# ExportHTML doesn't work with version 1.3 (Known Problem)
	#${LN} -s ${JAVA_HOME}/lib/tools.jar ${DATADIR}

.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for file in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.post.mk>
