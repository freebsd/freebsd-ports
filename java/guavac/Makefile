# New ports collection makefile for:   guavac
# Version required:    1.2
# Date created:        10 October 1996
# Whom:                Yukihiro Nakai <Nakai@Mlab.t.u-tokyo.ac.jp>
#
# $Id: Makefile,v 1.6 1997/11/14 10:20:25 tg Exp $
#

DISTNAME=	guavac-1.2
CATEGORIES=	lang
MASTER_SITES=	ftp://ftp.yggdrasil.com/pub/dist/devel/compilers/guavac/

MAINTAINER=	Nakai@technologist.com

CC=		gcc28
CXX=		g++28
GNUOSREL!=	uname -r | sed -e 's/[-(].*//'
LIB_DEPENDS=	${LOCALBASE}/i386-unknown-freebsd${GNUOSREL}/lib/libiberty.a:${PORTSDIR}/lang/glibstdc++28

USE_GMAKE=	yes
GNU_CONFIGURE=	yes
MAN1=		guavac.1
STRIP=

pre-install:
	@chmod +x ${WRKSRC}/mkinstalldirs

post-install:
	@strip ${PREFIX}/bin/guavac ${PREFIX}/bin/guavad

.include <bsd.port.mk>
