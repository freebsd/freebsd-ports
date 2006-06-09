# New ports collection makefile for:	exiv2
# Date created:		2004-09-24
# Whom:			Michael Johnson <ahze@ahze.net>
#
# $FreeBSD$
#

PORTNAME=	exiv2
PORTVERSION=	0.10
CATEGORIES=	graphics
MASTER_SITES=	http://www.exiv2.org/

MAINTAINER=	multimedia@FreeBSD.org
COMMENT=	Exif and Iptc metadata manipulation library and tools

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
INSTALLS_SHLIB=	yes
MAN1=		exiv2.1
ALLTARGET=	all

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
USE_GCC=	3.4
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|$${datarootdir}/man|${PREFIX}/man|' \
		${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|$$(libdir)/pkgconfig|${PREFIX}/libdata/pkgconfig|' \
		${WRKSRC}/src/Makefile

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/doc/html/* ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
