PORTNAME=	noti
DISTVERSION=	3.7.0
PORTREVISION=	5
CATEGORIES=	deskutils

MAINTAINER=	tagattie@FreeBSD.org
COMMENT=	Trigger notifications when a process completes
WWW=		https://github.com/variadico/noti

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	notify-send:devel/libnotify

USES=		go:modules

USE_GITHUB=	yes
GH_ACCOUNT=	variadico

GO_TARGET=	./cmd/noti

PLIST_FILES=	bin/noti man/man1/noti.1.gz man/man5/noti.yaml.5.gz

post-install:
	${INSTALL_MAN} ${WRKSRC}/docs/man/dist/noti.1 ${STAGEDIR}${MANPREFIX}/man/man1/noti.1
	${INSTALL_MAN} ${WRKSRC}/docs/man/dist/noti.yaml.5 ${STAGEDIR}${MANPREFIX}/man/man5/noti.yaml.5

.include <bsd.port.mk>
