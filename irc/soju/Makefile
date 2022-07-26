PORTNAME=	soju
DISTVERSIONPREFIX=	v
DISTVERSION=	0.5.0
CATEGORIES=	irc

MAINTAINER=	ashish@FreeBSD.org
COMMENT=	IRC bouncer

LICENSE=	AGPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules sqlite:3

OPTIONS_DEFAULT=	DOCS
OPTIONS_DEFINE=		DOCS

GO_BUILDFLAGS+=	-tags=libsqlite3
CGO_LDFLAGS+=	-lsqlite3
GO_MODULE=	git.sr.ht/~emersion/soju
GO_PKGNAME=	./cmd/soju ./cmd/sojuctl ./contrib/znc-import
PLIST_FILES=	bin/soju \
		bin/sojuctl \
		bin/soju-znc-import \
		${DOCSDIR_REL}/getting-started.md

DOCS_BUILD_DEPENDS=	scdoc:textproc/scdoc
DOCS_PLIST_FILES=	man/man1/soju.1.gz \

post-build-DOCS-on:
	${LOCALBASE}/bin/scdoc <${WRKSRC}/doc/${PORTNAME}.1.scd >${WRKSRC}/doc/${PORTNAME}.1

post-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${MV} ${STAGEDIR}${PREFIX}/bin/znc-import ${STAGEDIR}${PREFIX}/bin/soju-znc-import
	${INSTALL_MAN} ${WRKSRC}/doc/getting-started.md ${STAGEDIR}${DOCSDIR}

post-install-DOCS-on:
	${INSTALL_MAN} ${WRKSRC}/doc/${PORTNAME}.1 ${STAGEDIR}${PREFIX}/man/man1

.include <bsd.port.mk>
