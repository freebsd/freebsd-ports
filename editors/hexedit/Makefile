# Created by: Andrey Zakhvatov
# $FreeBSD$

PORTNAME=	hexedit
PORTVERSION=	1.2.13
CATEGORIES=	editors
MASTER_SITES=	http://rigaux.org/
DISTFILES=	${DISTNAME}.src.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	View and edit files in hexadecimal or ASCII

LICENSE=	GPLv2

WRKSRC=		${WRKDIR}/${DISTNAME:S/-${PORTVERSION}//}

GNU_CONFIGURE=	yes

PLIST_FILES=	bin/hexedit man/man1/hexedit.1.gz

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/hexedit ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/hexedit.1 ${STAGEDIR}${PREFIX}/man/man1

.include <bsd.port.mk>
