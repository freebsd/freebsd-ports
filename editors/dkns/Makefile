PORTNAME=	dkns
PORTVERSION=	1.100
PORTREVISION=	1
CATEGORIES=	editors
MASTER_SITES=	https://www.mammothcheese.ca/

MAINTAINER=	jimmy@mammothcheese.ca
COMMENT=	Simple console text editor
WWW=		https://www.mammothcheese.ca/dkns.txt

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	munger:lang/munger

MAKE_ARGS=	MANDIR="${STAGEDIR}${PREFIX}/share/man/man1/"
MAKE_ENV=	INSTALL_MAN="${INSTALL_MAN}" INSTALL_SCRIPT="${INSTALL_SCRIPT}"
NO_ARCH=	yes

PLIST_FILES=	bin/dkns \
		share/man/man1/dkns.1.gz

.include <bsd.port.mk>
