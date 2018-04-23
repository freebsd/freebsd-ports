# $FreeBSD$

PORTNAME=	mage
DISTVERSIONPREFIX=	v
DISTVERSION=	2.1.0
CATEGORIES=	devel

MAINTAINER=	seanc@FreeBSD.org
COMMENT=	Command-line make-like build tool using Go as input files

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	go:lang/go

USE_GITHUB=	yes
GH_ACCOUNT=	magefile
GH_SUBDIR=	src/github.com/${GH_ACCOUNT}/${PORTNAME}
GH_TAGNAME=	2.1
GH_TAG_COMMIT=	771ebed

PLIST_FILES=	bin/mage

pre-patch:
	@${SED} -e "s|%%GH_TAGNAME%%|${GH_TAGNAME}|g; s|%%GH_TAG_COMMIT%%|${GH_TAG_COMMIT}|g" \
		${FILESDIR}/patch-magefile.go > ${WRKSRC}/magefile.go.patch

do-patch:
	@cd ${WRKSRC} && ${PATCH} --forward --quiet -p2 < magefile.go.patch

do-build:
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} CGO_ENABLED=0 GOPATH=${WRKSRC} \
	${LOCALBASE}/bin/go run bootstrap.go

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
