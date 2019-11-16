# $FreeBSD$

PORTNAME=		git-lfs
DISTVERSIONPREFIX=	v
DISTVERSION=		2.9.0
PORTREVISION=		1
CATEGORIES=		devel

MAINTAINER=	egypcio@FreeBSD.org
COMMENT=	Git extension for versioning large files

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.md

USES=		go:modules
USE_GITHUB=	yes

OPTIONS_DEFINE=		GIT_SUBVERSION MANPAGES
OPTIONS_DEFAULT=	MANPAGES
OPTIONS_SUB=		yes

GIT_SUBVERSION_DESC=		Use 'git-subversion' instead of 'git' as backend
GIT_SUBVERSION_RUN_DEPENDS=	git-subversion>0:devel/git-subversion
GIT_SUBVERSION_RUN_DEPENDS_OFF=	git:devel/git

MANPAGES_BUILD_DEPENDS=	ronn:textproc/rubygem-ronn

post-build-MANPAGES-on:
	cd ${GO_WRKSRC}/docs/man && ${LOCALBASE}/bin/ronn -r *.ronn

post-install-MANPAGES-on:
	${INSTALL_MAN} ${GO_WRKSRC}/docs/man/*.1 ${STAGEDIR}${LOCALBASE}/man/man1
	${INSTALL_MAN} ${GO_WRKSRC}/docs/man/*.5 ${STAGEDIR}${LOCALBASE}/man/man5

.include <bsd.port.mk>
