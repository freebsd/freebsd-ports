# New ports collection makefile for:	hanterm-xf86
# Version required:     hanterm-xf-p14
# Date created:		22 Mar 1997
# Whom:			CHOI Junho <junker@jazz.snu.ac.kr>
#
# $Id: Makefile,v 1.12 1999/01/15 05:34:48 kuriyama Exp $
#

DISTNAME=	hanterm-xf-p16
PKGNAME=	ko-hanterm-xf-16
CATEGORIES=	korean x11
MASTER_SITES=	http://pseudo.snu.ac.kr/~hwang/

MAINTAINER=	cjh@kr.freebsd.org

RUN_DEPENDS=	${PREFIX}/lib/X11/fonts/local/johabm16.pcf.gz:${PORTSDIR}/korean/johabfonts

USE_X_PREFIX=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS=		--with-x --build=i386--freebsd --prefix=${PREFIX} \
			--enable-16-color
NO_INSTALL_MANPAGES=	yes

post-install:
	@${INSTALL_DATA} ${WRKSRC}/Hanterm.ad ${PREFIX}/lib/X11/app-defaults/Hanterm

.include <bsd.port.mk>
