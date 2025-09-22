PORTNAME=	restarter
DISTVERSION=	2025.2.2
CATEGORIES=	devel
PKGNAMEPREFIX=	jetbrains-
DIST_SUBDIR=	jetbrains

MAINTAINER=	dmitry.wagin@ya.ru
COMMENT=	IntelliJ cross-platform restarter
WWW=		https://github.com/JetBrains/intellij-community/tree/master/native/restarter

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/../../LICENSE.txt

ONLY_FOR_ARCHS=	aarch64 amd64 powerpc64le

USES=		cargo

USE_GITHUB=	yes
GH_ACCOUNT=	JetBrains
GH_PROJECT=	intellij-community
GH_TAGNAME=	idea/2025.2.2

DATADIR=	${PREFIX}/share/jetbrains/${PORTNAME}
WRKSRC_SUBDIR=	native/restarter
PLIST_FILES=	share/jetbrains/${PORTNAME}/restarter

do-install:
	${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_PROGRAM} \
		${CARGO_TARGET_DIR}/*/restarter \
		${STAGEDIR}${DATADIR}

post-install:
	${STRIP_CMD} ${STAGEDIR}${DATADIR}/restarter

.include <bsd.port.mk>
