# Created by: Hiroki Tagato <tagattie@yandex.com>
# $FreeBSD$

PORTNAME=	noti
DISTVERSION=	3.1.0
CATEGORIES=	deskutils

MAINTAINER=	tagattie@yandex.com
COMMENT=	Trigger notifications when a process completes

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	notify-send:devel/libnotify

USES=		go
USE_GITHUB=	yes

GH_ACCOUNT=	variadico

GO_PKGNAME=	github.com/${GH_ACCOUNT}/${PORTNAME}
GO_TARGET=	github.com/${GH_ACCOUNT}/${PORTNAME}/cmd/noti

PLIST_FILES=	bin/noti man/man1/noti.1.gz man/man5/noti.yaml.5.gz

do-install:
	${INSTALL_PROGRAM} ${WRKDIR}/bin/noti ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKDIR}/${PORTNAME}-${DISTVERSION}/docs/man/noti.1 ${STAGEDIR}${PREFIX}/man/man1/noti.1
	${INSTALL_MAN} ${WRKDIR}/${PORTNAME}-${DISTVERSION}/docs/man/noti.yaml.5 ${STAGEDIR}${PREFIX}/man/man5/noti.yaml.5

.include <bsd.port.mk>
