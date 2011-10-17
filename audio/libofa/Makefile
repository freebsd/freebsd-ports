# New ports collection makefile for:	libofa
# Date created:		2006-04-01
# Whom:			Alexander Botero-Lowry <alex@foxybanana.com>
#
# $FreeBSD$
#

PORTNAME=	libofa
PORTVERSION=	0.9.3
PORTREVISION=	7
CATEGORIES=	audio
MASTER_SITES=	GOOGLE_CODE

MAINTAINER=	bsdkaffee@gmail.com
COMMENT=	The Open Fingerprint Architecture Library

LIB_DEPENDS=	fftw3:${PORTSDIR}/math/fftw3 \
		expat.6:${PORTSDIR}/textproc/expat2 \
		curl.6:${PORTSDIR}/ftp/curl

PROJECTHOST=	musicip-libofa
USE_DOS2UNIX=	yes
USE_AUTOTOOLS=	libtool
USE_GNOME=	gnomehack pkgconfig
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
MAKE_JOBS_SAFE=	yes
USE_LDCONFIG=	yes

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

.include <bsd.port.mk>
