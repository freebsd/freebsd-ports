# $FreeBSD$

PORTNAME=	git-codereview
PORTVERSION=	0.0.0.2016030201
CATEGORIES=	devel

MAINTAINER=	swills@FreeBSD.org
COMMENT=	Command-line tool for working with Gerrit

BUILD_DEPENDS=	${LOCALBASE}/bin/go:lang/go

USE_GITHUB=	yes
GH_ACCOUNT=	golang
GH_PROJECT=	review
GH_TAGNAME=	77ae237

PLIST_FILES=	bin/git-codereview

STRIP=		# stripping can break go binaries

post-patch:
	@${MKDIR} ${WRKSRC}/src/golang.org/x/review
.for src in .gitattributes AUTHORS CONTRIBUTING.md CONTRIBUTORS LICENSE PATENTS \
	README codereview.cfg git-codereview
	@${MV} ${WRKSRC}/${src} ${WRKSRC}/src/golang.org/x/review
.endfor

do-build:
	cd ${WRKSRC}/src/golang.org/x/review ; ${SETENV} ${BUILD_ENV} GOPATH=${WRKSRC} go install ./...

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
