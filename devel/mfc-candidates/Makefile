PORTNAME=	mfc-candidates
PORTVERSION=	20260105
CATEGORIES=	devel
MASTER_SITES=	https://raw.githubusercontent.com/freebsd/freebsd-src/${_REV}/tools/tools/git/
DISTFILES=	mfc-candidates.lua
DIST_SUBDIR=	${PORTNAME}_${_REV}

MAINTAINER=	jrm@FreeBSD.org
COMMENT=	Identify FreeBSD commits to MFC
WWW=		https://github.com/freebsd/freebsd-src/tree/main/tools/tools/git

LICENSE=	BSD2CLAUSE

USES=		lua shebangfix
SHEBANG_FILES=	mfc-candidates.lua
lua_OLD_CMD=	/usr/libexec/flua

EXTRACT_CMD=	${CP}
EXTRACT_BEFORE_ARGS=	# empty
EXTRACT_AFTER_ARGS=	.
NO_ARCH=	yes
NO_BUILD=	yes

NO_WRKSUBDIR=	yes

PLIST_FILES=	bin/mfc-candidates

_REV=		1c8dafe618878c563c3740061f83a85b0be10720

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/mfc-candidates.lua ${STAGEDIR}${PREFIX}/bin/mfc-candidates

.include <bsd.port.mk>
