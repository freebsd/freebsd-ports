# ex:ts=8
# New ports collection makefile for:	hexedit
# Date created:				5 August 1998
# Whom:					Andrey Zakhvatov
#
# $FreeBSD$
#

PORTNAME=	hexedit
PORTVERSION=	1.2.12
CATEGORIES=	editors
MASTER_SITES=	http://people.mandriva.com/~prigaux/ \
		${MASTER_SITE_LOCAL:S/$/:local/}
MASTER_SITE_SUBDIR=	obrien/:local
DISTFILES=	${DISTNAME}.src.tgz:DEFAULT,local

MAINTAINER=	obrien@FreeBSD.org
COMMENT=	View and edit files in hexadecimal or ASCII

WRKSRC=		${WRKDIR}/${DISTNAME:S/-${PORTVERSION}//}
GNU_CONFIGURE=	yes
MAN1=		hexedit.1

PLIST_FILES=	bin/hexedit

do-install:
	@ ${INSTALL_PROGRAM} ${WRKSRC}/hexedit ${PREFIX}/bin
	@ ${INSTALL_MAN} ${WRKSRC}/hexedit.1 ${PREFIX}/man/man1

.include <bsd.port.mk>
