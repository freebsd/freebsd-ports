# New ports collection makefile for:	openorb
# Date created:				2004-11-19
# Whom:					Herve Quiroz <hq@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	${APP_NAME:L}
PORTVERSION=	1.3.1
CATEGORIES=	devel java
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	${APP_NAME}-${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	hq@FreeBSD.org
COMMENT=	Java implementation of the OMG CORBA 2.4.2 specification

RUN_DEPENDS=	${JAVALIBDIR}/excalibur-configuration.jar:${PORTSDIR}/devel/excalibur-configuration \
		${JAVALIBDIR}/avalon-framework.jar:${PORTSDIR}/devel/avalon-framework \
		${JAVALIBDIR}/logkit.jar:${PORTSDIR}/java/avalon-logkit \
		${JAVALIBDIR}/xercesImpl.jar:${PORTSDIR}/textproc/xerces-j

APP_NAME=	OpenORB

USE_JAVA=	yes
JAVA_VERSION=	1.3+
NO_BUILD=	yes

DATADIR=	${JAVASHAREDIR}/${PORTNAME}

SCRIPT_FILES=	openorb-idl_compiler openorb-naming_service
DATA_FILES=	config idl test
JAR_FILES=	openorb-1.3.1.jar openorb_examples-1.3.1.jar openorb_test-1.3.1.jar openorb_tools-1.3.1.jar
PLIST_FILES=	${JAR_FILES:S,-${PORTVERSION},,:S,^,%%JAVAJARDIR%%/,} ${SCRIPT_FILES:S,^,bin/,}
.if !defined(NOPORTDOCS)
OTHERDOCS=	EXOLAB.txt LICENSE.txt README WHATSNEW
PORTDOCS=	${OTHERDOCS} html_img javadoc orb.html orb.pdf
.endif

.include <bsd.port.pre.mk>

JAR_DEPENDS=	excalibur-configuration.jar avalon-framework.jar logkit.jar xercesImpl.jar xml-apis.jar
CLASSPATH!=	${ECHO_CMD} \
		  "${JAR_FILES:S,-${PORTVERSION},,:S,^,${JAVAJARDIR}/,} ${JAR_DEPENDS:S,^,${JAVALIBDIR}/,}" \
		  | ${TR} " " ":"

do-configure:
	${SED} \
	  -e 's,%%LOCALBASE%%,${LOCALBASE},' \
	  -e 's,%%CLASSPATH%%,${CLASSPATH},' \
	  -e 's,%%BASENAME%%,${BASENAME},' \
	  ${FILESDIR}/launcher.sh > ${WRKSRC}/launcher

do-install:
	@${ECHO_MSG} -n ">> Installing JARs in ${JAVAJARDIR}/..."
	@${MKDIR} ${JAVAJARDIR}
	@for jarfile in ${JAR_FILES} ; do \
	  destjarfile="`${ECHO_CMD} "$${jarfile}" | ${SED} -e 's,-${PORTVERSION},,'`" ; \
	  ${ECHO_MSG} -n " $${destjarfile}" ; \
	  ${INSTALL_DATA} ${WRKSRC}/lib/$${jarfile} ${JAVAJARDIR}/$${destjarfile} ; \
	done
	@${ECHO_MSG} "  [ DONE ]"
	@${ECHO_MSG} -n ">> Installing launcher scripts in ${PREFIX}/bin/..."
.for script in ${SCRIPT_FILES}
	@${ECHO_MSG} -n " ${script}"
	@${INSTALL_SCRIPT} ${WRKSRC}/launcher ${PREFIX}/bin/${script}
.endfor
	@${ECHO_MSG} "  [ DONE ]"
	@${ECHO_MSG} -n ">> Installing data files in ${DATADIR}/..."
	@cd ${WRKSRC} \
	  && ${FIND} ${DATA_FILES} -type d -exec ${MKDIR} ${DATADIR}/{} \; \
	  && ${FIND} ${DATA_FILES} -type f -exec ${INSTALL_DATA} {} ${DATADIR}/{} \;
	@${ECHO_MSG} " [ DONE ]"
.if !defined(NOPORTDOCS)
	@${ECHO_MSG} -n ">> Installing samples in ${EXAMPLESDIR}/..."
	@cd ${WRKSRC}/examples \
	  && ${FIND} . -type d -exec ${MKDIR} ${EXAMPLESDIR}/{} \; \
	  && ${FIND} . -type f -exec ${INSTALL_DATA} {} ${EXAMPLESDIR}/{} \;
	@${ECHO_MSG} " [ DONE ]"
	@${ECHO_MSG} -n ">> Installing documentation in ${DOCSDIR}/..."
	@cd ${WRKSRC}/doc \
	  && ${FIND} . -type d -exec ${MKDIR} ${DOCSDIR}/{} \; \
	  && ${FIND} . -type f -exec ${INSTALL_DATA} {} ${DOCSDIR}/{} \;
	@${INSTALL_DATA} ${OTHERDOCS:S,^,${WRKSRC}/,} ${DOCSDIR}/
	@${ECHO_MSG} " [ DONE ]"
.endif

post-install:
	@${FIND} -s ${DATA_FILES:S,^,${WRKSRC}/,} -not -type d \
	  | ${SED} -ne 's,^${WRKSRC},${DATADIR:S,^${PREFIX}/,,},p' >> ${TMPPLIST}
	@${FIND} -s -d ${DATA_FILES:S,^,${WRKSRC}/,} -type d \
	  | ${SED} -ne 's,^${WRKSRC},@dirrm ${DATADIR:S,^${PREFIX}/,,},p' >> ${TMPPLIST}
	@${ECHO_CMD} "@dirrm ${DATADIR:S,^${PREFIX}/,,}" >> ${TMPPLIST}
.if !defined(NOPORTDOCS)
	@${FIND} -s ${WRKSRC}/examples -not -type d \
	  | ${SED} -ne 's,^${WRKSRC}/examples,${EXAMPLESDIR:S,^${PREFIX}/,,},p' >> ${TMPPLIST}
	@${FIND} -s -d ${WRKSRC}/examples -type d \
	  | ${SED} -ne 's,^${WRKSRC}/examples,@dirrm ${EXAMPLESDIR:S,^${PREFIX}/,,},p' >> ${TMPPLIST}
.endif

.include <bsd.port.post.mk>
