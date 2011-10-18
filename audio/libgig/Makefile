# New ports collection makefile for:	libgig
# Date created:		2007-01-24
# Whom:			trasz <trasz@pin.if.uz.zgora.pl>
#
# $FreeBSD$
#

PORTNAME=	libgig
PORTVERSION=	3.3.0
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	SF/qsampler/${PORTNAME}/${PORTVERSION} \
		http://download.linuxsampler.org/packages/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Gigasampler file loader library

LICENSE=	GPLv2

LIB_DEPENDS=	FLAC.10:${PORTSDIR}/audio/flac \
		sndfile.1:${PORTSDIR}/audio/libsndfile \
		uuid.1:${PORTSDIR}/misc/e2fsprogs-libuuid

USE_BZIP2=	yes
USE_GNOME=	gnomehack
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
MAKE_JOBS_UNSAFE=yes

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

MAN1=		dlsdump.1 gigdump.1 gigextract.1 rifftree.1

.include <bsd.port.mk>
