# Created by: Andrew Pantyukhin <infofarmer@FreeBSD.org>
# $FreeBSD$

PORTNAME=	msghack
PORTVERSION=	0.21
CATEGORIES=	devel
MASTER_SITES=	LOCAL/sunpoet
PKGNAMEPREFIX=	gettext-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Alter gettext po files in special ways

LICENSE=	GPLv3+

USES=		python:3.5+ shebangfix tar:xz

NO_ARCH=	yes
NO_BUILD=	yes

PLIST_FILES=	bin/msghack \
		share/man/man1/msghack.1.gz

SHEBANG_FILES=	msghack.py

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/msghack.py ${STAGEDIR}${PREFIX}/bin/msghack
	${INSTALL_MAN} ${WRKSRC}/msghack.1 ${STAGEDIR}${PREFIX}/share/man/man1

.include <bsd.port.mk>
