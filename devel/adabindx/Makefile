# New ports collection makefile for:   adabindx
# Date created:        23 December 2002
# Whom:                David Holm <david@realityrift.com>
#
# $FreeBSD$
#

PORTNAME=	adabindx
PORTVERSION=	0.7.2
CATEGORIES=	devel
MASTER_SITES=	http://home.arcor.de/hfvogt/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An Ada-binding to the X Window System and *tif

BUILD_DEPENDS=	gnatmake:${PORTSDIR}/lang/gnat

USE_MOTIF=	yes
PREFIX=		${X11BASE}

post-patch:
#	@mv ${WRKSRC}/lib ${WRKSRC}/src

#do-install:
#	@${MKDIR} ${X11BASE}/lib/adabindx
#	@(for i in `cat pkg-plist|grep "lib/adabindx"|grep -v dirrm|sed "s/lib\/adabindx\///"`; do \
#		${INSTALL_DATA} ${WRKSRC}/lib/$${i} ${PREFIX}/lib/adabindx; \
#	done)
#
#	@${MKDIR} ${X11BASE}/share/adabindx
#	@(for i in `cat pkg-plist|grep "share/adabindx"|grep -v dirrm|sed "s/share\/adabindx\///"`; do \
#		${INSTALL_DATA} ${WRKSRC}/$${i} ${PREFIX}/share/adabindx; \
#	done)

.include <bsd.port.mk>
