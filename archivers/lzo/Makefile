# New ports collection makefile for:	lzo
# Date created:				21 Feb 1998
# Whom:					giffunip@asme.org
#
# $FreeBSD$
#

PORTNAME=	lzo
PORTVERSION=	1.06
CATEGORIES=	archivers devel
MASTER_SITES= 	${MASTER_SITE_SUNSITE} \
		http://wildsau.idv.uni-linz.ac.at/mfx/lzo-download/
MASTER_SITE_SUBDIR=	libs/compression

MAINTAINER=	ports@FreeBSD.org

USE_LIBTOOL=	yes
INSTALLS_SHLIBS=	yes

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/lzo
	${INSTALL_DATA}	${WRKSRC}/doc/* ${PREFIX}/share/doc/lzo
.endif

.include <bsd.port.mk>
