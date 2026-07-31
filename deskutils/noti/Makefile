PORTNAME=	noti
DISTVERSION=	3.9.0
CATEGORIES=	deskutils
MASTER_SITES=	https://codeberg.org/roble/noti/releases/download/${DISTVERSION}/
DISTNAME=	${PORTNAME}${DISTVERSION}

MAINTAINER=	tagattie@FreeBSD.org
COMMENT=	Trigger notifications when a process completes
WWW=		https://codeberg.org/roble/noti

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSES/MIT.txt

RUN_DEPENDS=	notify-send:devel/libnotify

USES=		go:1.25+,modules

GO_TARGET=	./cmd/noti
GO_LDFLAGS=	-w -X codeberg.org/roble/noti/internal/command.Version=${DISTVERSION}

NO_WRKSUBDIR=	yes

PLIST_FILES=	bin/${PORTNAME} \
		share/man/man1/${PORTNAME}.1.gz \
		share/man/man5/${PORTNAME}.yaml.5.gz
PORTDOCS=	CONTRIBUTING.md README.md

OPTIONS_DEFINE=	DOCS

post-install:
	${INSTALL_MAN} ${WRKSRC}/docs/man/dist/${PORTNAME}.1 \
		${STAGEDIR}${PREFIX}/share/man/man1/${PORTNAME}.1
	${INSTALL_MAN} ${WRKSRC}/docs/man/dist/${PORTNAME}.yaml.5 \
		${STAGEDIR}${PREFIX}/share/man/man5/${PORTNAME}.yaml.5

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${PORTDOCS:S|^|${GO_WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
