PORTNAME=	JavaFX
DISTVERSION=	21.0.12	# Please check compatibility with math/scilab
CATEGORIES=	devel java
MASTER_SITES=	https://download2.gluonhq.com/openjfx/${PORTVERSION}/
DISTNAME=	openjfx-${PORTVERSION}_linux-x64_bin-sdk
PKGSUFFIX=	-jars

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	jar files provided by OpenJFX
WWW=		https://openjdk.org/projects/openjfx/

LICENSE=	GPLv2

USES=		java:run zip
JAVA_VERSION=	21

NO_BUILD=	yes
NO_ARCH=	yes

WRKSRC=		${WRKDIR}/javafx-sdk-${PORTVERSION}

do-install:
	@${MKDIR} ${STAGEDIR}${JAVAJARDIR}
	for jar in `${LS} ${WRKSRC}/lib/javafx*jar`; do \
		${INSTALL_DATA} $${jar} ${STAGEDIR}${JAVAJARDIR}/ ; \
	done

.include <bsd.port.mk>
