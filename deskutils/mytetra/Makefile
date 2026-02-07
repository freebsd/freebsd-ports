PORTNAME=	mytetra
PORTVERSION=	1.44.183
DISTVERSIONPREFIX=	v.
CATEGORIES=	deskutils

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Smart manager for information collecting
WWW=		https://webhamster.ru/site/page/index/articles/projectcode/138

LICENSE=	GPLv3

USES=		gmake qmake qt:5
USE_QT=		buildtools:build core gui network printsupport svg widgets xml
USE_GITHUB=	yes
GH_ACCOUNT=	xintrea
GH_PROJECT=	${PORTNAME}_dev

PLIST_FILES=	bin/mytetra share/applications/mytetra.desktop \
		share/icons/hicolor/48x48/apps/mytetra.png \
		share/icons/hicolor/scalable/apps/mytetra.svg

post-extract:
	@${CHMOD} -x ${WRKSRC}/app/desktop/any/mytetra.desktop

post-patch:
# Delete homegrown strcasestr() implementation (breaks the build):
# https://github.com/xintrea/mytetra_dev/issues/164
	@${REINPLACE_CMD} \
		-e '/for strcasestr() in string\.h/,+4d' \
		-e '/^int mystrncmpi/,+28d' \
			${WRKSRC}/thirdParty/mimetex/mimetex.c

.include <bsd.port.mk>
