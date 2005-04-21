# ex:ts=8
# Ports collection makefile for:	fig2pstricks
# Date created:			Mar 4, 2005
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	fig2pstricks
PORTVERSION=	0.6.6
CATEGORIES=	graphics
MASTER_SITES=	http://www.vuw.ac.nz/staff/chirok_han/fig2pstricks/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Convert xfig to pstricks

USE_REINPLACE=	yes
USE_GMAKE=	yes

PLIST_FILES=	bin/fig2pstricks

post-patch:
	@${REINPLACE_CMD} -e 's|gcc|$$(CC)|g ; \
		 s|^CFLAGS|#CFLAGS|g' ${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin

.include <bsd.port.mk>
