# New ports collection makefile for:	exiv2
# Date created:		2004-09-24
# Whom:			Michael Johnson <ahze@ahze.net>
#
# $FreeBSD$
#

PORTNAME=	exiv2
PORTVERSION=	0.12
CATEGORIES=	graphics
MASTER_SITES=	http://www.exiv2.org/

MAINTAINER=	multimedia@FreeBSD.org
COMMENT=	Exif and Iptc metadata manipulation library and tools

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_LDCONFIG=	yes
MAN1=		exiv2.1
ALLTARGET=	all
CONFIGURE_ARGS=	--mandir=${PREFIX}/man
USE_GCC=	3.4+
PORTDOCS=	*

.if !defined(NOPORTDOCS)
post-install:
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/doc/html/* ${DOCSDIR}
.endif

.include <bsd.port.mk>
