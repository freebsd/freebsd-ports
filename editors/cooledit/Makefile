# New ports collection makefile for:	 cooledit
# Version required:	3.11.3
# Date created:		18 November 1997
# Whom:			brett@peloton.physics.montana.edu
#
# $FreeBSD$
#

DISTNAME=	cooledit-3.13.2
CATEGORIES=	editors
MASTER_SITES= 	${MASTER_SITE_SUNSITE} \
		http://www.netins.net/showcase/Comput-IT/cooledit/src/
MASTER_SITE_SUBDIR=	apps/editors/X

MAINTAINER=	brett@peloton.runet.edu

BUILD_DEPENDS=	gettext:${PORTSDIR}/devel/gettext
LIB_DEPENDS=	Xpm.4:${PORTSDIR}/graphics/xpm

USE_LIBTOOL=	yes
CONFIGURE_ARGS=	--disable-mail-author --with-libs='-lcrypt -lreadline'

USE_GMAKE= 	yes

MAN1 = cooledit.1 smalledit.1 coolman.1 coolicon.1

pre-install:
	@${ECHO_MSG} "Installing in ${PREFIX}/bin"
	@if [ ! -f ${PREFIX}/etc/coolicon.config ]; then \
		${INSTALL_SCRIPT} ${WRKSRC}/pixmap/coolicon.config \
		    ${PREFIX}/etc ; \
	fi
	${INSTALL_SCRIPT} ${WRKSRC}/pixmap/coolicon.config \
		${PREFIX}/etc/coolicon.config.dist

.include <bsd.port.mk>
