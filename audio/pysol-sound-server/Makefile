# New ports collection makefile for:	pysol-sound-server
# Date created:				7 January 2000
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	pysol-sound-server
PORTVERSION=	3.01
#PORTREVISION=	2
CATEGORIES=	audio games
MASTER_SITES=	http://www.pysol.org/download/pysol/ \
		ftp://ftp.is.co.za/linux/distributions/gentoo/distfiles/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Python extension module to play sounds and background music

LIB_DEPENDS=	smpeg.1:${PORTSDIR}/multimedia/smpeg

PLIST_FILES=	lib/%%PYTHON_VERSION%%/site-packages/pysolsoundserver.so
WRKSRC=		${WRKDIR}/${DISTNAME}/src

USE_SDL=	mixer sdl
USE_BZIP2=	yes
USE_PYTHON=	yes
HAS_CONFIGURE=	yes

.include <bsd.port.mk>
