# New ports collection makefile for:	lpe
# Version required:	1.1.5
# Date created:		12 April 1999
# Whom:			Chris Piazza <cpiazza@home.net>
#
# $Id$
#

DISTNAME=     	lpe-1.1.5
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
	${INSTALL_DATA} ${WRKSRC}/cmode.so ${PREFIX}/lib/lpe
	${INSTALL_DATA} ${WRKSRC}/cppmode.so ${PREFIX}/lib/lpe
	${INSTALL_DATA} ${WRKSRC}/htmlmode.so ${PREFIX}/lib/lpe
	${INSTALL_DATA} ${WRKSRC}/perlmode.so ${PREFIX}/lib/lpe
	${INSTALL_DATA} ${WRKSRC}/sgmlmode.so ${PREFIX}/lib/lpe
	${INSTALL_MAN} ${WRKSRC}/lpe.1 ${PREFIX}/man/man1

.include <bsd.port.mk>
