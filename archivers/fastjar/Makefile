# New ports collection makefile for:	fastjar
# Version required:     0.90
# Date created:		18 March 2000
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

DISTNAME=	fastjar-0.90
CATEGORIES=	archivers java
MASTER_SITES=	http://download.sourceforge.net/fastjar/
EXTRACT_SUFX=	.tgz

MAINTAINER=	knu@idaemons.org

GNU_CONFIGURE=	YES

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/fastjar
	cd ${WRKSRC} && ${INSTALL_DATA} CHANGES README ${PREFIX}/share/doc/fastjar/
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
