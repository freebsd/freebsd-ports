# New ports collection makefile for:	netpbm
# Date created:		?
# Whom:			jmz (original)
#
# $FreeBSD$
#

PORTNAME=	netpbm
PORTVERSION=	9.12
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org

LIB_DEPENDS=	tiff.4:${PORTSDIR}/graphics/tiff \
		jpeg.9:${PORTSDIR}/graphics/jpeg \
		png.4:${PORTSDIR}/graphics/png

USE_GMAKE=	yes
MAKEFILE=	GNUmakefile
ALL_TARGET=	merge
INSTALL_TARGET=	install-merge install-dev
INSTALLS_SHLIB=	yes

.include <bsd.port.pre.mk>

.include "${FILESDIR}/manpages"

post-patch:
	@${PERL} -pi -e "s|%%X11BASE%%|${X11BASE}|g" ${WRKSRC}/pbmplus.h
	@${CP} ${FILESDIR}/Makefile.config.FreeBSD ${WRKSRC}/Makefile.config

.include <bsd.port.post.mk>
