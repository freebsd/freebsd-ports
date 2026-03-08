PORTNAME=	violet
DISTVERSION=	2.3.0
PORTREVISION=	1
CATEGORIES=	devel editors java
MASTER_SITES=	SF/${PORTNAME}/violetumleditor/${DISTVERSION}-SNAPSHOT/
DISTNAME=	violetumleditor-${DISTVERSION}-SNAPSHOT
EXTRACT_SUFX=	.jar
EXTRACT_ONLY=

MAINTAINER=	alven@FreeBSD.org
COMMENT=	Easy to learn and use UML editor
WWW=		https://horstmann.com/violet/ \
		https://sourceforge.net/projects/violet/

LICENSE=	GPLv2

USES=		java

DATADIR=	${JAVASHAREDIR}/${PORTNAME}

NO_ARCH=	YES
NO_BUILD=	YES
SUB_FILES=	${PORTNAME}

PLIST_FILES=	${DATADIR}/violetumleditor.jar bin/${PORTNAME}

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/
	${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${DISTDIR}/${DISTNAME}.jar \
		${STAGEDIR}${DATADIR}/violetumleditor.jar

.include <bsd.port.mk>
