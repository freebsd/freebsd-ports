# New ports collection makefile for:	jad
# Date created:				27 September 2000
# Whom:	      				Yen-Ming Lee <leeym@cae.ce.ntu.edu.tw>
#
# $FreeBSD$
#

PORTNAME=	jad
PORTVERSION=	1.5.8c
CATEGORIES=	java
MASTER_SITES=	http://www.metaverse.nl/~ernst/ \
		http://www.pensioenconsult.com/ \
		http://www.schraven.nl/ \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	znerd
DISTNAME=	jadfb158

MAINTAINER=	znerd@FreeBSD.org

USE_ZIP=	yes
NO_WRKSUBDIR=	yes
NO_BUILD=	yes

.include <bsd.port.pre.mk>

.if ${ARCH} != "i386"
BROKEN=		Only supported on FreeBSD/i386
.endif

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/jad ${PREFIX}/bin/
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/jad
	@${INSTALL_DATA} ${WRKSRC}/Readme.txt ${PREFIX}/share/doc/jad/
.endif

.include <bsd.port.post.mk>
