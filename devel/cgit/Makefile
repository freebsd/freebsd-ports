# $FreeBSD$

PORTNAME=	cgit
PORTVERSION=	0.9.2
PORTREVISION=	3
CATEGORIES=	devel www
MASTER_SITES=	http://git.zx2c4.com/cgit/snapshot/:cgit \
		GOOGLE_CODE:git
DISTFILES=	cgit-${PORTVERSION}${EXTRACT_SUFX}:cgit \
		git-${GIT_VERSION}.tar.gz:git

MAINTAINER=	kevinz5000@gmail.com
COMMENT=	Fast web frontend for Git repositories

LICENSE=	GPLv2

PROJECTHOST=	git-core
GIT_VERSION=	1.8.2.3
USE_BZIP2=	yes
USES=		gmake iconv shebangfix
SHEBANG_FILES=	filters/html-converters/resources/markdown.pl
USE_OPENSSL=	yes
CFLAGS+=	-I${LOCALBASE}/include
MAKE_ARGS+=	CGIT_SCRIPT_PATH=${WWWDIR} \
		CGIT_CONFIG=${PREFIX}/etc/cgitrc NO_GETTEXT=1
LDFLAGS+=	-L${LOCALBASE}/lib ${ICONV_LIB}

SUB_FILES=	pkg-message
SUB_LIST+=	PORTNAME=${PORTNAME}
PLIST_SUB+=	PORTNAME=${PORTNAME} WWWOWN=${WWWOWN} WWWGRP=${WWWGRP}

OPTIONS_DEFINE=	DOCS

.include <bsd.port.pre.mk>

post-extract:
	@${RMDIR} ${WRKSRC}/git
	@${MV} ${WRKDIR}/git-${GIT_VERSION} ${WRKSRC}/git

post-patch:
	@${REINPLACE_CMD} -e '/^CC =/d' -e '/^CFLAGS =/d' \
		-e '/^LDFLAGS =/d' ${WRKSRC}/git/Makefile \
		${WRKSRC}/git/Makefile
	@${REINPLACE_CMD} -e 's,/usr,${PREFIX},g' \
		-e 's,-Igit,-I.,g' ${WRKSRC}/Makefile
.if empty(ICONV_LIB)
	@${REINPLACE_CMD} -e '/NEEDS_LIBICONV = YesPlease/d' \
		-e '/OLD_ICONV = YesPlease/d' \
		${WRKSRC}/git/config.mak.uname
.endif

post-install:
	@${MKDIR} ${STAGEDIR}/${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}rc.5.txt ${STAGEDIR}/${DOCSDIR}/

.include <bsd.port.post.mk>
