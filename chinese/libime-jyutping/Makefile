# Created by: Ka Ho Ng <khng300@gmail.com>

PORTNAME=	libime-jyutping
DISTVERSION=	1.0.3
CATEGORIES=	chinese textproc
MASTER_SITES=	https://download.fcitx-im.org/data/:dict,model
DISTFILES=	${DICT_TAR}:dict \
		${MODEL_TAR}:model
DIST_SUBDIR=	${PORTNAME}
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	khng@FreeBSD.org
COMMENT=	Library to support Jyutping through libime

LICENSE=	LGPL21+ GPLv3+
LICENSE_COMB=	multi

BUILD_DEPENDS=	${LOCALBASE}/lib/fcitx5/punctuation.so:chinese/fcitx5-chinese-addons
LIB_DEPENDS=	libboost_iostreams.so:devel/boost-libs \
		libIMECore.so:chinese/libime \
		libFcitx5Core.so:textproc/fcitx5
RUN_DEPENDS=	${LOCALBASE}/lib/fcitx5/punctuation.so:chinese/fcitx5-chinese-addons

USES=		compiler:c++17-lang cmake gettext-tools kde:5 localbase

PLIST_SUB=	VER=${PORTVERSION}

USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	fcitx

USE_KDE=	ecm

CMAKE_ON=	ENABLE_ENGINE
CMAKE_OFF=	ENABLE_TEST ENABLE_DOC
MAKE_ENV=	FCITX5_DOWNLOAD_DISALLOWED=TRUE

# These must follow data/CMakeLists.txt
DICT_TAR=	jyutping-dict-20180104.tar.xz
MODEL_TAR=	jyutping-model-20180103.tar.xz

post-extract:
	${CP} ${DISTDIR}/${DIST_SUBDIR}/${DICT_TAR} ${WRKSRC}/data
	${CP} ${DISTDIR}/${DIST_SUBDIR}/${MODEL_TAR} ${WRKSRC}/data

.include <bsd.port.mk>
