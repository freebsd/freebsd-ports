# New ports collection makefile for:	fastjar
# Date created:		18 March 2000
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	fastjar
PORTVERSION=	0.93
PORTREVISION=	1
CATEGORIES=	archivers java
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A version of JDK's `jar' command written entirely in C

GNU_CONFIGURE=	yes
USE_GMAKE=	yes

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/fastjar
	cd ${WRKSRC} && ${INSTALL_DATA} CHANGES README ${PREFIX}/share/doc/fastjar/
	@${CAT} ${PKGMESSAGE}
.endif

.include <bsd.port.mk>
