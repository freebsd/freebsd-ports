# Created by: Herve Quiroz <hq@FreeBSD.org>
# $FreeBSD$

PORTNAME=	dnsjava
PORTVERSION=	2.1.8
CATEGORIES=	dns java
MASTER_SITES=	http://www.dnsjava.org/download/

MAINTAINER=	danilo@FreeBSD.org
COMMENT=	Implementation of DNS in Java

BROKEN=		unfetchable

USE_JAVA=	yes
JAVA_VERSION=	1.6+
USE_ANT=	yes
ALL_TARGET=	jar
NO_ARCH=	yes

OPTIONS_DEFINE=	DOCS EXAMPLES

SAMPLE_FILES=	examples.html USAGE dig.java jnamed.java lookup.java update.java
OTHERDOCS=	README Changelog
DOCS_ALL_TARGET=	docs

.include <bsd.port.pre.mk>

.if ${JAVA_PORT_VERSION:M*6*}
PLIST_SUB+=	JDK6=""
.else
PLIST_SUB+=	JDK6="@comment "
.endif
.if ${JAVA_PORT_VERSION:M*8*}
PLIST_SUB+=	JDK8=""
.else
PLIST_SUB+=	JDK8="@comment "
.endif

do-install:
	@${MKDIR} ${STAGEDIR}${JAVAJARDIR}
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}-${PORTVERSION}.jar ${STAGEDIR}${JAVAJARDIR}/${PORTNAME}.jar

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${TAR} -C ${WRKSRC}/doc -cf - . | ${TAR} -C ${STAGEDIR}${DOCSDIR} -xf -
	${INSTALL_DATA} ${OTHERDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}/

do-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${SAMPLE_FILES:S,^,${WRKSRC}/,} ${STAGEDIR}${EXAMPLESDIR}/

.include <bsd.port.post.mk>
