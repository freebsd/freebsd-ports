# New ports collection makefile for:   guavac
# Version required:    1.2
# Date created:        10 October 1996
# Whom:                Yukihiro Nakai <Nakai@Mlab.t.u-tokyo.ac.jp>
#
# $Id: Makefile,v 1.13 1999/05/12 22:45:03 asami Exp $
#

DISTNAME=	guavac-1.2
CATEGORIES=	java
MASTER_SITES=	ftp://ftp.yggdrasil.com/pub/dist/devel/compilers/guavac/

MAINTAINER=	nacai@iname.com

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 400004
CC=		egcc
CXX=		eg++
BUILD_DEPENDS=	egcc:${PORTSDIR}/lang/egcs
.endif

USE_GMAKE=	yes
GNU_CONFIGURE=	yes
MAN1=		guavac.1
STRIP=

pre-install:
	@chmod +x ${WRKSRC}/mkinstalldirs

post-install:
	@strip ${PREFIX}/bin/guavac ${PREFIX}/bin/guavad

.include <bsd.port.post.mk>
