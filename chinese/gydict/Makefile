# Created by: Chih-Hsin Chang <chihhsin@cs.nctu.edu.tw>
# $FreeBSD$

PORTNAME=	gydict
PORTVERSION=	1.0
CATEGORIES=	chinese textproc python

MAINTAINER=	chihhsin@cs.nctu.edu.tw
COMMENT=	Command line tool of Yahoo! Dictionary

LICENSE=	MIT

USES=		python:run,3

USE_GITHUB=	yes
GH_ACCOUNT=	iamgyz
GH_TAGNAME=	124aebf

NO_BUILD=	yes
NO_ARCH=	yes

PLIST_FILES=	bin/gydict

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/gydict.py ${STAGEDIR}${PREFIX}/bin/gydict

.include <bsd.port.mk>
