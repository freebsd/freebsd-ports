# Created by: Markus Brueffer <brueffer@phoenix-systems.de>
# $FreeBSD$

PORTNAME=	basket
PORTVERSION=	1.0.3.1
PORTREVISION=	7
CATEGORIES=	deskutils kde
MASTER_SITES=	http://basket.kde.org/downloads/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Desktop organization tool

USE_KDELIBS_VER=3
USE_GMAKE=	yes
USE_AUTOTOOLS=	libtool
USE_LDCONFIG=	yes

OPTIONS_DEFINE=	KONTACT GPGME
OPTIONS_DEFAULT=	KONTACT GPGME
KONTACT_DESC=	Kontact plugin
GPGME_DESC=	GPG support (experimental)

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MKONTACT}
LIB_DEPENDS+=	kontact.1:${PORTSDIR}/deskutils/kdepim3
PLIST_SUB=	KONTACT=""
.else
PLIST_SUB=	KONTACT="@comment "
CONFIGURE_ENV+=	DO_NOT_COMPILE="kontact_plugin"
.endif

.if ${PORT_OPTIONS:MGPGME}
RUN_DEPENDS+=	pinentry-qt:${PORTSDIR}/security/pinentry-qt
LIB_DEPENDS+=	gpgme.19:${PORTSDIR}/security/gpgme \
		gpg-error.0:${PORTSDIR}/security/libgpg-error
.else
CONFIGURE_ARGS+=	--with-encryption=no
.endif

post-patch:
	@${REINPLACE_CMD} -e 's/-O2//g' ${WRKSRC}/${CONFIGURE_SCRIPT}

.include <bsd.port.mk>
