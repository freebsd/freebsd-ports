# New ports collection makefile for:	ireport
# Date created:		21 May 2005
# Whom:			Thierry Thomas <thierry@pompo.net>
#
# $FreeBSD$
#

PORTNAME=	ireport
PORTVERSION=	3.7.4
CATEGORIES=	devel databases java
MASTER_SITES=	SF/${PORTNAME}/iReport/iReport-${PORTVERSION}
DISTNAME=	iReport-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A visual report builder/designer for JasperReports

RUN_DEPENDS=	java:${PORTSDIR}/java/javavmwrapper					\
		${JAVALIBDIR}/bsh.jar:${PORTSDIR}/lang/bsh				\
		${JAVALIBDIR}/axis.jar:${PORTSDIR}/www/axis				\
		${JAVALIBDIR}/antlr.jar:${PORTSDIR}/devel/antlr				\
		${JAVALIBDIR}/looks.jar:${PORTSDIR}/devel/looks				\
		${JAVALIBDIR}/mail.jar:${PORTSDIR}/java/javamail			\
		${JAVALIBDIR}/castor.jar:${PORTSDIR}/java/castor			\
		${JAVALIBDIR}/groovy.jar:${PORTSDIR}/lang/groovy			\
		${JAVALIBDIR}/activation.jar:${PORTSDIR}/java/jaf			\
		${JAVALIBDIR}/dom4j.jar:${PORTSDIR}/textproc/dom4j			\
		${JAVALIBDIR}/jaxen-full.jar:${PORTSDIR}/java/jaxen			\
		${JAVALIBDIR}/tinylaf.jar:${PORTSDIR}/devel/tinylaf			\
		${JAVALIBDIR}/slf4j-api.jar:${PORTSDIR}/devel/slf4j			\
		${JAVALIBDIR}/bcel.jar:${PORTSDIR}/java/jakarta-bcel			\
		${JAVASHAREDIR}/rhino/rhino.jar:${PORTSDIR}/lang/rhino			\
		${JAVALIBDIR}/barbecue.jar:${PORTSDIR}/graphics/barbecue		\
		${JAVALIBDIR}/xml-apis.jar:${PORTSDIR}/textproc/xerces-j		\
		${JAVALIBDIR}/spring.jar:${PORTSDIR}/java/springframework		\
		${JAVASHAREDIR}/apache-ant/lib/ant.jar:${PORTSDIR}/devel/apache-ant	\
		${JAVALIBDIR}/jasperreports.jar:${PORTSDIR}/databases/jasperreports	\
		${JAVALIBDIR}/commons-math.jar:${PORTSDIR}/math/jakarta-commons-math	\
		${JAVALIBDIR}/commons-pool.jar:${PORTSDIR}/java/jakarta-commons-pool	\
		${JAVALIBDIR}/commons-codec.jar:${PORTSDIR}/java/jakarta-commons-codec	\
		${JAVALIBDIR}/commons-discovery.jar:${PORTSDIR}/java/jakarta-commons-discovery	\
		${JAVALIBDIR}/commons-httpclient.jar:${PORTSDIR}/java/jakarta-commons-httpclient

USE_JAVA=	yes
JAVA_VERSION=	1.5+
USE_DOS2UNIX=	*.txt
NO_BUILD=	yes

#LICENSE=	GNU AFFERO GPL
LICENSE_FILE=	${WRKSRC}/LICENSE_ireport.txt

PLIST_SUB=	VER=${PORTVERSION} VERMAN=0.2.0

# Installed files
JARFILES=	asm-attrs.jar asm.jar barcode4j-2.0-LICENSE.txt			\
		barcode4j-2.0-NOTICE.txt barcode4j-2.0.jar cglib-2.1.jar	\
		cincom-jr-xmla.jar commons-javaflow-20060411.jar		\
		commons-vfs-1.0.jar ehcache-1.1.jar				\
		eigenbase-properties-1.1.0.10924.jar				\
		eigenbase-resgen-1.3.0.11873.jar eigenbase-xom-1.3.0.11999.jar	\
		ejb3-persistence.jar hibernate-annotations.jar			\
		hibernate-commons-annotations.jar hibernate3-LICENSE.txt	\
		hibernate3.jar iText-2.1.7-LICENSE.txt iText-2.1.7.jar		\
		iTextAsian.jar jasperreports-chart-themes-3.7.4.jar		\
		jasperreports-extensions-3.5.3.jar jasperreports-fonts-3.7.4.jar\
		javacup.jar javassist-3.4.GA.jar jdt-compiler-3.1.1-LICENSE.html\
		jdt-compiler-3.1.1.jar jpa.jar					\
		js_jasperserver-common-ws-3.5.0.jar js_saaj-api-1.3.jar		\
		js_wsdl4j-1.5.1.jar jta.jar jxl-2.6-LICENSE.txt jxl-2.6.jar	\
		mondrian-3.1.1.12687-Jaspersoft.jar				\
		mondrian-3.1.1.12687-LICENSE.html olap4j-0.9.7.145.jar		\
		png-encoder-1.5.jar rex-20080421.jar saaj-api-1.3.jar		\
		sqleonardo-2007.03.jar swingx-2007_10_07.jar xml-apis-ext.jar
