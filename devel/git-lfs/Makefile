PORTNAME=	git-lfs
DISTVERSIONPREFIX=	v
DISTVERSION=	3.6.1
PORTREVISION=	6
CATEGORIES=	devel
MASTER_SITES=	https://github.com/${PORTNAME}/${PORTNAME}/releases/download/v${DISTVERSION}/

MAINTAINER=	egypcio@FreeBSD.org
COMMENT=	Git extension for versioning large files
WWW=		https://git-lfs.github.com/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.md

RUN_DEPENDS=	git:devel/git

USES=		go:modules
GO_MODULE=	github.com/git-lfs/git-lfs/v3

WRKSRC=		${WRKDIR}/${PORTNAME}-${DISTVERSION}

OPTIONS_DEFINE=		MANPAGES
OPTIONS_DEFAULT=	MANPAGES
OPTIONS_SUB=		yes

MANPAGES_BUILD_DEPENDS=	asciidoctor:textproc/rubygem-asciidoctor

post-build-MANPAGES-on:
	cd ${GO_WRKSRC}/docs/man && ${LOCALBASE}/bin/asciidoctor -b manpage *.adoc

post-install-MANPAGES-on:
	${INSTALL_MAN} ${GO_WRKSRC}/docs/man/*.1 ${STAGEDIR}${LOCALBASE}/share/man/man1
	${INSTALL_MAN} ${GO_WRKSRC}/docs/man/*.5 ${STAGEDIR}${LOCALBASE}/share/man/man5

.include <bsd.port.mk>
