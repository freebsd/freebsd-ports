# New ports collection makefile for:	jude_take
# Date created:				19 April 2004
# Whom:					Yoshihiko Sarumaru <mistral@imasy.or.jp>
#
# $FreeBSD$
#

PORTNAME=	jude-community
PORTVERSION=	1.5.2
CATEGORIES=	devel java
MASTER_SITES=	# you have to register yourself as a member to download
DISTNAME=	${PORTNAME}-${PORTVERSION:S!.!_!g}
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

RESTRICTED=	"See http://www.esm.jp/jude-web/en/permission_e.html"
NO_CDROM=	${RESTRICTED}

PLIST_SUB+=	PORTNAME=${PORTNAME}

WRKSRC=		${WRKDIR}/${PORTNAME:S!-!_!}

DOWNLOAD_URL=	https://www.esm.jp/jude-web/en/enquete_e.html

.if !defined(NOPORTDOCS)
PORTDOCS=	README-e.txt README.txt ReleaseNote-e.html ReleaseNote.html
.endif

.include <bsd.port.pre.mk>

.if !exists(${DISTDIR}/${DISTNAME}${EXTRACT_SUFX})
IGNORE=		You must manually fetch the distribution file from ${DOWNLOAD_URL}, then\
		place it in ${DISTDIR} and run make again
.endif

post-patch:
	${REINPLACE_CMD} -e "s!%%JAVA_HOME%%!${JAVA_HOME}!; \
	                     s!%%DATADIR%%!${DATADIR}!" ${WRKSRC}/jude

do-install:
	${MKDIR} ${DATADIR}
	${INSTALL_SCRIPT} ${WRKSRC}/jude ${PREFIX}/bin
	${INSTALL_SCRIPT} ${FILESDIR}/netscape ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}.jar ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/JudeDefaultModel.jude ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/jude.ico ${DATADIR}
	# ExportHTML needs lib/tools.jar to be copied
	${LN} -s ${JAVA_HOME}/lib/tools.jar ${DATADIR}

.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for file in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.post.mk>
