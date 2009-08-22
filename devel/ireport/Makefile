# New ports collection makefile for:	ireport
# Date created:		21 May 2005
# Whom:			Thierry Thomas <thierry@pompo.net>
#
# $FreeBSD$
#

PORTNAME=	ireport
PORTVERSION=	3.0.0
PORTREVISION=	2
CATEGORIES=	devel databases java
MASTER_SITES=	SF/${PORTNAME}/iReport%20%28classic%29/iReport-${PORTVERSION}
DISTNAME=	iReport-${PORTVERSION}

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	A visual report builder/designer for JasperReports

RUN_DEPENDS=	java:${PORTSDIR}/java/javavmwrapper					\
		${JAVALIBDIR}/bsh.jar:${PORTSDIR}/lang/bsh				\
		${JAVALIBDIR}/dom4j.jar:${PORTSDIR}/textproc/dom4j			\
		${JAVALIBDIR}/antlr.jar:${PORTSDIR}/devel/antlr				\
		${JAVALIBDIR}/looks.jar:${PORTSDIR}/devel/looks				\
		${JAVALIBDIR}/jaxen-full.jar:${PORTSDIR}/java/jaxen			\
		${JAVALIBDIR}/tinylaf.jar:${PORTSDIR}/devel/tinylaf			\
		${JAVALIBDIR}/bcel.jar:${PORTSDIR}/java/jakarta-bcel			\
		${JAVALIBDIR}/jcmdline.jar:${PORTSDIR}/devel/jcmdline			\
		${JAVALIBDIR}/xml-apis.jar:${PORTSDIR}/textproc/xerces-j		\
		${JAVALIBDIR}/jasperreports.jar:${PORTSDIR}/databases/jasperreports	\
		${JAVALIBDIR}/commons-dbcp.jar:${PORTSDIR}/java/jakarta-commons-dbcp	\
		${JAVALIBDIR}/commons-math.jar:${PORTSDIR}/math/jakarta-commons-math	\
		${JAVALIBDIR}/commons-pool.jar:${PORTSDIR}/java/jakarta-commons-pool	\
		${JAVALIBDIR}/commons-codec.jar:${PORTSDIR}/java/jakarta-commons-codec	\
		${JAVALIBDIR}/commons-httpclient.jar:${PORTSDIR}/java/jakarta-commons-httpclient

USE_JAVA=	yes
JAVA_VERSION=	1.4+
NO_BUILD=	yes

PLIST_SUB=	VER=${PORTVERSION} VERMAN=0.2.0

JARFILES=	JasperBabylon-1.0.0.jar LICENSE.asm-attr.txt LICENSE.asm.txt	\
		LICENSE.barbecue-1.1.txt LICENSE.jta.txt LICENSE.microba.txt	\
		asm-attrs.jar asm.jar batik-anim.jar batik-awt-util.jar		\
		batik-bridge.jar batik-css.jar batik-dom.jar batik-ext.jar	\
		batik-gvt.jar batik-parser.jar batik-script.jar			\
		batik-svg-dom.jar batik-svggen.jar batik-util.jar batik-xml.jar	\
		barbecue-1.5-beta1.jar cglib-2.1.jar cincom-jr-xmla.jar		\
		commons-javaflow-20060411.jar commons-vfs-1.0.jar		\
		ehcache-1.1.jar eigenbase-properties.jar eigenbase-resgen.jar	\
		eigenbase-xom.jar flexdock-0.4.1.jar groovy-all-1.5.5.jar	\
		hibernate3.jar iReport.jar iTextAsian.jar			\
		jasperreports-extensions-1.3.1.jar jasperreports-flash-2.0.5.jar\
		javacup.jar jdt-compiler-3.1.1.jar jpa.jar js_activation-1.1.jar\
		js_axis-1.4patched.jar js_commons-discovery-0.2.jar		\
		js_jasperserver-common-ws-3.0.0.jar				\
		js_jasperserver-ireport-plugin-3.0.0.jar js_jaxrpc.jar		\
		js_mail-1.4.jar js_wsdl4j-1.5.1.jar jsmoothgen-ant-0.9.7.jar	\
		jta.jar jxl-2.6.jar microba-0.4.1-bin.jar			\
		mondrian-2.3.2.8944.jar nsisant-1.1.jar png-encoder-1.5.jar	\
		rex-20080421.jar saaj-api-1.3.jar servlet.jar spring-2.0-m2.jar	\
		spring-context-2.0-m2.jar spring-hibernate3-2.0-m2.jar		\
		sqleonardo-2007.03.jar swingx-2007_05_13.jar toniclf.jar	\
		xml-apis-ext.jar
BASEFILES=	Changelog.txt notice.txt
SUBDIRS=	fonts plugins templates

# Jarfiles to be included in classpath
CLSSPTH=	JasperBabylon-1.0.0 antlr asm-attrs asm barbecue-1.5-beta1	\
		batik-anim batik-awt-util batik-bridge batik-css batik-dom	\
		batik-ext batik-gvt batik-parser batik-script batik-svg-dom	\
		batik-svggen batik-util batik-xml bsh cglib-2.1 cincom-jr-xmla	\
		commons-beanutils commons-codec commons-collections commons-dbcp\
		commons-digester commons-httpclient commons-javaflow-20060411	\
		commons-logging commons-logging-api commons-math commons-pool	\
		commons-vfs-1.0 dom4j ehcache-1.1 eigenbase-properties		\
		eigenbase-resgen eigenbase-xom flexdock-0.4.1 groovy-all-1.5.5	\
		hibernate3 iReport iTextAsian itext bcel jasperreports		\
		jasperreports-extensions-1.3.1 jasperreports-flash-2.0.5 javacup\
		jaxen-full jcmdline jcommon jdt-compiler-3.1.1 jfreechart jpa	\
		js_activation-1.1 js_axis-1.4patched js_commons-discovery-0.2	\
		js_jasperserver-common-ws-3.0.0					\
		js_jasperserver-ireport-plugin-3.0.0 js_jaxrpc js_mail-1.4	\
		js_wsdl4j-1.5.1 jsmoothgen-ant-0.9.7 jta jxl-2.6 log4j looks	\
		microba-0.4.1-bin mondrian-2.3.2.8944 mysql-connector-java	\
		nsisant-1.1 png-encoder-1.5 poi postgresql rex-20080421		\
		saaj-api-1.3 servlet spring-2.0-m2 spring-context-2.0-m2	\
		spring-hibernate3-2.0-m2 sqleonardo-2007.03 swingx-2007_05_13	\
		tinylaf toniclf xalan xercesImpl xml-apis xml-apis-ext		\
		${CLSSHSQLDB}

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
	${RM} -rf ${DATADIR}/fonts/font_licenses	# All GPL
.if !defined(NOPORTDOCS)
	#${LN} -sf ${DATADIR}/docs ${DOCSDIR}
.endif

post-install:
	@${ECHO_MSG}
	@${CAT} ${PKGMESSAGE}
	@${ECHO_MSG}

.include <bsd.port.post.mk>
