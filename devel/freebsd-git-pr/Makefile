PORTNAME=	git-pr
PKGNAMEPREFIX=	freebsd-
PORTVERSION=	0.20260415
HASH=		9135bc9be79c7d26b368d64537ae638f47f70047
CATEGORIES=	devel
MASTER_SITES=	https://codeberg.org/FreeBSD/${PORTNAME}/raw/commit/${HASH}/
DISTFILES=	git-pr \
		git-pr.1
DIST_SUBDIR=	${PORTNAME}_${HASH}
EXTRACT_ONLY=	# nothing

MAINTAINER=	des@FreeBSD.org
COMMENT=	Git plugin to manage FreeBSD Forgejo pull requests
WWW=		https://codeberg.org/FreeBSD/${PORTNAME}/

LICENSE=	BSD2CLAUSE

RUN_DEPENDS=	curl:ftp/curl \
		git:devel/git \
		jq:textproc/jq

NO_ARCH=	yes
NO_BUILD=	yes

PLIST_FILES=	bin/git-pr \
		share/man/man1/git-pr.1.gz

do-install:
	${INSTALL_SCRIPT} ${DISTDIR}/${DIST_SUBDIR}/git-pr \
	    ${STAGEDIR}${PREFIX}/bin/git-pr
	${INSTALL_MAN} ${DISTDIR}/${DIST_SUBDIR}/git-pr.1 \
	    ${STAGEDIR}${PREFIX}/share/man/man1/

.include <bsd.port.mk>
