PORTNAME=	postgis-jdbc
PORTVERSION=	2.1.7
CATEGORIES=	databases java geography
MASTER_SITES=	http://postgis.net/stuff/
EXTRACT_SUFX=	.jar

MAINTAINER=	rhurlin@FreeBSD.org
COMMENT=	PostGIS spatial data structures for JDBC
WWW=		http://postgis.refractions.net

LICENSE=	GPLv2 LGPL21
LICENSE_COMB=	multi

RUN_DEPENDS=	${JAVALIBDIR}/postgresql.jar:databases/postgresql-jdbc

USES=		java zip:infozip
NO_BUILD=	yes
NO_ARCH=	yes

PLIST_FILES=	${JAVAJARDIR}/postgis-jdbc-2.1.7.jar

do-install:
	${INSTALL_DATA} ${_DISTDIR}/${PORTNAME}-${PORTVERSION}.jar ${STAGEDIR}${JAVAJARDIR}

.include <bsd.port.mk>
