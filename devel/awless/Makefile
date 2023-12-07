PORTNAME=	awless
DISTVERSIONPREFIX=	v
DISTVERSION=	0.1.11
PORTREVISION=	18
CATEGORIES=	devel

MAINTAINER=	dmgk@FreeBSD.org
COMMENT=	Fast, powerful and easy-to-use CLI for AWS
WWW=		https://github.com/wallix/awless

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go

USE_GITHUB=	yes
GH_ACCOUNT=	wallix
GH_SUBDIR=	src/github.com/wallix/${PORTNAME}
GH_TUPLE=	golang:sys:v0.6.0:golang_sys

PLIST_FILES=	bin/awless
PORTDOCS=	README.md CHANGELOG.md

OPTIONS_DEFINE=	DOCS

# freebsd/arm64 needs golang.org/x/sys@33540a1f6037 or later
post-patch:
	${RM} -r ${WRKSRC}/vendor/golang.org/x/sys
	${RLN} ${WRKSRC_golang_sys} ${WRKSRC}/vendor/golang.org/x/sys

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
