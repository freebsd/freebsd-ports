# New ports collection makefile for:	 cooledit
# Date created:		18 November 1997
# Whom:			brett@peloton.physics.montana.edu
#
# $FreeBSD$
#

PORTNAME=	cooledit
PORTVERSION=	3.17.2
CATEGORIES=	editors
MASTER_SITES=	${MASTER_SITE_SUNSITE} \
		http://www.netins.net/showcase/Comput-IT/cooledit/src/
MASTER_SITE_SUBDIR=	apps/editors/X/cooledit

MAINTAINER=	brett@peloton.runet.edu

LIB_DEPENDS=	intl.1:${PORTSDIR}/devel/gettext

USE_LIBTOOL=	yes
INSTALLS_SHLIB=	yes
USE_XLIB=	yes
USE_XPM=	yes
USE_GMAKE=	yes

CONFIGURE_ARGS=	--disable-mail-author --with-libs='-lcrypt -lreadline' \
		--without-included-gettext
CONFIGURE_ENV=	CC="${CC} -I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

MAN1=		cooledit.1 smalledit.1 coolman.1 coolicon.1

pre-install:
	@${ECHO_MSG} "Installing in ${PREFIX}/bin"
	@if [ ! -f ${PREFIX}/etc/coolicon.config ]; then \
		${INSTALL_SCRIPT} ${WRKSRC}/pixmap/coolicon.config \
		    ${PREFIX}/etc ; \
	fi
	${INSTALL_SCRIPT} ${WRKSRC}/pixmap/coolicon.config \
		${PREFIX}/etc/coolicon.config.dist

post-install:
	@${LN} -sf ${PREFIX}/share/cooledit/global.py \
		${PREFIX}/share/coolicon/global.py

.include <bsd.port.mk>
