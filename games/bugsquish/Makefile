# New ports collection makefile for:	bugsquish
# Date created:				2004 05 July
# Whom:					Adam Weinberger <adamw@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	bugsquish
PORTVERSION=	0.0.6
CATEGORIES=	games
MASTER_SITES=	ftp://ftp.sonic.net/pub/users/nbs/unix/x/bugsquish/src/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Bug-squishing, fly-swatting action

BROKEN=		Broken pkg-plist

USE_SDL=	mixer image
USE_GMAKE=	yes
USE_REINPLACE=	yes
PLIST=		${WRKDIR}/plist

post-patch:
	${REINPLACE_CMD} -e "/^#include/s|<SDL|<SDL11/SDL|g" \
		${WRKSRC}/bugsquish.c

do-install:
	${MKDIR} ${DATADIR}
	${CP} -R ${WRKSRC}/data/* ${DATADIR}
	${FIND} ${DATADIR} -type f | ${XARGS} ${CHMOD} 644
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin

pre-install:
	-${RM} ${PLIST}
	${ECHO_CMD} bin/${PORTNAME} >> ${PLIST}
	cd ${WRKSRC} && ${FIND} data ! -type d | ${SORT} \
		| ${SED} -e "s|^data|%%DATADIR%%|" >> ${PLIST};
	cd ${WRKSRC} && ${FIND} data -type d ! -empty | ${SORT} -r \
		| ${SED} -e "s|^data|@dirrm %%DATADIR%%|" \
		| ${GREP} / >> ${PLIST}

.include <bsd.port.mk>
