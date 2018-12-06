# $FreeBSD$

PORTNAME=		git-lfs
DISTVERSIONPREFIX=	v
DISTVERSION=		2.6.1
CATEGORIES=		devel

MAINTAINER=	egypcio@FreeBSD.org
COMMENT=	Git extension for versioning large files

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.md

RUN_DEPENDS=	git:devel/git

USES=		go
USE_GITHUB=	yes

GH_TUPLE=	davecgh:go-spew:d8f796a:davecgh_spew/vendor/github.com/davecgh/go-spew \
		pmezard:go-difflib:792786c:pmezard_difflib/vendor/github.com/pmezard/go-difflib

GO_PKGNAME=	github.com/${PORTNAME}/${PORTNAME}

OPTIONS_DEFINE=		MANPAGES
OPTIONS_DEFAULT=	MANPAGES
OPTIONS_SUB=		yes

MANPAGES_BUILD_DEPENDS=	ronn:textproc/rubygem-ronn

post-build-MANPAGES-on:
	cd ${GO_WRKSRC}/docs/man && ${LOCALBASE}/bin/ronn -r *.ronn

post-install-MANPAGES-on:
	${INSTALL_MAN} ${GO_WRKSRC}/docs/man/*.1 ${STAGEDIR}${LOCALBASE}/man/man1
	${INSTALL_MAN} ${GO_WRKSRC}/docs/man/*.5 ${STAGEDIR}${LOCALBASE}/man/man5

.include <bsd.port.mk>
