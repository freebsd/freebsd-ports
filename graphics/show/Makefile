# New ports collection makefile for:	show
# Date created:        06 July 2003
# Whom:                roop
#
# $FreeBSD$
#

PORTNAME=	show
PORTVERSION=	2.2
PORTREVISION=	7
CATEGORIES=	graphics
MASTER_SITES=	http://www.ibiblio.org/propaganda/ \
		http://www.freebsdbrasil.com.br/~jmelo/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A fast, flexible, extensible and bloat-free image viewer for X11

LIB_DEPENDS=	jpeg.11:${PORTSDIR}/graphics/jpeg	\
		png.6:${PORTSDIR}/graphics/png		\
		tiff.4:${PORTSDIR}/graphics/tiff	\
		ungif.5:${PORTSDIR}/graphics/libungif	\
		Imlib.5:${PORTSDIR}/graphics/imlib

PLIST_FILES=	bin/show

post-extract:
	@${CP} ${PATCHDIR}/Makefile ${WRKSRC}
	@${RM} ${WRKSRC}/${PORTNAME}

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/show ${PREFIX}/bin

.include <bsd.port.mk>
