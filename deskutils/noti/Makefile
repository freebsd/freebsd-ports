PORTNAME=	noti
DISTVERSION=	3.8.0
PORTREVISION=	5
CATEGORIES=	deskutils

MAINTAINER=	tagattie@FreeBSD.org
COMMENT=	Trigger notifications when a process completes
WWW=		https://github.com/variadico/noti

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	notify-send:devel/libnotify

USES=		go:1.24,modules

USE_GITHUB=	yes
GH_ACCOUNT=	variadico

GO_TARGET=	./cmd/noti
GO_BUILDFLAGS=	-ldflags "-s -w -X github.com/variadico/noti/internal/command.Version=${DISTVERSION}"

PLIST_FILES=	bin/noti \
		share/man/man1/noti.1.gz \
		share/man/man5/noti.yaml.5.gz

post-install:
	${INSTALL_MAN} ${WRKSRC}/docs/man/dist/noti.1 ${STAGEDIR}${PREFIX}/share/man/man1/noti.1
	${INSTALL_MAN} ${WRKSRC}/docs/man/dist/noti.yaml.5 ${STAGEDIR}${PREFIX}/share/man/man5/noti.yaml.5

.include <bsd.port.mk>
