PORTNAME=	git-mfc
PORTVERSION=	0.20260730
CATEGORIES=	devel
HASH=		2c98dc4e5ca9ac8d8c9d3d874d118ded38957b4f
MASTER_SITES=	https://raw.githubusercontent.com/freebsd/freebsd-src/${HASH}/tools/tools/git/
PKGNAMEPREFIX=	freebsd-
DISTFILES=	git-mfc \
		git-mfc.1
DIST_SUBDIR=	${PORTNAME}_${HASH}

MAINTAINER=	des@FreeBSD.org
COMMENT=	Git plugin to assist in FreeBSD MFCs
WWW=		https://github.com/freebsd/freebsd-src/tree/main/tools/tools/git

LICENSE=	BSD2CLAUSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}gitpython>=0:devel/py-gitpython@${PY_FLAVOR}

USES=		python shebangfix

SHEBANG_FILES=	git-mfc

NO_ARCH=	yes
NO_BUILD=	yes

PLIST_FILES=	bin/git-mfc \
		share/man/man1/git-mfc.1.gz

do-extract:
	${MKDIR} ${WRKSRC}
.for file in ${DISTFILES}
	${INSTALL_SCRIPT} ${_DISTDIR}/${file} ${WRKSRC}
.endfor

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/git-mfc ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/git-mfc.1 ${STAGEDIR}${PREFIX}/share/man/man1/

.include <bsd.port.mk>
