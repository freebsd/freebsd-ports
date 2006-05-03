# New ports collection makefile for:	adstudio
# Date created:				9 February 2005
# Whom:					Thierry Thomas <thierry@pompo.net>
#
# $FreeBSD$
#

PORTNAME=	adstudio
PORTVERSION=	4.7.2
CATEGORIES=	databases devel java
MASTER_SITES=	http://download.aquafold.com/download/v${PORTVERSION}/java/
DISTNAME=	ads-java-novm-${PORTVERSION}

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	A database query and administration tool

RUN_DEPENDS=	java:${PORTSDIR}/java/javavmwrapper

USE_ZIP=	yes
USE_JAVA=	yes
JAVA_VERSION=	1.5+
NO_BUILD=	yes

RESTRICTED=	See <http://www.aquafold.com/licensing.html>
NO_CDROM=	${RESTRICTED}

WRKSRC=		${WRKDIR}/datastudio

INSTFILES=	License.txt PAD_FILE.XML changelog.txt datastudio.gif	\
		datastudio.ico lib license

pre-configure:
	${REINPLACE_CMD} -e "s|%%ADS_HOME%%|${DATADIR}|"	\
		-e "s|^java |JAVA_VERSION=${JAVA_VERSION} ${LOCALBASE}/bin/java -Xmx256M |"	\
		${WRKSRC}/datastudio.sh

do-install:
	${MKDIR} ${DATADIR}
	${CP} -R ${INSTFILES:S|^|${WRKSRC}/|} ${DATADIR}
	${INSTALL_SCRIPT} ${WRKSRC}/datastudio.sh ${PREFIX}/bin

post-install:
	@${ECHO_MSG}
	@${CAT} ${PKGMESSAGE}
	@${ECHO_MSG}

.include <bsd.port.mk>
