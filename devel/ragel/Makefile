# ex:ts=8
# Ports collection makefile for:	ragel
# Date created:			Mar 6, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	ragel
PORTVERSION=	1.3.1
CATEGORIES=	devel
MASTER_SITES=	http://www.essemage.com/ragel/

MAINTAINER=	ports@FreeBSD.org

USE_REINPLACE=	yes
USE_BISON=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes

MAN1=	ragel.1

post-patch:
	@${FIND} ${WRKSRC} -name "Makefile.in" | ${XARGS} ${REINPLACE_CMD} -e \
		's|-g -Wall|@CFLAGS@|g'

.include <bsd.port.mk>
