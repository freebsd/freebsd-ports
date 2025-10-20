PORTNAME=	libime-jyutping
DISTVERSION=	1.0.13
PORTREVISION=	2
CATEGORIES=	chinese textproc
MASTER_SITES=	https://download.fcitx-im.org/fcitx5/${PORTNAME}/ \
		https://download.fcitx-im.org/data/:dict,model
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		${DICT_TAR}:dict \
		${MODEL_TAR}:model
DIST_SUBDIR=	${PORTNAME}
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	khng@FreeBSD.org
COMMENT=	Library to support Jyutping through libime
WWW=		https://github.com/fcitx/libime-jyutping

LICENSE=	GPLv3+ LGPL21+
LICENSE_COMB=	multi

BUILD_DEPENDS=	${LOCALBASE}/lib/fcitx5/libpunctuation.so:chinese/fcitx5-chinese-addons
LIB_DEPENDS=	libboost_iostreams.so:devel/boost-libs \
		libFcitx5Core.so:textproc/fcitx5 \
		libIMECore.so:chinese/libime
RUN_DEPENDS=	${LOCALBASE}/lib/fcitx5/libpunctuation.so:chinese/fcitx5-chinese-addons

USES=		cmake compiler:c++17-lang gettext-tools kde:5 localbase \
		pkgconfig tar:zst

PLIST_SUB=	VER=${PORTVERSION}

USE_LDCONFIG=	yes

USE_KDE=	ecm

CMAKE_ON=	ENABLE_ENGINE
CMAKE_OFF=	ENABLE_DOC ENABLE_TEST
MAKE_ENV=	FCITX5_DOWNLOAD_DISALLOWED=TRUE

# These must follow data/CMakeLists.txt
DICT_TAR=	jyutping-dict-20180104.tar.xz
MODEL_TAR=	jyutping-model-20180103.tar.xz

post-extract:
	${CP} ${DISTDIR}/${DIST_SUBDIR}/${DICT_TAR} ${WRKSRC}/data
	${CP} ${DISTDIR}/${DIST_SUBDIR}/${MODEL_TAR} ${WRKSRC}/data

.include <bsd.port.mk>
