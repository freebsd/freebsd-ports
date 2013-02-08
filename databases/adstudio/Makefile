# Created by: Thierry Thomas <thierry@pompo.net>
# $FreeBSD$

PORTNAME=	adstudio
PORTVERSION=	10.0.11
CATEGORIES=	databases devel java
MASTER_SITES=	http://dd1.aquafold.com/download/v${PORTVERSION:R}.0/java/ \
		http://dd1.aquafold.com/download/v${PORTVERSION:R}.0/:patch
DISTFILES=	ads-java-novm-10.0.10${EXTRACT_SUFX} ads-${PORTVERSION}-patch.zip:patch

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A database query and administration tool

LICENSE=	EULA
LICENSE_NAME=	EULA
LICENSE_FILE=	${WRKSRC}/${INSTLICENSE}
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

RUN_DEPENDS=	java:${PORTSDIR}/java/javavmwrapper	\
		${LOCALBASE}/lib/libjogl.so:${PORTSDIR}/graphics/jogl

DEPRECATED=	Broken for more than 6 month
EXPIRATION_DATE=	2013-03-05
BROKEN=		incomplete plist

USE_JAVA=	yes
JAVA_VERSION=	1.6+
NO_BUILD=	yes

RESTRICTED=	See <http://www.aquafold.com/licensing.html>

WRKSRC=		${WRKDIR}/datastudio

INSTFILES=	changelog.txt datastudio-*.png datastudio.gif	\
		datastudio.ico lib license
INSTSCRIPTS=	datastudio runscript
INSTLICENSE=	License.txt
EXTRACT_ONLY=	${_DISTFILES:M*tar.gz}
EXTRACT_AFTER_ARGS=|${TAR} -xpf - ${INSTSCRIPTS:S|^|./datastudio/|:S|$|.sh|} ${INSTLICENSE:S|^|./datastudio/|}

pre-configure:
	${REINPLACE_CMD} -e "s|%%ADS_HOME%%|${DATADIR}|"	\
		-e "s|^java |JAVA_VERSION=${JAVA_VERSION} exec ${LOCALBASE}/bin/java -Xmx256M |"	\
		${INSTSCRIPTS:S|^|${WRKSRC}/|:S|$|.sh|}

do-install:
	${MKDIR} ${DATADIR}
	# Extracting the base version:
	${TAR} -C ${DATADIR} -xpf ${DISTDIR}/${EXTRACT_ONLY}	\
		${INSTFILES:S|^|./datastudio/|}
	# Patching:
	${TAR} -C ${DATADIR}/datastudio/ -xpf ${DISTDIR}/${_DISTFILES:M*zip}
	${MV} ${DATADIR}/datastudio/* ${DATADIR}
	${RMDIR} ${DATADIR}/datastudio
	${INSTALL_SCRIPT} ${INSTSCRIPTS:S|^|${WRKSRC}/|:S|$|.sh|} ${PREFIX}/bin

post-install:
	@${ECHO_MSG}
	@${CAT} ${PKGMESSAGE}
	@${ECHO_MSG}

.include <bsd.port.mk>
