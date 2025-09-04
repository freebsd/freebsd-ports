PORTNAME=	loccount
DISTVERSION=	2.16
PORTREVISION=	13
CATEGORIES=	devel
MASTER_SITES=	http://www.catb.org/~esr/loccount/

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Count source lines of code in a project
WWW=		http://www.catb.org/esr/loccount/

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	a2x:textproc/asciidoc

USES=		gmake go python:build

GO_PKGNAME=	gitlab.com/esr/${PORTNAME}

BINARY_ALIAS=	python3=${PYTHON_CMD}

PLIST_FILES=	bin/${PORTNAME} \
		share/man/man1/${PORTNAME}.1.gz

do-build:
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${GO_ENV} ${GMAKE} loccount loccount.1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME}-${PORTVERSION} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 ${STAGEDIR}${PREFIX}/share/man/man1

.include <bsd.port.mk>
