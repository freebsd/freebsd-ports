PORTNAME=	coffeebreak
DISTVERSION=	0.1.1
PORTREVISION=	1
CATEGORIES=	games

MAINTAINER=	0mp@FreeBSD.org
COMMENT=	Pretend your machine is busy with a fake FreeBSD installer
WWW=		https://github.com/0mp/coffeebreak

LICENSE=	BSD2CLAUSE

USE_GITHUB=	yes
GH_ACCOUNT=	0mp

NO_ARCH=	yes
NO_BUILD=	yes

PLIST_FILES=	bin/coffeebreak \
		share/man/man6/coffeebreak.6.gz

post-patch:
	${REINPLACE_CMD} 's|/usr/local|${PREFIX}|g' ${WRKSRC}/Makefile

.include <bsd.port.mk>
