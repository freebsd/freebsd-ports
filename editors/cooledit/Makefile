# New ports collection makefile for:	 cooledit
# Version required:	3.8.3
# Date created:		18 November 1997
# Whom:			brett@peloton.physics.montana.edu
#
# $Id: Makefile,v 1.12 1999/04/06 22:06:40 jseger Exp $
#

DISTNAME=	cooledit-3.9.0
CATEGORIES=	editors
MASTER_SITES=	${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR=	apps/editors/X

MAINTAINER=	brett@peloton.physics.montana.edu

LIB_DEPENDS=    Xpm.4:${PORTSDIR}/graphics/xpm

USE_LIBTOOL=	yes
CONFIGURE_ARGS=	--disable-mail-author --disable-static  --with-libs='-lcrypt -lreadline'
USE_GMAKE= 	yes

pre-install:
	@${ECHO_MSG} "Installing in ${PREFIX}/bin"

MAN1 = cooledit.1 smalledit.1 coolman.1 coolicon.1

.include <bsd.port.mk>
