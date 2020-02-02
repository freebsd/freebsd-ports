# $FreeBSD$

PORTNAME=	loccount
DISTVERSION=	2.8
CATEGORIES=	devel

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Count source lines of code in a project

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	a2x:textproc/asciidoc

USES=		gmake go python:2.7,build
USE_GITLAB=	yes
GL_ACCOUNT=	esr
GL_COMMIT=	7b453bb11473af641aac8e3f5616c91528431b9f

GO_PKGNAME=	gitlab.com/${GL_ACCOUNT}/${PORTNAME}

BINARY_ALIAS=	python2=${PYTHON_CMD}

PLIST_FILES=	bin/${PORTNAME} \
		man/man1/${PORTNAME}.1.gz

do-build:
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${GMAKE} loccount loccount.1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME}-${GL_COMMIT}-${GL_COMMIT} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 ${STAGEDIR}${MAN1PREFIX}/man/man1

.include <bsd.port.mk>
