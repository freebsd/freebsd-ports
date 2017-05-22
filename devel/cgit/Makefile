# $FreeBSD$

PORTNAME=	cgit
PORTVERSION=	1.1
PORTREVISION=	4
CATEGORIES=	devel www
MASTER_SITES=	http://git.zx2c4.com/cgit/snapshot/:cgit \
		https://www.kernel.org/pub/software/scm/git/:git
DISTFILES=	cgit-${PORTVERSION}${EXTRACT_SUFX}:cgit \
		git-${GIT_VERSION}${EXTRACT_SUFX}:git

MAINTAINER=	adamw@FreeBSD.org
COMMENT=	Fast, lightweight web frontend for Git repositories

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

GIT_VERSION=	2.13.0
USES=		cpe gmake iconv shebangfix ssl tar:xz
CPE_VENDOR=	lars_hjemli
SHEBANG_FILES=	filters/html-converters/rst2html

CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib ${ICONV_LIB}
MAKE_ARGS+=	CGIT_SCRIPT_PATH=${WWWDIR} CGIT_CONFIG=${PREFIX}/etc/cgitrc \
		prefix=${PREFIX} NO_GETTEXT=1 NO_LUA=1 NO_R_TO_GCC_LINKER=1 V=1

SUB_FILES=	pkg-message

PORTDOCS=	${PORTNAME}rc.5.txt

OPTIONS_DEFINE=	DOCS

post-extract:
	@${RMDIR} ${WRKSRC}/git
	@${MV} ${WRKDIR}/git-${GIT_VERSION} ${WRKSRC}/git

post-patch:
	@${REINPLACE_CMD} -e 's/^\(GIT_VER =\).*$$/\1 ${GIT_VERSION}/' \
		${WRKSRC}/Makefile

	@${REINPLACE_CMD} -e 's/-liconv/${ICONV_LIB}/' \
		-e "s|\(ALL_CFLAGS =\)|\1 -I${OPENSSLINC}|g" \
		-e "s|\(ALL_LDFLAGS =\)|\1 -L${OPENSSLLIB}|g" \
		${WRKSRC}/git/Makefile

post-install:
	${STRIP_CMD} ${STAGEDIR}${WWWDIR}/cgit.cgi

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
