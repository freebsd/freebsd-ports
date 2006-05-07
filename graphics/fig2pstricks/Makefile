# ex:ts=8
# Ports collection makefile for:	fig2pstricks
# Date created:			Mar 4, 2005
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	fig2pstricks
PORTVERSION=	0.6.8
CATEGORIES=	graphics
MASTER_SITES=	http://www.vuw.ac.nz/staff/chirok_han/fig2pstricks/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Convert xfig to pstricks

USE_GMAKE=	yes

PLIST_FILES=	bin/fig2pstricks

post-patch:
	@${REINPLACE_CMD} -e 's|gcc|$$(CC)|g ; \
		 s|^CFLAGS|#CFLAGS|g' ${WRKSRC}/Makefile
	@cd ${WRKSRC} && ${TR} -d '\r' < fig2pstricks.c > fig2pstricks.c.bak \
		&& ${SED} -e 's:0.6.6:${PORTNAME}:g' < fig2pstricks.c.bak \
		> fig2pstricks.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin

.include <bsd.port.mk>
