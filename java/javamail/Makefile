# New ports collection makefile for:    JavaMail API Implementation
# Date created:		1999/08/08
# Whom:			Jose Marques
#
# $FreeBSD$
#

PORTNAME=	javamail
PORTVERSION=	1.4.3
CATEGORIES=	java mail
MASTER_SITES=	#

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A Reference Implementation of JSR 919

RUN_DEPENDS=	${JAVALIBDIR}/activation.jar:${PORTSDIR}/java/jaf

USE_ZIP=	YES
USE_JAVA=	YES
JAVA_VERSION=	1.4+

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
NO_BUILD=	yes
NO_CDROM=	See the license
DOWNLOAD_URL=	https://cds.sun.com/is-bin/INTERSHOP.enfinity/WFS/CDS-CDS_Developer-Site/en_US/-/USD/ViewProductDetail-Start?ProductRef=javamail-${PORTVERSION}-oth-JPR@CDS-CDS_Developer

.if !defined(NOPORTDOCS)
DOCFILES1=	JavaMail-1.1-changes.txt JavaMail-1.2-changes.txt \
		JavaMail-1.4.pdf JavaMail-1.3-changes.txt \
		JavaMail-1.4-changes.txt Providers.pdf javadocs
DOCFILES2=	CHANGES.txt COMPAT.txt COPYRIGHT.txt LICENSE.txt NOTES.txt \
		NTLMNOTES.txt README.txt SSLNOTES.txt distributionREADME.txt
PORTDOCS=	${DOCFILES1} ${DOCFILES2}
.endif

JARFILES=	mail.jar dsn.jar imap.jar mailapi.jar pop3.jar smtp.jar
PLIST_FILES=	${JARFILES:S,^,%%JAVAJARDIR%%/,}

.include <bsd.port.pre.mk>
.if !exists(${DISTDIR}/${DISTNAME}${EXTRACT_SUFX}) && !defined(PACKAGE_BUILDING)
IGNORE=		you must manually fetch the distribution from ${DOWNLOAD_URL} and place it in ${DISTDIR} then run make again
.endif

do-install:
	@${ECHO_MSG} -n ">> Installing demo in ${EXAMPLESDIR}..."
	@${MKDIR} ${EXAMPLESDIR}
	@cd ${WRKSRC} && ${FIND} demo \
	  | ${CPIO} -pdmu -R ${SHAREOWN}:${SHAREGRP} ${EXAMPLESDIR} > /dev/null 2>&1
	@${ECHO_MSG} " [ DONE ]"
	@${ECHO_MSG} -n ">> Install JAR files in ${JAVAJARDIR}..."
	@${INSTALL_DATA} ${WRKSRC}/mail.jar ${JAVAJARDIR}/
	@cd ${WRKSRC}/lib && ${INSTALL_DATA} dsn.jar imap.jar mailapi.jar pop3.jar smtp.jar ${JAVAJARDIR}/
	@${ECHO_MSG} " [ DONE ]"
.if !defined(NOPORTDOCS)
	@${ECHO_MSG} -n ">> Installing documentation in ${DOCSDIR}..."
	@${MKDIR} ${DOCSDIR}
	@cd ${WRKSRC}/docs && ${FIND} ${DOCFILES1} \
	  | ${CPIO} -pdmu -R ${SHAREOWN}:${SHAREGRP} ${DOCSDIR} > /dev/null 2>&1
	@cd ${WRKSRC} && ${FIND} ${DOCFILES2} \
	  | ${CPIO} -pdmu -R ${SHAREOWN}:${SHAREGRP} ${DOCSDIR} > /dev/null 2>&1
	@${ECHO_MSG} " [ DONE ]"
.endif

post-install:
	@${FIND} -s ${WRKSRC}/demo -not -type d 2>/dev/null \
	  | ${SED} -ne 's,^${WRKSRC},${EXAMPLESDIR:S,^${PREFIX}/,,},p' >> ${TMPPLIST}
	@${FIND} -s -d ${WRKSRC}/demo -type d 2>/dev/null \
	  | ${SED} -ne 's,^${WRKSRC},@dirrm ${EXAMPLESDIR:S,^${PREFIX}/,,},p' >> ${TMPPLIST}
	@${ECHO_CMD} '@dirrm ${EXAMPLESDIR:S,^${PREFIX}/,,}' >> ${TMPPLIST}

.include <bsd.port.post.mk>
