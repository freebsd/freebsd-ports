# New ports collection makefile for:	exiv2
# Date created:		2004-09-24
# Whom:			Michael Johnson <ahze@ahze.net>
#
# $FreeBSD$
#

PORTNAME=	exiv2
PORTVERSION=	0.7
CATEGORIES=	graphics
MASTER_SITES=	http://home.arcor.de/ahuggel/exiv2/

MAINTAINER=	ahze@FreeBSD.org
COMMENT=	Exif and Iptc metadata manipulation library and tools

.if defined(PORTDOCS)
BUILD_DEPENDS=	doxygen:${PORTSDIR}/devel/doxygen
.endif

USE_LIBTOOL_VER=15
USE_GMAKE=	yes
INSTALLS_SHLIB=	yes

PORTDOCS=	*

.if defined(PORTDOCS)
ALLTARGET=	all doc
.endif

.include <bsd.port.pre.mk>

.if ${ARCH} == "alpha"
BROKEN=		"Does not compile on alpha"
.endif

.if ${OSVERSION} < 500000
USE_GCC=	3.4
.endif

post-install:
.if defined(PORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/doc/html/* ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
