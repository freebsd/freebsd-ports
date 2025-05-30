PORTNAME=	dnsjava
DISTVERSIONPREFIX=	v
DISTVERSION=	2.1.9
CATEGORIES=	dns java

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Implementation of DNS in Java
WWW=		https://github.com/dnsjava/dnsjava/

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		java:ant
USE_GITHUB=	yes
JAVA_VERSION=	8

ALL_TARGET=	jar
NO_ARCH=	yes

OPTIONS_DEFINE=	DOCS EXAMPLES

SAMPLE_FILES=	EXAMPLES.md USAGE dig.java jnamed.java lookup.java update.java
OTHERDOCS=	README.md Changelog
DOCS_ALL_TARGET=	docs

post-patch:
	@${REINPLACE_CMD} "s/2\.1\.8/${DISTVERSION}/" ${WRKSRC}/build.xml

do-install:
	@${MKDIR} ${STAGEDIR}${JAVAJARDIR}
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}-${DISTVERSION}.jar \
		${STAGEDIR}${JAVAJARDIR}/${PORTNAME}.jar

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${TAR} -C ${WRKSRC}/doc -cf - . | ${TAR} -C ${STAGEDIR}${DOCSDIR} -xf -
	${INSTALL_DATA} ${OTHERDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}/

do-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${SAMPLE_FILES:S,^,${WRKSRC}/,} ${STAGEDIR}${EXAMPLESDIR}/

.include <bsd.port.mk>
