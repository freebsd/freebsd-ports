# ex:ts=8
# Ports collection makefile for:	fig2pstricks
# Date created:			Mar 4, 2005
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	fig2pstricks
PORTVERSION=	0.7.0
CATEGORIES=	graphics
MASTER_SITES=	http://homes.eco.auckland.ac.nz/chan079/fig2pstricks/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Convert xfig to pstricks

USE_GMAKE=	yes

PLIST_FILES=	bin/fig2pstricks bin/fig2epspdf

CFLAGS+=	-DVERSION=\\\"${PORTVERSION}\\\"

post-patch:
	@${REINPLACE_CMD} -e 's|gcc|$$(CC)|g ; \
		 s|^CFLAGS|#CFLAGS|g' ${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/fig2epspdf ${PREFIX}/bin

.include <bsd.port.mk>
