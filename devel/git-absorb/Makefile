PORTNAME=	git-absorb
DISTVERSION=	0.6.11
PORTREVISION=	1
CATEGORIES=	devel

MAINTAINER=	eduardo@FreeBSD.org
COMMENT=	Git command for automating fixup/autosquash commits
WWW=		https://github.com/tummychow/git-absorb

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.md

LIB_DEPENDS=	libgit2.so:devel/libgit2

USES=		cargo
USE_GITHUB=	yes
GH_ACCOUNT=	tummychow

PLIST_FILES=	bin/git-absorb

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/git-absorb

.include <bsd.port.mk>
