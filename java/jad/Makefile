# New ports collection makefile for:	jad
# Date created:				27 September 2000
# Whom:	      				Yen-Ming Lee <leeym@cae.ce.ntu.edu.tw>
#
# $FreeBSD$
#

PORTNAME=	jad
PORTVERSION=	1.5.8c
CATEGORIES=	java
MASTER_SITES=	http://www.geocities.com/SiliconValley/Bridge/8617/jad/freebsd/ \
		http://www.metaverse.nl/~ernst/ \
		http://www.pensioenconsult.com/ \
		http://www.schraven.nl/
DISTNAME=	jadfb158

MAINTAINER=	znerd@FreeBSD.org

USE_ZIP=	yes
NO_WRKSUBDIR=	yes
NO_BUILD=	yes

.include <bsd.port.pre.mk>

.if ${ARCH} == "alpha"
BROKEN=		Not supported on FreeBSD/Alpha
.endif

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/jad ${PREFIX}/bin/
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/jad
	@${INSTALL_DATA} ${WRKSRC}/Readme.txt ${PREFIX}/share/doc/jad/
.endif

.include <bsd.port.post.mk>
