PORTNAME=	libime
DISTVERSION=	1.0.9
PORTREVISION=	1
CATEGORIES=	chinese textproc
MASTER_SITES=	https://download.fcitx-im.org/data/:opengram_lm,opengram_dict,table_dict
DISTFILES=	${OPENGRAM_LM_TAR}:opengram_lm \
		${OPENGRAM_DICT_TAR}:opengram_dict \
		${TABLE_DICT_TAR}:table_dict
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	khng@FreeBSD.org
COMMENT=	Library to support generic input method implementation

LICENSE=	LGPL21

LIB_DEPENDS=	libboost_filesystem.so:devel/boost-libs \
		libFcitx5Utils.so:textproc/fcitx5

USES=		compiler:c++17-lang cmake kde:5

PLIST_SUB=	VER=${PORTVERSION} VER_MAJOR=${PORTVERSION:R:R}

USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	fcitx
GH_TUPLE=	kpu:kenlm:01c49fe:kenlm/src/libime/core/kenlm

USE_KDE=	ecm

CMAKE_OFF=	ENABLE_TEST
MAKE_ENV=	FCITX5_DOWNLOAD_DISALLOWED=TRUE

# These must follow data/CMakeLists.txt
OPENGRAM_LM_TAR=	lm_sc.3gm.arpa-20140820.tar.bz2
OPENGRAM_DICT_TAR=	dict.utf8-20211021.tar.xz
TABLE_DICT_TAR=		table.tar.gz

post-extract:
	${CP} ${DISTDIR}/${DIST_SUBDIR}/${OPENGRAM_LM_TAR} ${WRKSRC}/data
	${CP} ${DISTDIR}/${DIST_SUBDIR}/${OPENGRAM_DICT_TAR} ${WRKSRC}/data
	${CP} ${DISTDIR}/${DIST_SUBDIR}/${TABLE_DICT_TAR} ${WRKSRC}/data

.include <bsd.port.mk>
