# New ports collection makefile for:   guavac
# Version required:    1.2
# Date created:        10 October 1996
# Whom:                Yukihiro Nakai <Nakai@Mlab.t.u-tokyo.ac.jp>
#
# $Id: Makefile,v 1.11 1999/01/12 16:50:46 vanilla Exp $
#

DISTNAME=	guavac-1.2
CATEGORIES=	lang
MASTER_SITES=	ftp://ftp.yggdrasil.com/pub/dist/devel/compilers/guavac/

MAINTAINER=	nacai@iname.com

CC=		gcc28
CXX=		g++28
BUILD_DEPENDS=	${LOCALBASE}/i386-portbld-freebsd${OSREL}/lib/libiberty.a:${PORTSDIR}/lang/glibstdc++28

USE_GMAKE=	yes
GNU_CONFIGURE=	yes
MAN1=		guavac.1
STRIP=

pre-install:
	@chmod +x ${WRKSRC}/mkinstalldirs

post-install:
	@strip ${PREFIX}/bin/guavac ${PREFIX}/bin/guavad

.include <bsd.port.mk>
