# New ports collection makefile for:    Java Servlet Developpers Kit
# Date created:		1999/05/29
# Whom:			Kensaku Masuda <greg@greg.rim.or.jp>
#
# $FreeBSD$
#

PORTNAME=	jsdk
PORTVERSION=	2.0
PORTREVISION=	1
CATEGORIES=	java devel
MASTER_SITES=	#
DISTNAME=	jsdk20-solaris2-sparc
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	greg@greg.rim.or.jp
COMMENT=	Sun\'s Java Servlet Developers Kit

RUN_DEPENDS=	java:${PORTSDIR}/java/javavmwrapper

USE_JAVA=	yes
NO_BUILD=	yes

NO_CDROM=	"Sun has a funky license for this software"
RESTRICTED=	"no commercial use"

WRKSRC=		${WRKDIR}/JSDK2.0

.if defined(BATCH) || defined(PACKAGE_BUILDING)
IGNORE=		"Should be fetched manually"
.endif

PLIST_FILES=	%%JAVAJARDIR%%/jsdk.jar bin/servletrunner
.if !defined(NOPORTDOCS)
OTHERDOCS=	apidoc images servlet_tutorial.html
PORTDOCS=	README ${OTHERDOCS}
.endif

do-fetch:
	@if [ ! -f ${DISTDIR}/${DISTNAME}${EXTRACT_SUFX} ]; then \
	  ${ECHO_MSG} "=========================================================="; \
	  ${ECHO_MSG} " You must a fetch the Java Servlet Development Kit 2.0"; \
	  ${ECHO_MSG} " (for Unix) archive from"; \
	  ${ECHO_MSG} ""; \
	  ${ECHO_MSG} "     http://java.sun.com/products/servlet/archive.html"; \
	  ${ECHO_MSG} ""; \
	  ${ECHO_MSG} " And copy into ${DISTDIR}"; \
	  ${ECHO_MSG} "=========================================================="; \
	  ${FALSE}; \
	fi

do-configure:
	@${SED} \
	  -e 's,%%JAVAJARDIR%%,${JAVAJARDIR},g' \
	  -e 's,%%JAVA_CLASSES%%,${JAVA_CLASSES},g' \
	  -e 's,%%LOCALBASE%%,${LOCALBASE},g' \
	  ${FILESDIR}/servletrunner > ${WRKSRC}/servletrunner

do-install:
	@${ECHO_MSG} -n ">> Installing JAR as ${JAVAJARDIR}/jsdk.jar..."
	@${MKDIR} ${JAVAJARDIR}
	@${INSTALL_DATA} ${WRKSRC}/lib/jsdk.jar ${JAVAJARDIR}/
	@${ECHO_MSG} " [ DONE ]"
	@${ECHO_MSG} -n ">> Installing script in ${PREFIX}/bin..."
	@${INSTALL_SCRIPT} ${WRKSRC}/servletrunner ${PREFIX}/bin
	@${ECHO_MSG} " [ DONE ]"
.if !defined(NOPORTDOCS)
	@${ECHO_MSG} -n ">> Installing samples in ${EXAMPLESDIR}/..."
	@cd ${WRKSRC}/examples/ \
	  && ${FIND} . -type d -exec ${MKDIR} ${EXAMPLESDIR}/{} \; \
	  && ${FIND} . -type f -exec ${INSTALL_DATA} {} ${EXAMPLESDIR}/{} \;
	@${ECHO_MSG} " [ DONE ]"
	@${ECHO_MSG} -n ">> Installing documentation in ${DOCSDIR}/..."
	@cd ${WRKSRC}/doc/ \
	  && ${FIND} ${OTHERDOCS} -type d -exec ${MKDIR} ${DOCSDIR}/{} \; \
	  && ${FIND} ${OTHERDOCS} -type f -exec ${INSTALL_DATA} {} ${DOCSDIR}/{} \;
	@${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}/
	@${ECHO_MSG} " [ DONE ]"
.endif

.if !defined(NOPORTDOCS)
post-install:
	@${FIND} -s ${WRKSRC}/examples -not -type d \
	  | ${SED} -ne 's,^${WRKSRC}/examples,${EXAMPLESDIR:S,${PREFIX}/,,},p' >> ${TMPPLIST}
	@${FIND} -s -d ${WRKSRC}/examples -type d \
	  | ${SED} -ne 's,^${WRKSRC}/examples,@dirrm ${EXAMPLESDIR:S,${PREFIX}/,,},p' >> ${TMPPLIST}
.endif

.include <bsd.port.mk>
