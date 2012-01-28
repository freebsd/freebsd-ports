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

OPTIONS=	MIKMOD "Enable libmikmod support" on

USE_GNOME=	gtk20
USE_PERL5=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
MAKE_JOBS_SAFE=	yes

MAN6=		xscorch.6

.include <bsd.port.options.mk>

.if defined(WITHOUT_MIKMOD)
CONFIGURE_ARGS+=--disable-sound
.else
LIB_DEPENDS+=	mikmod.2:${PORTSDIR}/audio/libmikmod
CONFIGURE_ARGS+=--with-libmikmod-prefix=${LOCALBASE}
.endif

.include <bsd.port.mk>
