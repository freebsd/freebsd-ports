# New ports collection makefile for:	ireport
# Date created:		21 May 2005
# Whom:			Thierry Thomas <thierry@pompo.net>
#
# $FreeBSD$
#

PORTNAME=	ireport
PORTVERSION=	0.5.0
PORTREVISION=	1
CATEGORIES=	devel databases java
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	iReport-${PORTVERSION}

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	A visual report builder/designer for JasperReports

RUN_DEPENDS=	java:${PORTSDIR}/java/javavmwrapper	\
		${JAVALIBDIR}/bsh.jar:${PORTSDIR}/java/bsh	\
		${JAVALIBDIR}/looks.jar:${PORTSDIR}/devel/looks	\
		${JAVALIBDIR}/tinylaf.jar:${PORTSDIR}/devel/tinylaf	\
		${JAVALIBDIR}/jcmdline.jar:${PORTSDIR}/devel/jcmdline	\
		${JAVALIBDIR}/barbecue.jar:${PORTSDIR}/graphics/barbecue	\
		${JAVALIBDIR}/jfreechart.jar:${PORTSDIR}/java/jfreechart	\
		${JAVALIBDIR}/jasperreports.jar:${PORTSDIR}/databases/jasperreports

USE_JAVA=	yes
JAVA_VERSION=	1.4+
USE_REINPLACE=	yes
NO_BUILD=	yes

PLIST_SUB=	VER=${PORTVERSION} VERMAN=0.2.0

JARFILES=	groovy-all-1.0-beta-10.jar iReport.jar jdt-compiler.jar	\
		jr-bsh-compiler.jar jr-groovy-compiler.jar

BASEFILES=	Changelog.txt relnotes${PORTVERSION}.html
SUBDIRS=	fonts plugins templates

# Jarfiles to be included in classpath
CLSSPTH=	barbecue bsh commons-beanutils commons-collections commons-digester	\
		commons-logging-api commons-logging groovy-all-1.0-beta-10 iReport	\
		itext jasperreports jcmdline jcommon jdt-compiler jfreechart		\
		jr-bsh-compiler jr-groovy-compiler log4j looks mysql-connector-java	\
		postgresql poi tinylaf xalan xercesImpl xmlParserAPIs

.if !defined(NOPORTDOCS)
SUBDIRS+=	docs
.endif

.include <bsd.port.pre.mk>

# Remark: Oracle's dependencies already registered by databases/jasperreports
.if exists(${JAVALIBDIR}/classes12.zip)
WITH_ORACLE8=	yes
.endif
.if defined(WITH_ORACLE8)
CLSSORA=	classes12.zip nls_charset12.zip
.endif

.if exists(${JAVALIBDIR}/ojdbc14.zip)
WITH_ORACLE9=	yes
.endif
.if defined(WITH_ORACLE9)
CLSSORA+=	ojdbc14.jar ocrs12.zip
.endif

post-extract:
	@${FIND} ${WRKSRC} -name "*.bat" -exec ${RM} {} \;
	@${RMDIR} -p ${WRKSRC}/docs/releases/Release0.3.2/Release\ Document\ 0.3.2_files	\
		2>/dev/null | ${TRUE}

pre-configure:
	@${REINPLACE_CMD} -e 's|%%CLSSPTH%%|${CLSSPTH:S,^,${JAVALIBDIR}/,g:S,$,.jar£,g}|;	\
	s|jar£ |jar\:|g; s|£|:${JAVA_HOME}/lib/tools.jar${CLSSORA:S,^,\:${JAVALIBDIR}/,g}|;	\
	s|zip |zip|g; s|jar |jar|g; s|%%DATADIR%%|${DATADIR}|;	\
	s|^java |JAVA_VERSION="${JAVA_VERSION}" ${LOCALBASE}/bin/java |'	\
		${WRKSRC}/bin/startup.sh

do-install:
	${MKDIR} ${DATADIR}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/bin/startup.sh ${DATADIR}/bin
	${LN} -sf ${DATADIR}/bin/startup.sh ${PREFIX}/bin/iReport
	${LN} -sf ${JAVAJARDIR} ${DATADIR}/lib
	${INSTALL_DATA} ${JARFILES:S|^|${WRKSRC}/lib/|} ${JAVAJARDIR}
	${INSTALL_DATA} ${BASEFILES:S|^|${WRKSRC}/|} ${DATADIR}
	cd ${WRKSRC} && ${FIND} ${SUBDIRS} -type d -exec ${MKDIR} ${DATADIR}/{} \;
	cd ${WRKSRC} && ${FIND} ${SUBDIRS} -type f -exec ${INSTALL_DATA} {} ${DATADIR}/{} \;
.if !defined(NOPORTDOCS)
	${LN} -sf ${DATADIR}/docs ${DOCSDIR}
.endif

post-install:
	@${ECHO_MSG}
	@${CAT} ${PKGMESSAGE}
	@${ECHO_MSG}

.include <bsd.port.post.mk>
