PORTNAME=	openapi-generator
DISTVERSION=	7.22.0
CATEGORIES=	devel java
MASTER_SITES=	https://github.com/OpenAPITools/${PORTNAME}/releases/download/v${DISTVERSION}/
DISTNAME=	${PORTNAME}-cli-${DISTVERSION}
EXTRACT_SUFX=	.jar
EXTRACT_ONLY=	# empty

MAINTAINER=	kde@FreeBSD.org
COMMENT=	OpenAPI Generator CLI
WWW=		https://openapi-generator.tech/

LICENSE=	APACHE20

USES=		java:run

NO_ARCH=	yes
NO_BUILD=	yes

PLIST_FILES=	bin/openapi-generator \
		${JAVAJARDIR}/openapi-generator-cli.jar

do-install:
	${INSTALL_DATA} ${DISTDIR}/${DISTNAME}${EXTRACT_SUFX} \
		${STAGEDIR}${JAVAJARDIR}/openapi-generator-cli.jar
	${PRINTF} "#!/bin/sh\nexec ${JAVA} -jar ${JAVAJARDIR}/openapi-generator-cli.jar \"\$$@\"\n" \
		> ${STAGEDIR}${PREFIX}/bin/openapi-generator
	${CHMOD} +x ${STAGEDIR}${PREFIX}/bin/openapi-generator

.include <bsd.port.mk>
