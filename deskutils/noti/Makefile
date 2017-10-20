# Created by: Hiroki Tagato <tagattie@yandex.com>
# $FreeBSD$

PORTNAME=	noti
DISTVERSIONPREFIX=	v
DISTVERSION=	2.7.0
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

PLIST_FILES=	bin/noti

do-install:
	${INSTALL_PROGRAM} ${WRKDIR}/bin/noti ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
