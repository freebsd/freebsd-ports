PORTNAME=	unpackerr
DISTVERSIONPREFIX=	v
DISTVERSION=	0.14.5
PORTREVISION=	4
CATEGORIES=	archivers

MAINTAINER=	mdw@FreeBSD.org
COMMENT=	Extracts downloads for Radarr, Sonarr, Lidarr or Readarr
WWW=		https://unpackerr.zip

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	go-md2man:textproc/go-md2man

USES=		go:modules
USE_RC_SUBR=	unpackerr

GO_MODULE=	github.com/Unpackerr/unpackerr

USERS=		unpackerr
GROUPS=		unpackerr

PLIST_FILES=	bin/${PORTNAME} \
		share/man/man1/unpackerr.1.gz \
		"@sample ${ETCDIR_REL}/unpackerr.conf.sample"
PORTDOCS=	README.md

OPTIONS_DEFINE=	DOCS

post-build:
	go-md2man -in ${WRKSRC}/examples/MANUAL.md -out ${WRKSRC}/examples/unpackerr.1
	${GZIP_CMD} ${WRKSRC}/examples/unpackerr.1

post-install:
	${MKDIR} ${STAGEDIR}${ETCDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/unpackerr.conf.example ${STAGEDIR}${ETCDIR}/unpackerr.conf.sample
	${INSTALL_MAN} ${WRKSRC}/examples/unpackerr.1.gz ${STAGEDIR}${PREFIX}/share/man/man1/

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.md ${STAGEDIR}${DOCSDIR}/

.include <bsd.port.mk>
