# New ports collection makefile for:	gaim-guifications
# Date created:		2004-05-04
# Whom:			ports@c0decafe.net
#
# $FreeBSD$
#

PORTNAME=	musictracker
PORTVERSION=	0.4.1
PORTREVISION=	2
CATEGORIES=	audio
MASTER_SITES=	GOOGLE_CODE
PKGNAMEPREFIX=	pidgin-

MAINTAINER=	ports@c0decafe.net
COMMENT=	Plugin for Pidgin to displays the music track currently playing

BUILD_DEPENDS=	${LOCALBASE}/include/pidgin/pidgin.h:${PORTSDIR}/net-im/pidgin
RUN_DEPENDS=	pidgin:${PORTSDIR}/net-im/pidgin
LIB_DEPENDS=	pcre.0:${PORTSDIR}/devel/pcre

USE_BZIP2=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	"CPPFLAGS=-I${LOCALBASE}/include" "LIBS=-L${LOCALBASE}/lib"

.include <bsd.port.mk>
