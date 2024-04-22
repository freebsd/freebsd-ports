PORTNAME=	mdbtools
DISTVERSION=	1.0.0
PORTREVISION=	2
CATEGORIES=	databases
MASTER_SITES=	https://github.com/${PORTNAME}/${PORTNAME}/releases/download/v${DISTVERSION}/

MAINTAINER=	rhurlin@FreeBSD.org
COMMENT=	Utilities and libraries to export data from MS Access databases (.mdb)
WWW=		https://github.com/mdbtools/mdbtools/

LICENSE=	GPLv2

BUILD_DEPENDS=	bash-completion>=0:shells/bash-completion \
		flex:textproc/flex \
		gawk:lang/gawk
LIB_DEPENDS=	libodbcinst.so:databases/unixODBC
RUN_DEPENDS=	bash-completion>=0:shells/bash-completion

USES=		bison cpe gnome iconv:wchar_t libtool pathfix \
		pkgconfig readline
CPE_VENDOR=	mdbtools_project
USE_GNOME=	glib20
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=	${PREFIX}/share
CONFIGURE_ARGS=	${ICONV_CONFIGURE_ARG} \
		--with-unixodbc=${LOCALBASE}

INSTALL_TARGET=	install-strip

OPTIONS_DEFINE=		DOCS MANPAGES LIBMSWSTR NLS
OPTIONS_DEFAULT=	MANPAGES
OPTIONS_SUB=		yes

LIBMSWSTR_DESC=	Read and parse JET 4 mdb file indices

LIBMSWSTR_LIB_DEPENDS=		libmswstr.so:databases/libmswstr
LIBMSWSTR_CONFIGURE_ENV_OFF=	ac_cv_lib_mswstr_DBLCMapStringW=no
MANPAGES_CONFIGURE_OFF=		--disable-man
NLS_USES=			gettext

DOCS=		AUTHORS HACKING.md NEWS README.md

.include <bsd.port.pre.mk>

.if ${LLVM_DEFAULT} >= 15
# With LLVM15:  parser.c:1053:9: error:
# variable 'yynerrs' set but not used [-Werror,-Wunused-but-set-variable]
BUILD_DEPENDS+=	llvm-config${LLVM_VER}:devel/llvm${LLVM_VER}
LLVM_VER=	14
#CMAKE_ARGS+=	-DLLVM_DIR=${LOCALBASE}/llvm${LLVM_VER}/lib/cmake/llvm
CC=		clang${LLVM_VER}
CPP=		clang-cpp${LLVM_VER}
CXX=		clang++${LLVM_VER}
.endif

post-configure:
	@${REINPLACE_CMD} -e \
		's|libdir = $${exec_prefix}/lib/odbc|libdir = $${exec_prefix}/lib|' \
		${WRKSRC}/src/odbc/Makefile

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${DOCS:S,^,${WRKSRC}/,}  ${STAGEDIR}${DOCSDIR}

.include <bsd.port.post.mk>
