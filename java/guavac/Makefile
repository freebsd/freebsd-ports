# New ports collection makefile for:   guavac
# Version required:    1.2
# Date created:        10 October 1996
# Whom:                Yukihiro Nakai <Nakai@Mlab.t.u-tokyo.ac.jp>
#
# $Id: Makefile,v 1.15 1999/08/17 19:36:56 cpiazza Exp $
#

DISTNAME=	guavac-1.2
CATEGORIES=	java
MASTER_SITES=	ftp://ftp.yggdrasil.com/pub/dist/devel/compilers/guavac/

MAINTAINER=	nacai@iname.com

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 400004
CC=		gcc295
CXX=		g++295
BUILD_DEPENDS=	gcc295:${PORTSDIR}/lang/egcs
.endif

USE_GMAKE=	yes
GNU_CONFIGURE=	yes
MAN1=		guavac.1
STRIP=

pre-install:
	@${CHMOD} +x ${WRKSRC}/mkinstalldirs

post-install:
	@strip ${PREFIX}/bin/guavac ${PREFIX}/bin/guavad

.include <bsd.port.post.mk>
