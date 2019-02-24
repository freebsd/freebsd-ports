# $FreeBSD$

PORTNAME=	loccount
DISTVERSION=	2.0
CATEGORIES=	devel

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Count source lines of code in a project

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	go:lang/go

USE_GITLAB=	yes
GL_ACCOUNT=	esr
GL_COMMIT=	249ea3d6927fd327086b609857c04bb95eafdd98

PLIST_FILES=	bin/${PORTNAME}

do-build:
	@cd ${WRKSRC} && \
		${SETENV} ${MAKE_ENV} GOPATH=${WRKSRC} go build -o ${PORTNAME}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
