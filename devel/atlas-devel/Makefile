# New ports collection makefile for:	Atlas
# Date created:				29 March 2001
# Whom:					Oliver Lehmann <lehmann@ans-netz.de>
#
# $FreeBSD$
#

PORTNAME=	Atlas
PORTVERSION=	0.4.6
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.lyx.org/pub/worldforge/libs/Atlas-C++/ \
		ftp://victor.worldforge.org/pub/worldforge/libs/Atlas-C++/
DISTNAME=	${PORTNAME}-C++-${PORTVERSION}

MAINTAINER=	oliver@FreeBSD.org
COMMENT=	A C++ reference implementation of the Atlas protocol

USE_REINPLACE=	YES
USE_LIBTOOL=	YES
GNU_CONFIGURE=	YES

post-patch:
	@${REINPLACE_CMD} -e 's| install-data-local||g' \
		-e 's|\(^pkgconfigdir =\) .*|\1 ${PREFIX}/libdata/pkgconfig|g' \
		${WRKSRC}/Makefile.in

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in README COPYING AUTHORS THANKS NEWS
	@${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
