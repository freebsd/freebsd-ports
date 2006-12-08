# New ports collection makefile for:	serialoverip
# Date created:		3 September 2006
# Whom:			Devon H. O'Dell <devon.odell@coyotepoint.com>
#
# $FreeBSD$
#

PORTNAME=	ser2net
PORTVERSION=	2.3
PORTREVISION=	1
CATEGORIES=	comms net
MASTER_SITES=	SF

MAINTAINER=	devon.odell@coyotepoint.com
COMMENT=	Allows to access serial ports over IP

GNU_CONFIGURE=	yes
MAN8=		${PORTNAME}.8
PLIST_FILES=	sbin/${PORTNAME} etc/${PORTNAME}.conf.sample
USE_RC_SUBR=	${PORTNAME}

post-patch:
	@${REINPLACE_CMD} -e's!/etc!${PREFIX}/etc!g' ${WRKSRC}/${PORTNAME}.c ${WRKSRC}/${PORTNAME}.8

post-install:
	@${INSTALL_DATA} ${WRKSRC}/${PORTNAME}.conf ${PREFIX}/etc/${PORTNAME}.conf.sample

.include <bsd.port.mk>
