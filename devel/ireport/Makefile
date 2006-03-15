# New ports collection makefile for:	ireport
# Date created:		21 May 2005
# Whom:			Thierry Thomas <thierry@pompo.net>
#
# $FreeBSD$
#

PORTNAME=	ireport
PORTVERSION=	1.2.0
CATEGORIES=	devel databases java
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	iReport-${PORTVERSION}

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	A visual report builder/designer for JasperReports

RUN_DEPENDS=	java:${PORTSDIR}/java/javavmwrapper	\
		${JAVALIBDIR}/bsh.jar:${PORTSDIR}/java/bsh	\
		${JAVALIBDIR}/dom4j.jar:${PORTSDIR}/textproc/dom4j	\
		${JAVALIBDIR}/antlr.jar:${PORTSDIR}/devel/antlr	\
		${JAVALIBDIR}/looks.jar:${PORTSDIR}/devel/looks	\
		${JAVALIBDIR}/tinylaf.jar:${PORTSDIR}/devel/tinylaf	\
		${JAVALIBDIR}/jcmdline.jar:${PORTSDIR}/devel/jcmdline	\
		${JAVALIBDIR}/xml-apis.jar:${PORTSDIR}/textproc/xerces-j	\
		${JAVALIBDIR}/jasperreports.jar:${PORTSDIR}/databases/jasperreports

USE_JAVA=	yes
JAVA_VERSION=	1.4+
NO_BUILD=	yes

PLIST_SUB=	VER=${PORTVERSION} VERMAN=0.2.0

JARFILES=	LICENSE.asm-attr.txt LICENSE.asm.txt LICENSE.barbecue-1.1.txt	\
		LICENSE.jta.txt asm-attrs.jar asm.jar barbecue-1.1.jar		\
		cglib-2.1.jar ehcache-1.1.jar groovy-all-1.0-beta-10.jar	\
		hibernate3.jar iReport.jar jdt-compiler.jar			\
		jexelapiexporter-jr120.jar jr-bsh-compiler.jar			\
		jr-groovy-compiler.jar jta.jar jxl.jar pngencoder.jar toniclf.jar
BASEFILES=	Changelog.txt notice.txt relnotes${PORTVERSION}.html
SUBDIRS=	fonts plugins templates

# Jarfiles to be included in classpath
CLSSPTH=	antlr asm-attrs asm.jar barbecue-1.1 bsh cglib-2.1	\
		commons-beanutils commons-collections commons-digester	\
		commons-logging commons-logging-api dom4j ehcache-1.1	\
		groovy-all-1.0-beta-10 hibernate3 iReport itext		\
		jasperreports jcmdline jcommon jdt-compiler		\
		jexelapiexporter-jr120 jfreechart jr-bsh-compiler	\
		jr-groovy-compiler jta jxl log4j looks			\
		mysql-connector-java pngencoder poi postgresql tinylaf	\
		toniclf xalan xercesImpl xml-apis ${CLSSHSQLDB}

.if !defined(NOPORTDOCS)
SUBDIRS+=	docs
.endif

.include <bsd.port.pre.mk>

# Remark: HSQLDB and Oracle's dependencies already registered by databases/jasperreports
.if exists(${JAVALIBDIR}/classes12.zip)
WITH_ORACLE8=	yes
.endif
.if defined(WITH_ORACLE8)
CLSSORA=	classes12.zip nls_charset12.zip
.endif

.if exists(${JAVALIBDIR}/ojdbc14.jar)
WITH_ORACLE9=	yes
.endif
.if defined(WITH_ORACLE9)
CLSSORA+=	ojdbc14.jar ocrs12.zip
.endif

.if exists(${JAVALIBDIR}/hsqldb.jar)
WITH_HSQLDB=	yes
.endif
.if defined(WITH_HSQLDB)
CLSSHSQLDB=	hsqldb
.endif

post-extract:
	@${FIND} ${WRKSRC} -name "*.bat" -exec ${RM} {} \;
	@${MV} ${WRKSRC}/lib/LICENSE.barbecue.txt ${WRKSRC}/lib/LICENSE.barbecue-1.1.txt

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
