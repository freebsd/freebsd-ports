# ex:ts=8
# New ports collection makefile for:	hexedit
# Date created:				5 August 1998
# Whom:					Andrey Zakhvatov
#
# $FreeBSD$
#

PORTNAME=	hexedit
PORTVERSION=	1.2.1
CATEGORIES=	editors
MASTER_SITES=	http://www.chez.com/prigaux/ \
		${MASTER_SITE_LOCAL} \
		${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR=	utils/file/hex,obrien
EXTRACT_SUFX=	.src.tgz

MAINTAINER=	obrien@FreeBSD.org
COMMENT=	View and edit files in hexadecimal or ASCII

WRKSRC=		${WRKDIR}/${DISTNAME:S/-${PORTVERSION}//}
GNU_CONFIGURE=	yes
MAN1=		hexedit.1

do-install:
	@ ${INSTALL_PROGRAM} ${WRKSRC}/hexedit ${PREFIX}/bin
	@ ${INSTALL_MAN} ${WRKSRC}/hexedit.1 ${PREFIX}/man/man1

.include <bsd.port.mk>
