# New ports collection makefile for:	lpe
# Version required:	1.1.8
# Date created:		12 April 1999
# Whom:			Chris Piazza <cpiazza@home.net>
#
# $Id: Makefile,v 1.2 1999/04/19 04:06:52 steve Exp $
#

DISTNAME=     	lpe-1.1.9
CATEGORIES=	editors
MASTER_SITES=	http://cdsmith.twu.net/lpe/

MAINTAINER=	cpiazza@home.net

LIB_DEPENDS=	slang.1:${PORTSDIR}/devel/libslang

USE_GMAKE=	yes

MAN1=	lpe.1

post-patch:
	@${SED} -e s#__PREFIX__#${PREFIX}#g ${WRKSRC}/options.h > ${WRKSRC}/options.h.new
	@${MV} -f ${WRKSRC}/options.h.new ${WRKSRC}/options.h

do-install:
	${MKDIR} ${PREFIX}/lib/lpe
	${INSTALL_PROGRAM} ${WRKSRC}/lpe ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/*.so ${PREFIX}/lib/lpe
	${INSTALL_MAN} ${WRKSRC}/lpe.1 ${PREFIX}/man/man1

.include <bsd.port.mk>
