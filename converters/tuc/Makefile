# New ports collection makefile for:	tuc
# Date created:				30 March 1999
# Whom:					G. Adam Stanislav <adam@whizkidtech.net>
#
# $FreeBSD$
#

PORTNAME=	tuc
PORTVERSION=	1.10
CATEGORIES=	converters
MASTER_SITES=	http://www.whizkidtech.redprince.net/fports/

MAINTAINER=	adam@redprince.net
COMMENT=	Text to Unix Conversion

MAN1=		tuc.1

NO_CDROM=	Author does not allow CD-ROM distribution
PLIST_FILES=	bin/tuc

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/tuc ${PREFIX}/bin
	$(INSTALL_MAN) ${WRKSRC}/tuc.1 ${PREFIX}/man/man1

.include <bsd.port.mk>
