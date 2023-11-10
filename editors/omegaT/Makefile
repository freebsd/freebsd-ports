PORTNAME=	omegaT
DISTVERSION=	6.0.0
CATEGORIES=	editors java x11
MASTER_SITES=	SF/${PORTNAME:tl}/OmegaT%20-%20Standard/OmegaT%20${DISTVERSION}/
DISTNAME=	OmegaT_${DISTVERSION}_Without_JRE
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	rodrigo@FreeBSD.org
COMMENT=	Powerful translation memory application written in Java
WWW=		https://omegat.org/

LICENSE=	GPLv3

RUN_DEPENDS=	${LOCALBASE}/bin/bash:shells/bash

USES=		desktop-file-utils shebangfix zip
USE_JAVA=	yes
JAVA_VERSION=	11
JAVA_VENDOR=	openjdk
JAVA_RUN=	yes

SHEBANG_FILES=		linux-install.sh OmegaT omegat.kaptn
SHEBANG_LANG=		kaptain
kaptain_OLD_CMD=	/usr/bin/kaptain
kaptain_CMD=		${LOCALBASE}/bin/kaptain # removed on 2019-03-16

NO_ARCH=	yes
NO_BUILD=	yes

ICON_SIZES=	32 128 256 512

pre-configure:
	${REINPLACE_CMD} -e 's|"java"|${JAVA}|' ${WRKSRC}/OmegaT

do-install:
	${MKDIR} ${STAGEDIR}${DATADIR} ${STAGEDIR}${DESKTOPDIR}
	cd  ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR}
	${CHMOD} a+x ${STAGEDIR}${DATADIR}/OmegaT
	${RLN} ${STAGEDIR}${DATADIR}/OmegaT ${STAGEDIR}${PREFIX}/bin/omegat
#${RLN} ${STAGEDIR}${DATADIR}/omegat.kaptn ${STAGEDIR}${PREFIX}/bin
	${MV} ${STAGEDIR}${DATADIR}/omegat.desktop ${STAGEDIR}${DESKTOPDIR}
.for sz in ${ICON_SIZES}
	${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/hicolor/${sz}x${sz}/apps
	${CP} -p ${STAGEDIR}${DATADIR}/images/OmegaT.iconset/icon_${sz}x${sz}.png	\
		${STAGEDIR}${PREFIX}/share/icons/hicolor/${sz}x${sz}/apps/omegat.png
.endfor

.include <bsd.port.mk>
