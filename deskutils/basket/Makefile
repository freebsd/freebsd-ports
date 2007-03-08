# New ports collection makefile for:	basket
# Date created:			Mon Sep  8 19:32:42 CEST 2003
# Whom:				Markus Brueffer <brueffer@phoenix-systems.de>
#
# $FreeBSD$

PORTNAME=		basket
PORTVERSION=		1.0
PORTREVISION=		1
CATEGORIES=		deskutils kde
MASTER_SITES=		http://basket.kde.org/downloads/

MAINTAINER=		markus@FreeBSD.org
COMMENT=		Desktop organization tool

LIB_DEPENDS+=		gpgme.17:${PORTSDIR}/security/gpgme \
			gpg-error.0:${PORTSDIR}/security/libgpg-error

USE_KDELIBS_VER=	3
USE_GMAKE=		yes
USE_AUTOTOOLS=		libtool:15

OPTIONS=	KONTACT	"Kontact plugin" on

.if !defined(WITHOUT_KONTACT)
LIB_DEPENDS+=	kontact.1:${PORTSDIR}/deskutils/kdepim3
PLIST_SUB=	KONTACT=""
.else
PLIST_SUB=	KONTACT="@comment "
CONFIGURE_ENV+=	DO_NOT_COMPILE="kontact_plugin"
.endif

post-patch:
	@${REINPLACE_CMD} -e 's/-O2//g' ${WRKSRC}/${CONFIGURE_SCRIPT}

.include <bsd.port.mk>
