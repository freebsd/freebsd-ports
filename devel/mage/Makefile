# $FreeBSD$

PORTNAME=	mage
DISTVERSIONPREFIX=	v
DISTVERSION=	2.1
CATEGORIES=	devel

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Command-line make-like build tool using Go as input files

BROKEN=		unfetchable
DEPRECATED=	Broken for more than 6 months
EXPIRATION_DATE=	2020-05-05

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go

USE_GITHUB=	yes
GH_ACCOUNT=	magefile
GH_SUBDIR=	src/github.com/${GH_ACCOUNT}/${PORTNAME}
GH_TAGNAME=	2.1
GH_TAG_COMMIT=	771ebed

PLIST_FILES=	bin/mage

post-patch:
	@${REINPLACE_CMD} -e "s|%%GH_TAGNAME%%|${GH_TAGNAME}|g; s|%%GH_TAG_COMMIT%%|${GH_TAG_COMMIT}|g" \
		${WRKSRC}/magefile.go

do-build:
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${GO_ENV} \
	${GO_CMD} run bootstrap.go

.include <bsd.port.mk>
