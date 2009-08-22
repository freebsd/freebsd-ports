# New ports collection makefile for:	libgig
# Date created:		2007-01-24
# Whom:			trasz <trasz@pin.if.uz.zgora.pl>
#
# $FreeBSD$
#

PORTNAME=	libgig
PORTVERSION=	3.3.0
CATEGORIES=	audio
MASTER_SITES=	http://download.linuxsampler.org/packages/

MAINTAINER=	trasz@FreeBSD.org
COMMENT=	Gigasampler file loader library

LIB_DEPENDS=	FLAC.10:${PORTSDIR}/audio/flac \
		sndfile.1:${PORTSDIR}/audio/libsndfile

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--mandir=${PREFIX}/man
USE_GMAKE=	yes
USE_GNOME=	gnomehack
USE_LDCONFIG=	yes

MAN1=		dlsdump.1 gigdump.1 gigextract.1 rifftree.1

.include <bsd.port.mk>
