# New ports collection makefile for:	netpbm
# Date created:		?
# Whom:			jmz (original)
#
# $FreeBSD$
#

PORTNAME=	netpbm
PORTVERSION=	9.4
CATEGORIES=	graphics
MASTER_SITES=	http://download.sourceforge.net/netpbm/
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org

LIB_DEPENDS=	tiff.4:${PORTSDIR}/graphics/tiff \
		jpeg.9:${PORTSDIR}/graphics/jpeg \
		png.3:${PORTSDIR}/graphics/png

USE_GMAKE=	yes
MAKEFILE=	GNUmakefile
ALL_TARGET=	merge
INSTALL_TARGET=	install-merge install-dev

.include <bsd.port.pre.mk>

.include "${FILESDIR}/manpages"

post-patch:
	@${PERL} -pi -e "s|%%X11BASE%%|${X11BASE}|g" ${WRKSRC}/pbmplus.h

post-install:
	${LDCONFIG} -m ${PREFIX}/lib

.include <bsd.port.post.mk>
