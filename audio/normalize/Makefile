# New ports collection makefile for:   normalize
# Date created:        31 January 2001
# Whom:                George Reid <greid@ukug.uk.freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	normalize
PORTVERSION=	0.7.6
PORTREVISION=	3
CATEGORIES=	audio
MASTER_SITES=	http://www1.cs.columbia.edu/~cvaill/normalize/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A tool for adjusting the volume of wave/MP3 files to a standard level

LIB_DEPENDS=	mad.2:${PORTSDIR}/audio/mad

USE_BZIP2=	yes	# XXX set before OPTIONS
OPTIONS=	XMMS "Build XMMS plugin" off
.include <bsd.port.pre.mk>
.if defined(WITH_XMMS)
LIB_DEPENDS+=	xmms.4:${PORTSDIR}/multimedia/xmms
.endif

USE_GETOPT_LONG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"
.if defined(WITH_XMMS)
PLIST_SUB+=	XMMS=""
.else
CONFIGURE_ARGS=	--disable-xmms
PLIST_SUB+=	XMMS="@comment "
.endif

.if !defined(WITHOUT_NLS)
USE_GETTEXT=	yes
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS+=--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

MAN1=		normalize.1 normalize-mp3.1

CPPFLAGS=	-I${LOCALBASE}/include
LDFLAGS=	-L${LOCALBASE}/lib

.include <bsd.port.post.mk>