CJSFILES=	com-jaspersoft-ireport-addons.jar		\
		com-jaspersoft-ireport-components.jar		\
		com-jaspersoft-ireport-designer-standalone.jar	\
		com-jaspersoft-ireport-heartbeat.jar		\
		com-jaspersoft-ireport-jasperserver.jar		\
		com-jaspersoft-ireport-samples.jar		\
		com-jaspersoft-ireport.jar			\
		com-jaspersoft-jrx.jar
BASEFILES=	Changelog.txt notice.txt

# Jarfiles to be included in classpath
CLSSPTH=	ant antlr asm-attrs asm barbecue barcode4j-2.0 batik batik-anim	\
		batik-awt-util batik-bridge batik-css batik-dom batik-ext	\
		batik-gvt batik-parser batik-script batik-svg-dom batik-svggen	\
		batik-util batik-xml bcel bsh castor cglib-2.1 cincom-jr-xmla	\
		commons-beanutils commons-collections commons-digester		\
		commons-javaflow-20060411 commons-logging commons-math		\
		commons-pool commons-vfs-1.0 crimson dom4j ehcache-1.1		\
		eigenbase-properties-1.1.0.10924 eigenbase-resgen-1.3.0.11873	\
		eigenbase-xom-1.3.0.11999 ejb3-persistence groovy		\
		hibernate-annotations hibernate-commons-annotations hibernate3	\
		itext iText-2.1.7 iTextAsian jasperreports			\
		jasperreports-chart-themes-3.7.4 jasperreports-extensions-3.5.3	\
		jasperreports-fonts-3.7.4 javacup javassist-3.4.GA  jaxen-full	\
		jcommon jdt-compiler-3.1.1 jfreechart jpa activation axis	\
		commons-codec commons-discovery commons-httpclient		\
		js_jasperserver-common-ws-3.5.0 jaxrpc mail js_saaj-api-1.3	\
		js_wsdl4j-1.5.1 jta jxl-2.6 log4j				\
		mondrian-3.1.1.12687-Jaspersoft olap4j-0.9.7.145 png-encoder-1.5\
		poi rex-20080421 rhino saaj-api-1.3 slf4j-api slf4j-log4j12	\
		spring sqleonardo-2007.03 swingx-2007_10_07 xalan xml-apis-ext	\
		xml-apis							\
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

# jakarta-commons-dbcp-1.2.2 is marked as broken:
# does not build unless jakarta-commons-collections is compiled with jdk15.
.if exists(${JAVALIBDIR}/commons-dbcp.jar)
RUN_DEPENDS+=	${JAVALIBDIR}/commons-dbcp.jar:${PORTSDIR}/java/jakarta-commons-dbcp
CLSSPTH+=	commons-dbcp
.else
JARFILES+=	commons-dbcp-1.2.2.jar
CLSSPTH+=	commons-dbcp-1.2.2
.endif

post-extract:
	${CP} ${FILESDIR}/startup.sh ${WRKSRC}/bin/
	${RM} ${WRKSRC}/bin/*.exe

pre-configure:
	${REINPLACE_CMD} -e 's|%%PORTVERSION%%|${PORTVERSION}|;			\
		s|%%CLSSPTH%%|${CLSSPTH:S,^,${JAVALIBDIR}/,g:S,$,.jar£,g}|'	\
		-e 's|jar£ |jar\:|g;						\
		s|£|:${JAVA_HOME}/lib/tools.jar${CLSSORA:S,^,\:${JAVALIBDIR}/,g}|;	\
		s|${JAVALIBDIR}/batik|${JAVASHAREDIR}/batik/lib/batik|g;	\
		s|${JAVALIBDIR}/rhino.jar|${JAVASHAREDIR}/rhino/rhino.jar|;	\
		s|${JAVALIBDIR}/ant.jar|${JAVASHAREDIR}/apache-ant/lib/ant.jar|;\
		s|zip |zip|g; s|jar |jar|g'					\
		-e 's|%%JAVA_HOME%%|${JAVA_HOME}|;				\
		s|%%DATADIR%%|${DATADIR}|g;					\
		s|^java |JAVA_VERSION="${JAVA_VERSION}" ${LOCALBASE}/bin/java |'\
		${WRKSRC}/bin/startup.sh
	${REINPLACE_CMD} -e 's|/bin/grep|/usr/bin/grep|' ${WRKSRC}/platform9/lib/nbexec

do-install:
	${MKDIR} ${DATADIR}
	(cd ${WRKSRC} && ${COPYTREE_SHARE} \* ${DATADIR})
	${CHMOD} ${BINMODE} ${DATADIR}/bin/startup.sh
	${LN} -sf ${DATADIR}/bin/startup.sh ${PREFIX}/bin/iReport
	${RM} -rf ${DATADIR}/ireport/modules/ext
	${INSTALL_DATA} ${JARFILES:S|^|${WRKSRC}/ireport/modules/ext/|} ${JAVAJARDIR}
	${LN} -sf ${JAVAJARDIR} ${DATADIR}/ireport/modules/ext

.include <bsd.port.post.mk>
