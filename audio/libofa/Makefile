# Created by: Alexander Botero-Lowry <alex@foxybanana.com>
# $FreeBSD$

PORTNAME=	libofa
PORTVERSION=	0.9.3
PORTREVISION=	8
CATEGORIES=	audio
MASTER_SITES=	GOOGLE_CODE

MAINTAINER=	jhale@FreeBSD.org
COMMENT=	The Open Fingerprint Architecture Library

LICENSE=		APL1 GPLv2
LICENSE_COMB=		dual
LICENSE_GROUPS_APL1=	OSI
LICENSE_NAME_APL1=	Adaptive Public License version 1.0
LICENSE_FILE_APL1=	${WRKSRC}/COPYING
LICENSE_PERMS_APL1=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

LIB_DEPENDS=	libfftw3.so:${PORTSDIR}/math/fftw3 \
		libexpat.so:${PORTSDIR}/textproc/expat2 \
		libcurl.so:${PORTSDIR}/ftp/curl

PROJECTHOST=	musicip-libofa
USE_DOS2UNIX=	yes
USE_AUTOTOOLS=	libtool
USES=		pathfix
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
USE_LDCONFIG=	yes

.include <bsd.port.mk>
