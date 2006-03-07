# New ports collection makefile for:	show
# Date created:        06 July 2003
# Whom:                roop
#
# $FreeBSD$
#

PORTNAME=	show
PORTVERSION=	2.2
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	http://www.ibiblio.org/propaganda/ \
		http://www.freebsdbrasil.com.br/~jmelo/

MAINTAINER=	jmelo@freebsdbrasil.com.br
COMMENT=	A fast, flexible, extensible and bloat-free image viewer for X11

LIB_DEPENDS=	jpeg.9:${PORTSDIR}/graphics/jpeg	\
		png.5:${PORTSDIR}/graphics/png		\
		tiff.4:${PORTSDIR}/graphics/tiff	\
		ungif.5:${PORTSDIR}/graphics/libungif	\
		Imlib.5:${PORTSDIR}/graphics/imlib

USE_X_PREFIX=	yes

PLIST_FILES=	bin/show

post-extract:
	@${CP} ${PATCHDIR}/Makefile ${WRKSRC}
	@${RM} ${WRKSRC}/${PORTNAME}

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/show ${PREFIX}/bin

.include <bsd.port.mk>
