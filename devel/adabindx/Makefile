# New ports collection makefile for:   adabindx
# Date created:        23 December 2002
# Whom:                David Holm <david@realityrift.com>
#
# $FreeBSD$
#

PORTNAME=	adabindx
PORTVERSION=	0.7.2
PORTREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	http://home.arcor.de/hfvogt/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An Ada-binding to the X Window System and *tif

BUILD_DEPENDS=	gnatmake:${PORTSDIR}/lang/gnat

BROKEN=		does not build
DEPRECATED=	has been broken for 3 months
EXPIRATION_DATE=2010-01-08

USE_MOTIF=	yes
USE_XORG=	x11

post-patch:
#	@mv ${WRKSRC}/lib ${WRKSRC}/src

#do-install:
#	@${MKDIR} ${LOCALBASE}/lib/adabindx
#	@(for i in `cat pkg-plist|grep "lib/adabindx"|grep -v dirrm|sed "s/lib\/adabindx\///"`; do \
#		${INSTALL_DATA} ${WRKSRC}/lib/$${i} ${PREFIX}/lib/adabindx; \
#	done)
#
#	@${MKDIR} ${LOCALBASE}/share/adabindx
#	@(for i in `cat pkg-plist|grep "share/adabindx"|grep -v dirrm|sed "s/share\/adabindx\///"`; do \
#		${INSTALL_DATA} ${WRKSRC}/$${i} ${PREFIX}/share/adabindx; \
#	done)

.include <bsd.port.mk>
