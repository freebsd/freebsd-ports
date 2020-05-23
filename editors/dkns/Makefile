# Created by: James Bailie <jimmy@mammothcheese.ca>
# $FreeBSD$

PORTNAME=	dkns
PORTVERSION=	1.100
CATEGORIES=	editors
MASTER_SITES=	http://www.mammothcheese.ca/

MAINTAINER=	jimmy@mammothcheese.ca
COMMENT=	Simple console text editor

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	munger:lang/munger

MAKE_ENV=	INSTALL_MAN="${INSTALL_MAN}" INSTALL_SCRIPT="${INSTALL_SCRIPT}"
NO_ARCH=	yes

PLIST_FILES=	bin/dkns \
		man/man1/dkns.1.gz

.include <bsd.port.mk>
