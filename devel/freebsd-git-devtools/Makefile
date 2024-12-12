PORTNAME=	freebsd-git-devtools
PORTVERSION=	20241203
CATEGORIES=	devel
MASTER_SITES=	https://raw.githubusercontent.com/freebsd/freebsd-src/${_REV}/tools/tools/git/
DISTFILES=	git-arc.sh \
		git-arc.1 \
		mfc-candidates.lua \
		mfc-candidates.sh
DIST_SUBDIR=	${PORTNAME}_${_REV}

MAINTAINER=	jrm@FreeBSD.org
COMMENT=	Simple Git tools from the FreeBSD src repository

LICENSE=	BSD2CLAUSE

RUN_DEPENDS=	arc:devel/arcanist \
		git:devel/git \
		jq:textproc/jq

USES=		lua shebangfix
SHEBANG_FILES=	mfc-candidates.lua
lua_OLD_CMD=	/usr/libexec/flua

EXTRACT_CMD=	${CP}
EXTRACT_BEFORE_ARGS=	# empty
EXTRACT_AFTER_ARGS=	.
NO_ARCH=	yes
NO_BUILD=	yes

NO_WRKSUBDIR=	yes

PLIST_FILES=	bin/git-arc \
		bin/mfc-candidates \
		bin/mfc-candidates.lua \
		share/man/man1/git-arc.1.gz

_REV=		d6ed5ff4ac7d9610385b35f77539ccf5bae8cc65

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/git-arc.sh ${STAGEDIR}${PREFIX}/bin/git-arc
	${INSTALL_SCRIPT} ${WRKSRC}/mfc-candidates.lua ${STAGEDIR}${PREFIX}/bin/
	${INSTALL_SCRIPT} ${WRKSRC}/mfc-candidates.sh ${STAGEDIR}${PREFIX}/bin/mfc-candidates
	${INSTALL_MAN} ${WRKSRC}/git-arc.1 ${STAGEDIR}${PREFIX}/share/man/man1/

.include <bsd.port.mk>
