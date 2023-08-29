PORTNAME=	mytetra
DISTVERSION=	1_43_27
CATEGORIES=	deskutils
MASTER_SITES=	https://webhamster.ru/db/data/articles/105/ \
		http://vault.101011010.xyz/distfiles/
DISTNAME=	${PORTNAME}_${DISTVERSION}_src

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Smart manager for information collecting
WWW=		https://webhamster.ru/site/page/index/articles/projectcode/138

LICENSE=	GPLv3

USES=		gmake qmake qt:5 zip
USE_QT=		buildtools:build core gui network printsupport svg widgets xml

PLIST_FILES=	bin/mytetra share/applications/mytetra.desktop \
		share/icons/hicolor/48x48/apps/mytetra.png \
		share/icons/hicolor/scalable/apps/mytetra.svg

post-extract:
	${CHMOD} -x ${WRKSRC}/desktop/any/mytetra.desktop

.include <bsd.port.mk>
