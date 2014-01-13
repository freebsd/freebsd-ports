# Created by: Maxim Sobolev <sobomax@FreeBSD.org>
# $FreeBSD$

PORTNAME=	pysol-sound-server
PORTVERSION=	3.01
PORTREVISION=	5
CATEGORIES=	audio games
MASTER_SITES=	http://www.pysol.org/download/pysol/ \
		ftp://ftp.is.co.za/linux/distributions/gentoo/distfiles/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Python extension module to play sounds and background music

LIB_DEPENDS=	libsmpeg.so:${PORTSDIR}/multimedia/smpeg

WRKSRC=		${WRKDIR}/${DISTNAME}/src

USE_SDL=	mixer sdl
USE_BZIP2=	yes
USE_PYTHON=	2
HAS_CONFIGURE=	yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_AUTOPLIST=	yes
INSTALLS_EGGINFO=	yes
PYDISTUTILS_PKGNAME=	pysolsoundserver

.include <bsd.port.mk>
