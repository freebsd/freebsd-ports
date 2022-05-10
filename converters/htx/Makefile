# Created by: Vsevolod Stakhov <vsevolod@highsecure.ru>

PORTNAME=	htx
DISTVERSION=	0.7.8
CATEGORIES=	converters www
MASTER_SITES=	http://stuff.myrealm.co.uk/htx/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	HTML to XHTML converter

DEPRECATED=	XHTML is considered obsolete in favor of HTML5 
EXPIRATION_DATE=2022-06-30

USES=		perl5 shebangfix
SHEBANG_FILES=	htx
NO_BUILD=	yes
PLIST_FILES=	bin/htx

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/htx ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
