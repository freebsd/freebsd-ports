# New ports collection makefile for:   zh-aterm
# Version required:	0.3.6
# Date created:		26 April 1999
# Whom:			Chia-Hsing Yu <davidyu@ken.csie.ntu.edu.tw>
#
# $FreeBSD$
#

DISTNAME=	aterm-0.3.6
PKGNAME=	zh-aterm-0.3.6
CATEGORIES=	chinese
MASTER_SITES=	http://members.xoom.com/sashav/aterm/ \
		http://www.tigr.net/afterstep/as-apps/download/aterm/	\
		http://www.freebsd.org/~foxfair/

MAINTAINER=	davidyu@ken.csie.ntu.edu.tw

LIB_DEPENDS=	Xpm.4:${PORTSDIR}/graphics/xpm \
		jpeg.9:${PORTSDIR}/graphics/jpeg \
		png.3:${PORTSDIR}/graphics/png

USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-transparency --enable-background-image \
		--disable-delete-key --disable-backspace-key \
		--enable-fading --enable-utmp --enable-wtmp --enable-big5
MAN1=		aterm.1

post-patch:
	${CP} ${FILESDIR}/cli_xcin.c ${WRKSRC}/src/
	${CP} ${FILESDIR}/state.h ${WRKSRC}/src/
	${CP} ${FILESDIR}/protocol.h ${WRKSRC}/src/
	
.include <bsd.port.mk>
