# New ports collection makefile for:	tonicpoint-viewer
# Date created:		2007-02-06
# Whom:			ports@c0decafe.net
#
# $FreeBSD$
#

PORTNAME=	viewer
PORTVERSION=	1.4
PORTREVISION=	2
CATEGORIES=	graphics java
MASTER_SITES=	http://downloads.tonicsystems.com/viewer/
PKGNAMEPREFIX=	tonicpoint-
DISTNAME=	tonicpoint-${PORTVERSION}
EXTRACT_SUFX=	.jar
EXTRACT_ONLY=

MAINTAINER=	ports@FreeBSD.org
COMMENT=	PowerPoint presentations viewer

NO_CDROM=	free for non-commercial use

USE_JAVA=	yes
JAVA_VERSION=	1.5+

NO_WRKSUBDIR=	yes
NO_BUILD=	yes

BINNAME=	tonicpoint
JARFILE=	${BINNAME}.jar
PLIST_FILES=	%%JAVAJARDIR%%/${JARFILE} bin/${BINNAME}

do-configure:
	@${SED}	-e 's|%%LOCALBASE%%|${LOCALBASE}|;'\
		-e 's|%%JAVAJARDIR%%|${JAVAJARDIR}|;'\
		-e 's|%%JARFILE%%|${JARFILE}|;' \
	${FILESDIR}/${BINNAME} > ${WRKSRC}/${BINNAME}

do-install:
	@${MKDIR} ${JAVAJARDIR}
	${INSTALL_DATA} ${DISTDIR}/${DISTNAME}.jar ${JAVAJARDIR}/${JARFILE}
	${INSTALL_SCRIPT} ${WRKSRC}/${BINNAME} ${PREFIX}/bin/${BINNAME}

.include <bsd.port.mk>
