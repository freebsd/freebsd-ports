# New ports collection makefile for:	hanterm-xf86
# Version required:     hanterm-xf-p14
# Date created:		22 Mar 1997
# Whom:			CHOI Junho <junker@jazz.snu.ac.kr>
#
# $Id: Makefile,v 1.7 1998/08/05 09:31:21 asami Exp $
#

DISTNAME=	hanterm-xf-p14
PKGNAME=	ko-hanterm-xf14
CATEGORIES=	korean x11
MASTER_SITES=	http://pseudo.snu.ac.kr/~hwang/

MAINTAINER=	junker@jazz.snu.ac.kr

RUN_DEPENDS=	${PREFIX}/lib/X11/fonts/misc/johabm16.pcf.gz:${PORTSDIR}/korean/johabfonts

USE_X_PREFIX=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS=		--with-x --build=i386--freebsd --prefix=${PREFIX}
NO_INSTALL_MANPAGES=	yes

post-install:
	@${INSTALL_DATA} ${WRKSRC}/Hanterm.ad ${PREFIX}/lib/X11/app-defaults/Hanterm

.include <bsd.port.mk>
