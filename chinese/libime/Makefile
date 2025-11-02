PORTNAME=	libime
DISTVERSION=	1.1.12
CATEGORIES=	chinese textproc
MASTER_SITES=	https://download.fcitx-im.org/fcitx5/${PORTNAME}/ \
		https://download.fcitx-im.org/data/:opengram_lm,opengram_dict,table_dict
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		${OPENGRAM_LM_TAR}:opengram_lm \
		${OPENGRAM_DICT_TAR}:opengram_dict \
		${TABLE_DICT_TAR}:table_dict
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	khng@FreeBSD.org
COMMENT=	Library to support generic input method implementation
WWW=		https://github.com/fcitx/libime

LICENSE=	LGPL21

LIB_DEPENDS=	libboost_filesystem.so:devel/boost-libs \
		libFcitx5Utils.so:textproc/fcitx5

USES=		cmake compiler:c++17-lang kde:5 pkgconfig tar:zst

PLIST_SUB=	VER=${PORTVERSION} \
		VER_MAJOR=${PORTVERSION:R:R}

USE_LDCONFIG=	yes

USE_KDE=	ecm

CMAKE_OFF=	ENABLE_TEST
MAKE_ENV=	FCITX5_DOWNLOAD_DISALLOWED=TRUE

# These must follow data/CMakeLists.txt
OPENGRAM_LM_TAR=	lm_sc.arpa-20250113.tar.zst
OPENGRAM_DICT_TAR=	dict-20250327.tar.zst
TABLE_DICT_TAR=		table-20240108.tar.zst

.include <bsd.port.pre.mk>

post-patch:
.if ${COMPILER_TYPE} == clang
	@${REINPLACE_CMD} -e 's|std::binary_function|std::__binary_function|' \
		${WRKSRC}/src/libime/core/kenlm/lm/trie_sort.hh \
		${WRKSRC}/src/libime/core/kenlm/util/joint_sort.hh \
		${WRKSRC}/src/libime/core/kenlm/util/sized_iterator.hh
.endif


post-extract:
	${CP} ${DISTDIR}/${DIST_SUBDIR}/${OPENGRAM_LM_TAR} ${WRKSRC}/data
	${CP} ${DISTDIR}/${DIST_SUBDIR}/${OPENGRAM_DICT_TAR} ${WRKSRC}/data
	${CP} ${DISTDIR}/${DIST_SUBDIR}/${TABLE_DICT_TAR} ${WRKSRC}/data

.include <bsd.port.post.mk>
