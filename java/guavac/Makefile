# New ports collection makefile for:   guavac
# Version required:    1.2
# Date created:        10 October 1996
# Whom:                Yukihiro Nakai <Nakai@Mlab.t.u-tokyo.ac.jp>
#
# $FreeBSD$
#

DISTNAME=	guavac-1.2
CATEGORIES=	java
MASTER_SITES=	ftp://ftp.yggdrasil.com/pub/dist/devel/compilers/guavac/

MAINTAINER=	nacai@iname.com

USE_NEWGCC=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
MAN1=		guavac.1
STRIP=

pre-install:
	@${CHMOD} +x ${WRKSRC}/mkinstalldirs

post-install:
	@strip ${PREFIX}/bin/guavac ${PREFIX}/bin/guavad

.include <bsd.port.mk>
