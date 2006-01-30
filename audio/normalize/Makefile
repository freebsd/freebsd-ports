# New ports collection makefile for:   normalize
# Date created:        31 January 2001
# Whom:                George Reid <greid@ukug.uk.freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	normalize
PORTVERSION=	0.7.7
CATEGORIES=	audio
MASTER_SITES=	http://download.savannah.gnu.org/releases/normalize/

MAINTAINER=	alex@fafula.com
COMMENT=	A tool for adjusting the volume of wave/MP3 files to a standard level

LIB_DEPENDS=	mad.2:${PORTSDIR}/audio/libmad

USE_BZIP2=		yes
USE_GETOPT_LONG=	yes
GNU_CONFIGURE=		yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ENV=		CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"
CPPFLAGS=		-I${LOCALBASE}/include
LDFLAGS=		-L${LOCALBASE}/lib

MAN1=		normalize.1 normalize-mp3.1

OPTIONS=	XMMS "Build XMMS plugin" off

.include <bsd.port.pre.mk>

.if defined(WITH_XMMS)
LIB_DEPENDS+=	xmms.4:${PORTSDIR}/multimedia/xmms
PLIST_SUB+=	XMMS=""
PLIST_SUB+=	X11BASE="${X11BASE}"
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

.include <bsd.port.post.mk>
