# New ports collection makefile for:   vpce
# Version required:    0.3f
# Date created:        20 August 1997
# Whom:                Yukihiro Nakai <Nakai@Mlab.t.u-tokyo.ac.jp>
#
# $Id: Makefile,v 1.1.1.1 1998/12/15 21:30:02 jseger Exp $
#

DISTNAME=	vpce03f_freebsd
PKGNAME=	vpce-0.3f
CATEGORIES=	emulators
MASTER_SITES=	http://www.fortunecity.com/roswell/vanthal/10/
EXTRACT_SUFX=	.tgz

MAINTAINER=	nacai@iname.com

NO_WRKSUBDIR=	yes
USE_XLIB=	yes
NO_BUILD=	yes

STRIP=

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xvpce_03f_freebsd ${PREFIX}/bin/xvpce
.if !defined(NOPORTDOCS)
	@ ${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/README.vpce
.endif

.include <bsd.port.mk>
