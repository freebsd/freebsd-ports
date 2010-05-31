# New ports collection makefile for:	libzvbi
# Date created:				15 May 2003
# Whom:					Oliver Lehmann <oliver@freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	libzvbi
PORTVERSION=	0.2.33
PORTREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	SF/zapping/zvbi/${PORTVERSION}
DISTNAME=	${PORTNAME:S/lib//}-${PORTVERSION}

MAINTAINER=	oliver@FreeBSD.org
COMMENT=	Routines to access raw VBI capture devices

LIB_DEPENDS+=	png.6:${PORTSDIR}/graphics/png \
		unicode.0:${PORTSDIR}/devel/libunicode

USE_GETTEXT=	yes
USE_BZIP2=	yes
USE_GNOME=	gnomehack pkgconfig
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
MAN1=		zvbi-ntsc-cc.1

CONFIGURE_ENV= CFLAGS="${CFLAGS} -I${LOCALBASE}/include" LIBS="-L${LOCALBASE}/lib -L/usr/lib"

post-patch:
	@${REINPLACE_CMD} -e 's|-lpthread|${PTHREAD_LIBS}|g' ${WRKSRC}/configure
#	@${REINPLACE_CMD} -e 's|malloc\.h|stdlib\.h|g' \
#		${WRKSRC}/contrib/atsc-cc.c
#	@${REINPLACE_CMD} -e 's|-I\.|& -I\.\./src|g' \
#		${WRKSRC}/contrib/Makefile.in
	@${REINPLACE_CMD} -e 's|zvbi-atsc-cc$$(EXEEXT)||g; \
		s|zvbi-atsc-cc\.1||g' ${WRKSRC}/contrib/Makefile.in

.include <bsd.port.mk>
