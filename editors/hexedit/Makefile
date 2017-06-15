# Created by: Andrey Zakhvatov
# $FreeBSD$

PORTNAME=	hexedit
PORTVERSION=	1.3
CATEGORIES=	editors

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	View and edit files in hexadecimal or ASCII

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

GNU_CONFIGURE=	yes
USES=		autoreconf ncurses

PLIST_FILES=	bin/hexedit man/man1/hexedit.1.gz

GH_ACCOUNT=	pixel
USE_GITHUB=	yes

post-build:
	m4 -DVERSION=${PORTVERSION} ${WRKSRC}/hexedit.1.in > ${WRKSRC}/hexedit.1

.include <bsd.port.mk>
