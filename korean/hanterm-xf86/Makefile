# New ports collection makefile for:	hanterm-xf86
# Version required:     hanterm-xf331-p13
# Date created:		22 Mar 1997
# Whom:			CHOI Junho <junker@jazz.snu.ac.kr>
#
# $Id: Makefile,v 1.4 1998/03/28 14:39:28 steve Exp $
#

DISTNAME=	hanterm-xf331-p13
PKGNAME=	ko-hanterm-xf-3.3.1.13
CATEGORIES=	korean x11
MASTER_SITES=	ftp://ftp.kaist.ac.kr/pub/hangul/incoming/

MAINTAINER=	junker@jazz.snu.ac.kr

RUN_DEPENDS=	${PREFIX}/lib/X11/fonts/korean/johab:${PORTSDIR}/korean/johabfonts

USE_X11=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS=		--with-x --build=i386--freebsd --prefix=${PREFIX}
NO_INSTALL_MANPAGES=	yes

post-install:
	@${INSTALL_DATA} ${WRKSRC}/Hanterm.ad ${PREFIX}/lib/X11/app-defaults/Hanterm

.include <bsd.port.mk>
