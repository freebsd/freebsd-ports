# New ports collection makefile for:	 cooledit
# Date created:		18 November 1997
# Whom:			brett@peloton.physics.montana.edu
#
# $FreeBSD$
#

PORTNAME=	cooledit
PORTVERSION=	3.17.7
PORTREVISION=	2
CATEGORIES=	editors
MASTER_SITES=	http://cooledit.sourceforge.net/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Suite of utilities, including a GUI editor

LIB_DEPENDS=	vga.1:${PORTSDIR}/graphics/svgalib

USE_GETTEXT=	yes
USE_XPM=	yes
USE_PYTHON=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include ${PTHREAD_CFLAGS}" \
		LDFLAGS="-L${LOCALBASE}/lib ${PTHREAD_LIBS}"
CONFIGURE_ARGS=	--with-libs='-lcrypt -lreadline -lvga -lintl' \
		--disable-mail-author
INSTALLS_SHLIB=	yes

MAN1=		cooledit.1 coolicon.1 coolman.1 smalledit.1

post-install:
	${INSTALL_DATA} ${WRKSRC}/pixmap/coolicon.config \
		${PREFIX}/etc/coolicon.config.dist
.if !exists(${PREFIX}/etc/coolicon.config)
	${INSTALL_DATA} ${WRKSRC}/pixmap/coolicon.config \
		${PREFIX}/etc/coolicon.config
.endif
	@${LN} -sf ${PREFIX}/share/cooledit/global.py \
		${PREFIX}/share/coolicon/global.py

.include <bsd.port.mk>
