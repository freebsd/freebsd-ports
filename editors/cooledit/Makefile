# New ports collection makefile for:	 cooledit
# Version required:	3.8.3
# Date created:		18 November 1997
# Whom:			brett@peloton.physics.montana.edu
#
# $Id: Makefile,v 1.10 1999/01/10 18:14:40 steve Exp $
#

DISTNAME=	cooledit-3.8.3
CATEGORIES=	editors
MASTER_SITES=	${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR=	apps/editors/X

MAINTAINER=	brett@peloton.physics.montana.edu

LIB_DEPENDS=    Xpm.4:${PORTSDIR}/graphics/xpm

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-mail-author --disable-static
USE_GMAKE= 	yes

post-extract:
	@${CP} ${FILESDIR}/ltconfig-1.2 ${WRKSRC}/ltconfig
	@${CP} ${FILESDIR}/ltmain.sh-1.2 ${WRKSRC}/ltmain.sh

pre-install:
	@${ECHO_MSG} "Installing in ${PREFIX}/bin"

MAN1 = cooledit.1 smalledit.1 coolman.1 coolicon.1

.include <bsd.port.mk>
