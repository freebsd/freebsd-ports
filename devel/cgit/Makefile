PORTNAME=	cgit
DISTVERSION=	1.3
PORTREVISION=	1
CATEGORIES=	devel www
MASTER_SITES=	http://git.zx2c4.com/cgit/snapshot/:cgit \
		KERNEL_ORG/software/scm/git:git
DISTFILES=	cgit-${DISTVERSION}${EXTRACT_SUFX}:cgit \
		git-${GIT_VERSION}${EXTRACT_SUFX}:git

MAINTAINER=	mt-bugs@markoturk.info
COMMENT=	Fast, lightweight web frontend for Git repositories
WWW=		https://git.zx2c4.com/cgit/about/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

TEST_DEPENDS=	msgfmt:devel/gettext-tools

GIT_VERSION=	2.53.0
USES=		compiler:c++11-lang cpe gmake iconv perl5 python:env \
		shebangfix ssl tar:xz
CPE_VENDOR=	cgit_project
USE_PERL5=	test
SHEBANG_FILES=	filters/email-gravatar.py \
		filters/html-converters/md2html \
		filters/html-converters/rst2html \
		filters/syntax-highlighting.py

MAKE_ARGS+=	CGIT_SCRIPT_PATH=${WWWDIR} CGIT_CONFIG=${PREFIX}/etc/cgitrc \
		prefix=${PREFIX} NO_GETTEXT=1 NO_R_TO_GCC_LINKER=1 V=1

SUB_FILES=	pkg-message

PORTDOCS=	${PORTNAME}rc.5.txt

OPTIONS_DEFINE=		ASCIIDOC DOCS
OPTIONS_DEFAULT=	ASCIIDOC
OPTIONS_RADIO=		LUAS
OPTIONS_RADIO_LUAS=	LUA LUAJIT
OPTIONS_SUB=		yes

ASCIIDOC_DESC=	Use asciidoc to preprocess man page
LUAJIT_DESC=	${LUA_DESC} using luajit engine
LUAS_DESC=	${LUA_DESC}

ASCIIDOC_BUILD_DEPENDS=	a2x:textproc/asciidoc
LUAJIT_USES=		luajit pkgconfig
LUAJIT_MAKE_ARGS=	LUA_PKGCONFIG=luajit
LUA_USES=		lua pkgconfig
LUA_MAKE_ARGS=		LUA_PKGCONFIG=lua-${LUA_VER}

.include <bsd.port.options.mk>

.if !${PORT_OPTIONS:MLUA*}
MAKE_ARGS+=	NO_LUA=1
.endif

post-extract:
	@${RMDIR} ${WRKSRC}/git
	@${MV} ${WRKDIR}/git-${GIT_VERSION} ${WRKSRC}/git

post-patch:
	@${REINPLACE_CMD} -e 's/^\(GIT_VER =\).*$$/\1 ${GIT_VERSION}/' \
		${WRKSRC}/Makefile

	@${REINPLACE_CMD} -e 's/-liconv/${ICONV_LIB}/' \
		${WRKSRC}/git/Makefile

post-install:
	${STRIP_CMD} ${STAGEDIR}${WWWDIR}/cgit.cgi

post-install-ASCIIDOC-on:
	a2x --doctype manpage --format manpage ${WRKSRC}/cgitrc.5.txt
	${INSTALL_MAN} ${WRKSRC}/cgitrc.5 ${STAGEDIR}${PREFIX}/share/man/man5

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
