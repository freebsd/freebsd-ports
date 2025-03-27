PORTNAME=	git-filter-repo
PORTVERSION=	${GFR_COMMIT_DATE}
CATEGORIES=	devel
PKGNAMESUFFIX=	-devel

MAINTAINER=	cy@FreeBSD.org
COMMENT=	git filter-repo is a versatile tool for rewriting history
WWW=		https://github.com/newren/git-filter-repo

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING.mit

CONFLICTS=	git-filter-repo-[0-9]*

RUN_DEPENDS=	git:devel/git

USES=		python shebangfix

SHEBANG_FILES=	git-filter-repo

USE_GITHUB=	yes
GH_ACCOUNT=	newren
GH_TAGNAME=	c1d8461
GFR_COMMIT_DATE=	20250725

NO_BUILD=	yes
NO_ARCH=	yes

#
# XXX:	The man page only exists in the upstream docs branch. Unfortunately
#	there is no clean way to extract just one file from a different
#	upstream branch. Therefore we include it in files. To discover
#	which version of the git-filter-repo.1 file in the docs branch
#	corresponds with the extracted tag,
#
#	- git clone https://github.com/newren/git-filter-repo.git
#	- git log, looking for the current tag's hash.
#	- git switch docs
#	- git log and look for the matching hash in the commit log.
#	- git checkout HASH
#	- copy the file to the files subdirectory of this port
#
#	Until a better approach can be discovered.
#
post-extract:
	@${MKDIR} ${WRKSRC}/Documentation/man1;
	${CP} ${FILESDIR}/git-filter-repo.1.in ${WRKSRC}/Documentation/man1/git-filter-repo.1

do-install:
	cd ${WRKSRC}; \
	${MKDIR} ${STAGEDIR}/${PREFIX}/libexec/git-core; \
	${MKDIR} ${STAGEDIR}/${PYTHON_SITELIBDIR}; \
	${MAKE} prefix=${STAGEDIR}/${PREFIX} pythondir=${STAGEDIR}/${PYTHON_SITELIBDIR} install

.include <bsd.port.mk>
