# New ports collection makefile for:   normalize
# Date created:        31 January 2001
# Whom:                George Reid <greid@ukug.uk.freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	normalize
PORTVERSION=	0.7.6
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	http://www1.cs.columbia.edu/~cvaill/normalize/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A tool for adjusting the volume of wave/MP3 files to a standard level

LIB_DEPENDS=	mad.2:${PORTSDIR}/audio/mad \
		intl.5:${PORTSDIR}/devel/gettext-old

USE_BZIP2=	yes
USE_GETOPT_LONG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"
CONFIGURE_ARGS=	--disable-xmms

MAN1=		normalize.1 normalize-mp3.1

CPPFLAGS=	-I${LOCALBASE}/include
LDFLAGS=	-L${LOCALBASE}/lib

.include <bsd.port.mk>
