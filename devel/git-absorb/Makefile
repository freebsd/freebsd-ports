PORTNAME=	git-absorb
DISTVERSION=	0.8.0
PORTREVISION=	2
CATEGORIES=	devel

MAINTAINER=	eduardo@FreeBSD.org
COMMENT=	Git command for automating fixup/autosquash commits
WWW=		https://github.com/tummychow/git-absorb

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.md

BUILD_DEPENDS=	a2x:textproc/asciidoc

USES=		cargo
USE_GITHUB=	yes
GH_ACCOUNT=	tummychow

PLIST_FILES=	bin/${PORTNAME} \
		share/man/man1/${PORTNAME}.1.gz
post-build:
	cd ${WRKSRC}/Documentation && \
		a2x -L -d manpage -f manpage git-absorb.adoc --attribute man-version=${DISTVERSION}
post-install:
	${INSTALL_MAN} ${WRKSRC}/Documentation/${PORTNAME}.1 \
		${STAGEDIR}${PREFIX}/share/man/man1

.include <bsd.port.mk>
