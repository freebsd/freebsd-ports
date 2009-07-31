# New ports collection makefile for:	nautilus-sendto
# Date created:		2004-12-03
# Whom:			Michael Johnson <ahze@FreeBSD.org>
#
# $FreeBSD$
#    $MCom: ports-stable/deskutils/nautilus-sendto/Makefile,v 1.4 2009/04/20 06:12:55 marcus Exp $

PORTNAME=	nautilus-sendto
PORTVERSION=	1.1.5
PORTREVISION=	1
CATEGORIES=	deskutils
MASTER_SITES=	GNOME

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Integration between nautilus, evolution, and pidgin

BUILD_DEPENDS=	evolution:${PORTSDIR}/mail/evolution \
    		empathy:${PORTSDIR}/net-im/empathy
RUN_DEPENDS=	evolution:${PORTSDIR}/mail/evolution \
    		empathy:${PORTSDIR}/net-im/empathy

MAN1=		nautilus-sendto.1
GCONF_SCHEMAS=	nst.schemas
USE_BZIP2=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_GNOME=	intlhack gnomeprefix gnometarget nautilus2 gnomehack
USE_GETTEXT=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

.include <bsd.port.pre.mk>

.if exists(${LOCALBASE}/bin/pidgin)
BUILD_DEPENDS+=	pidgin:${PORTSDIR}/net-im/pidgin
RUN_DEPENDS+=	pidgin:${PORTSDIR}/net-im/pidgin
PLIST_SUB+=	PIDGIN=""
.else
PLIST_SUB+=	PIDGIN="@comment "
.endif

.include <bsd.port.post.mk>
