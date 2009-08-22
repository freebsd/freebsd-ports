# New ports collection makefile for:	bebocd
# Date created:				02 July 2003
# Whom:					Adam Weinberger <adamw@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	bebocd
PORTVERSION=	0.4
PORTREVISION=	9
CATEGORIES=	audio
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GTK2 CD Player

LIB_DEPENDS=	cdaudio.1:${PORTSDIR}/audio/libcdaudio

USE_XORG=	x11
USE_GNOME=	gnomehack gtk20
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

post-patch:
.if defined(CDROM) && exists(${CDROM})
	@${REINPLACE_CMD} -e "s|/dev/cdrom|${CDROM}|" ${WRKSRC}/src/main.h
.else
	@${ECHO_MSG} ""
	@${ECHO_MSG} "You can specify the default CD-ROM device by defining CDROM."
	@${ECHO_MSG} "For example, CDROM=\"/dev/acd0c\" make"
	@${ECHO_MSG} ""
.endif
	@${REINPLACE_CMD} -e "s|gpointer	data|gpointer	arg|" ${WRKSRC}/src/callbacks.c

.include <bsd.port.mk>
