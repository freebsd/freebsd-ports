# New ports collection makefile for:	jude_take
# Date created:				19 April 2004
# Whom:					Yoshihiko Sarumaru <mistral@imasy.or.jp>
#
# $FreeBSD$
#

PORTNAME=	jude-community
PORTVERSION=	2.5.1
CATEGORIES=	devel java
MASTER_SITES=	# you have to register yourself as a member to download
DISTNAME=	${PORTNAME}-${PORTVERSION:S!.!_!g}
EXTRACT_SUFX=	.zip

MAINTAINER=	mistral@imasy.or.jp
COMMENT=	A Java/UML Object-Oriented Design Tool

USE_ZIP=	yes
USE_JAVA=	yes
JAVA_VERSION=	1.4+
# It doesn't work well with linux-sun-jdk14
# I haven't tested with the jdks of blackdown or ibm
JAVA_OS=	native
NO_BUILD=	yes

RESTRICTED=	"See http://jude.change-vision.com/jude-web/notes/ProductLicenseAgreement.html"
NO_CDROM=	${RESTRICTED}

PLIST_SUB+=	PORTNAME=${PORTNAME}

WRKSRC=		${WRKDIR}/${PORTNAME:S!-!_!}

DOWNLOAD_URL=	http://jude.change-vision.com/jude-web/download/index.html

.if !defined(NOPORTDOCS)
PORTDOCS=	README-e.txt README.txt ReleaseNote-e.html ReleaseNote.html
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

do-install:
	${MKDIR} ${DATADIR}
	${INSTALL_SCRIPT} ${WRKSRC}/jude ${PREFIX}/bin
	${INSTALL_SCRIPT} ${FILESDIR}/mozilla ${DATADIR}
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
