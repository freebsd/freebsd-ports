# Created by: Herve Quiroz <hq@FreeBSD.org>
# $FreeBSD$

PORTNAME=	dnsjava
PORTVERSION=	2.1.5
CATEGORIES=	dns java
MASTER_SITES=	http://www.dnsjava.org/download/

MAINTAINER=	danilogondolfo@gmail.com
COMMENT=	Implementation of DNS in Java

USE_JAVA=	yes
JAVA_VERSION=	1.6+

USE_ANT=	yes
ALL_TARGET=	jar

OPTIONS_DEFINE=	DOCS EXAMPLES

NO_STAGE=	yes
.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MEXAMPLES}
SAMPLE_FILES=	examples.html USAGE dig.java jnamed.java lookup.java update.java
PLIST_SUB+=	EXAMPLES=""
.else
PLIST_SUB+=	EXAMPLES="@comment "
.endif

.if ${PORT_OPTIONS:MDOCS}
ALL_TARGET+=	docs
OTHERDOCS=	README Changelog
PLIST_SUB+=	DOCS=""
.else
PLIST_SUB+=	DOCS="@comment "
.endif

do-install:
	@${MKDIR} ${JAVAJARDIR}
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}-${PORTVERSION}.jar ${JAVAJARDIR}/${PORTNAME}.jar
.if ${PORT_OPTIONS:MEXAMPLES}
	@${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${SAMPLE_FILES:S,^,${WRKSRC}/,} ${EXAMPLESDIR}/
.endif
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${TAR} -C ${WRKSRC}/doc -cf - . | ${TAR} -C ${DOCSDIR} -xf -
	${INSTALL_DATA} ${OTHERDOCS:S,^,${WRKSRC}/,} ${DOCSDIR}/
.endif

.include <bsd.port.post.mk>
