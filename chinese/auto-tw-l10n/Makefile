PORTNAME=	auto-tw-l10n
PORTVERSION=	1.16
CATEGORIES=	chinese

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Automatic localization for Traditional Chinese locale

NO_ARCH=	yes
NO_BUILD=	yes

SUB_FILES=	pkg-message

USE_GITHUB=	yes
GH_ACCOUNT=	BSDTW

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/share/skel/zh_TW.UTF-8/
	${INSTALL_DATA} ${WRKSRC}/* ${STAGEDIR}${PREFIX}/share/skel/zh_TW.UTF-8/

.include <bsd.port.mk>
