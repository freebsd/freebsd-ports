# New ports collection makefile for:	xscorch
# Date created:				19 Apr 2000
# Whom:					will
#
# $FreeBSD$
#

PORTNAME=	xscorch
PORTVERSION=	0.2.1
CATEGORIES=	games
MASTER_SITES=	http://www.xscorch.org/releases/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Multiplayer tank shoot-em-up

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	mikmod.2:${PORTSDIR}/audio/libmikmod

USE_XORG=	xpm
USE_GNOME=	gtk20
WANT_GNOME=	yes
USE_PERL5=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-gtk
MAKE_JOBS_SAFE=	yes

MAN6=		xscorch.6
NO_MANCOMPRESS=	yes

.include <bsd.port.pre.mk>

.if ${HAVE_GNOME:Mgnomelibs}!=""
USE_GNOME+=	gnomeprefix gnomelibs
PKGNAMESUFFIX=	-gnome
.else
CONFIGURE_ARGS+=	--without-gnome
.endif

post-patch:
	@${REINPLACE_CMD} -e 's,MSG_NOSIGNAL,0,' \
		${WRKSRC}/snet/tcpnet/tn_internal.c \
		${WRKSRC}/snet/tcpnet/tn_read.c

.include <bsd.port.post.mk>
