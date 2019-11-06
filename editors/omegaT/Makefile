# $FreeBSD$

PORTNAME=	omegaT
DISTVERSION=	3.6.0
CATEGORIES=	editors java x11
MASTER_SITES=	SF/${PORTNAME:tl}/OmegaT%20-%20Standard/OmegaT%20${DISTVERSION}%20update%204/
DISTNAME=	OmegaT_${DISTVERSION}_04_Source
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	rodrigo@FreeBSD.org
COMMENT=	Powerful translation memory application written in Java

BROKEN=		unfetchable

LICENSE=	GPLv2

USES=		shebangfix zip
SHEBANG_FILES=	release/linux-specific/OmegaT \
		release/linux-specific/OmegaT-JRE \
		release/linux-specific/omegat.kaptn
SHEBANG_LANG=	kaptain
kaptain_OLD_CMD=/usr/bin/kaptain
kaptain_CMD=	${LOCALBASE}/bin/kaptain
USE_ANT=	yes
USE_JAVA=	yes
JAVA_VENDOR=	openjdk
JAVA_VERSION=	1.7+
JAVA_BUILD=	yes
JAVA_RUN=	yes
NO_WRKSUBDIR=	yes
USE_LDCONFIG=	${DATADIR}/native
ALL_TARGET=	release

DATADIR=	${JAVASHAREDIR}/${PORTNAME}
SUB_FILES=	omegaT.sh omegat.prefs

DESKTOP_ENTRIES="OmegaT" "Translation memory application" \
		"${DATADIR}/images/OmegaT.png" \
		"omegaT" "Office;WordProcessor;Java;" \
		false
post-build:
	@cd ${WRKSRC} && ${MV} 'dist' ${PORTNAME}

do-install:
	@${MKDIR} ${STAGEDIR}${JAVASHAREDIR}/${PORTNAME}
	@cd  ${WRKSRC} && ${COPYTREE_BIN} ${PORTNAME} ${STAGEDIR}${JAVASHAREDIR}
	${INSTALL_SCRIPT} ${WRKDIR}/omegat.prefs ${STAGEDIR}${JAVASHAREDIR}/${PORTNAME}
	${INSTALL_SCRIPT} ${WRKDIR}/omegaT.sh ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
