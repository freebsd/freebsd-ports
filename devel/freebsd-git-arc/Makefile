PORTNAME=	freebsd-git-arc
PORTVERSION=	20260105
CATEGORIES=	devel
MASTER_SITES=	https://raw.githubusercontent.com/freebsd/freebsd-src/${_REV}/tools/tools/git/
DISTFILES=	git-arc.sh \
		git-arc.1
DIST_SUBDIR=	${PORTNAME}_${_REV}

MAINTAINER=	jrm@FreeBSD.org
COMMENT=	Git plugin to manage FreeBSD Phabricator reviews
WWW=		https://github.com/freebsd/freebsd-src/tree/main/tools/tools/git

LICENSE=	BSD2CLAUSE

RUN_DEPENDS=	${LOCALBASE}/lib/php/arcanist/bin/arc:devel/arcanist-lib \
		git:devel/git \
		jq:textproc/jq

EXTRACT_CMD=	${CP}
EXTRACT_BEFORE_ARGS=	# empty
EXTRACT_AFTER_ARGS=	.
NO_ARCH=	yes
NO_BUILD=	yes

NO_WRKSUBDIR=	yes

PLIST_FILES=	bin/git-arc \
		share/man/man1/git-arc.1.gz

_REV=		1c8dafe618878c563c3740061f83a85b0be10720

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/git-arc.sh ${STAGEDIR}${PREFIX}/bin/git-arc
	${INSTALL_MAN} ${WRKSRC}/git-arc.1 ${STAGEDIR}${PREFIX}/share/man/man1/

.include <bsd.port.mk>
