# New ports collection makefile for:	adstudio
# Date created:				9 February 2005
# Whom:					Thierry Thomas <thierry@pompo.net>
#
# $FreeBSD$
#

PORTNAME=	adstudio
PORTVERSION=	7.5.11
CATEGORIES=	databases devel java
MASTER_SITES=	http://download.aquafold.com/download/v${PORTVERSION:R}.0/java/
DISTNAME=	ads-java-novm-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A database query and administration tool

RUN_DEPENDS=	java:${PORTSDIR}/java/javavmwrapper	\
		${LOCALBASE}/lib/libjogl.so:${PORTSDIR}/graphics/jogl

USE_JAVA=	yes
JAVA_VERSION=	1.6+
NO_BUILD=	yes

RESTRICTED=	See <http://www.aquafold.com/licensing.html>
NO_CDROM=	${RESTRICTED}

WRKSRC=		${WRKDIR}/datastudio

INSTFILES=	License.txt changelog.txt datastudio-*.png datastudio.gif	\
		datastudio.ico lib license
INSTSCRIPTS=	datastudio runscript
EXTRACT_AFTER_ARGS=|${TAR} -xpf - ${INSTSCRIPTS:S|^|./datastudio/|:S|$|.sh|}

pre-configure:
	${REINPLACE_CMD} -e "s|%%ADS_HOME%%|${DATADIR}|"	\
		-e "s|^java |JAVA_VERSION=${JAVA_VERSION} exec ${LOCALBASE}/bin/java -Xmx256M |"	\
		${INSTSCRIPTS:S|^|${WRKSRC}/|:S|$|.sh|}

do-install:
	${MKDIR} ${DATADIR}
	${TAR} -C ${DATADIR} -xpf ${DISTDIR}/${_DISTFILES}	\
		${INSTFILES:S|^|./datastudio/|}
	${MV} ${DATADIR}/datastudio/* ${DATADIR}
	${RMDIR} ${DATADIR}/datastudio
	${INSTALL_SCRIPT} ${INSTSCRIPTS:S|^|${WRKSRC}/|:S|$|.sh|} ${PREFIX}/bin

post-install:
	@${ECHO_MSG}
	@${CAT} ${PKGMESSAGE}
	@${ECHO_MSG}

.include <bsd.port.mk>
