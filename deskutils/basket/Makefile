# New ports collection makefile for:	basket
# Date created:			Mon Sep  8 19:32:42 CEST 2003
# Whom:				Markus Brueffer <brueffer@phoenix-systems.de>
#
# $FreeBSD$

PORTNAME=	basket
PORTVERSION=	1.0.3.1
PORTREVISION=	2
CATEGORIES=	deskutils kde
MASTER_SITES=	http://basket.kde.org/downloads/

MAINTAINER=	decept0@gmail.com
COMMENT=	Desktop organization tool

USE_KDELIBS_VER=3
USE_GMAKE=	yes
USE_AUTOTOOLS=	libtool:22
USE_LDCONFIG=	yes

OPTIONS=	KONTACT	"Kontact plugin" on \
		GPGME "GPG support (experimental)" off

.include <bsd.port.pre.mk>

.if defined(WITH_KONTACT)
LIB_DEPENDS+=	kontact.1:${PORTSDIR}/deskutils/kdepim3
PLIST_SUB=	KONTACT=""
.else
PLIST_SUB=	KONTACT="@comment "
CONFIGURE_ENV+=	DO_NOT_COMPILE="kontact_plugin"
.endif

.if defined(WITH_GPGME)
RUN_DEPENDS+=	pinentry-qt:${PORTSDIR}/security/pinentry-qt
LIB_DEPENDS+=	gpgme.18:${PORTSDIR}/security/gpgme \
		gpg-error.0:${PORTSDIR}/security/libgpg-error
.else
CONFIGURE_ARGS+=	--with-encryption=no
.endif

post-patch:
	@${REINPLACE_CMD} -e 's/-O2//g' ${WRKSRC}/${CONFIGURE_SCRIPT}

.include <bsd.port.post.mk>
