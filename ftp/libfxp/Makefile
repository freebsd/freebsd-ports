# ex:ts=8
# New ports collection makefile for:	libfxp
# Date created:			Feb 5, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	libfxp
PORTVERSION=	0.1.4
CATEGORIES=	ftp
MASTER_SITES=	http://millweed.com/projects/libfxp/

MAINTAINER=	ports@FreeBSD.org

PORTCOMMENT=	An ftp client library

USE_REINPLACE=	yes
USE_GMAKE=	yes
CFLAGS+=	-I. -Ilibmillweed

post-patch:
.for file in Makefile libmillweed/Makefile
	@${REINPLACE_CMD} -e "s,^CC,#CC,g ; \
		s,^CFLAGS,#CFLAGS,g ; \
		s,^PREFIX,#PREFIX,g" ${WRKSRC}/${file}
.endfor
	@(cd ${WRKSRC} ; \
	  ${GREP} -l -R malloc.h * | ${XARGS} \
	  ${REINPLACE_CMD} -e "s|malloc.h|stdlib.h|g")

.include <bsd.port.mk>
