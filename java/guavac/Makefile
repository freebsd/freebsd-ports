# New ports collection makefile for:   guavac
# Date created:        10 October 1996
# Whom:                Yukihiro Nakai <Nakai@Mlab.t.u-tokyo.ac.jp>
#
# $FreeBSD$
#

PORTNAME=	guavac
PORTVERSION=	1.2
PORTREVISION=	1
CATEGORIES=	java
MASTER_SITES=	ftp://ftp.yggdrasil.com/pub/dist/devel/compilers/guavac/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Java compiler and decompiler developed under GPL

USE_GMAKE=	yes
GNU_CONFIGURE=	yes
MAN1=		guavac.1
STRIP=

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 500113
BROKEN=         "Does not compile (bad C++ code)"
.endif

pre-install:
	@${CHMOD} +x ${WRKSRC}/mkinstalldirs

post-install:
	@${STRIP_CMD} ${PREFIX}/bin/guavac ${PREFIX}/bin/guavad

.include <bsd.port.post.mk>
