# New ports collection makefile for:	libzvbi
# Date created:				15 May 2003
# Whom:					Oliver Lehmann <oliver@freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	libzvbi
PORTVERSION=	0.2.21
PORTREVISION=	0
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	zapping
DISTNAME=	${PORTNAME:S/lib//}-${PORTVERSION}

MAINTAINER=	oliver@FreeBSD.org
COMMENT=	Routines to access raw VBI capture devices

LIB_DEPENDS+=	png.5:${PORTSDIR}/graphics/png \
		unicode.0:${PORTSDIR}/devel/libunicode

USE_GETTEXT=	yes
USE_BZIP2=	yes
USE_GNOME=	gnomehack pkgconfig
GNU_CONFIGURE=	yes
INSTALLS_SHLIB=	yes
MAN1=		zvbi-ntsc-cc.1

CONFIGURE_ENV= CFLAGS="${CFLAGS} -I${LOCALBASE}/include" LIBS="-L${LOCALBASE}/lib -L/usr/lib"

post-patch:
	@${REINPLACE_CMD} -e 's|-lpthread|${PTHREAD_LIBS}|g' ${WRKSRC}/configure

.include <bsd.port.mk>
