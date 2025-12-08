PORTNAME=	taskwarrior-tui
DISTVERSIONPREFIX=	v
DISTVERSION=	0.26.4
CATEGORIES=	deskutils

MAINTAINER=	adamw@FreeBSD.org
COMMENT=	Terminal User Interface for Taskwarrior
WWW=		https://kdheepak.com/taskwarrior-tui/

LICENSE=	AGPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	task:deskutils/taskwarrior

USES=		cargo
USE_GITHUB=	yes
GH_ACCOUNT=	kdheepak

PLIST_FILES=	bin/taskwarrior-tui

.include <bsd.port.mk>
