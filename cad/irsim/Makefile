# New ports collection makefile for:    irsim
# Date created:         18 Dec 1994
# Whom:                 swallace
#
# $FreeBSD$
#

PORTNAME=	irsim
PORTVERSION=	9.5
PORTREVISION=	1
CATEGORIES=	cad
MASTER_SITES=	http://mos.stanford.edu/group/magic/
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An event-driven logic-level simulator for MOS circuis

USE_XLIB=	yes
USE_REINPLACE=	yes
MAN1=		irsim.1
MAN3=		irsim-analyzer.3
MAN5=		netchange.5

.include <bsd.port.pre.mk>

# othewise patch will complain
post-extract:
	@${FIND} ${WRKSRC} -name RCS | ${XARGS} ${RM} -rf

post-patch:
	@${EGREP} -lr '^#endif[^$$]' ${WRKSRC} | ${XARGS} ${REINPLACE_CMD} -e \
		's|\(^#.*endif\).*|\1|g'

.include <bsd.port.post.mk>
