# New ports collection makefile for:	rio500
# Date created:		27 May 2000
# Whom:			Kazumasa Nishizawa <k_nishizawa@anet.ne.jp>
#
# $FreeBSD$
#

PORTNAME=       rio500
PORTVERSION=	0.7
CATEGORIES=     audio
MASTER_SITES=   http://download.sourceforge.net/rio500/

MAINTAINER=	k_nishizawa@anet.ne.jp

LIB_DEPENDS=    glib12:${PORTSDIR}/devel/glib12

GLIB_CONFIG=	${LOCALBASE}/bin/glib12-config

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-devicepath='/dev' \
		--with-deviceentry='urio0' \
		--with-id3support
CONFIGURE_ENV=  GLIB_CONFIG="${GLIB_CONFIG}"

.include <bsd.port.mk>
