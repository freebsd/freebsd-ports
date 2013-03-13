# Created by: Arjan van Leeuwen <avleeuwen@piwebs.com>
# $FreeBSD$

PORTNAME=	yammi
PORTVERSION=	1.2.3
PORTREVISION=	14
CATEGORIES=	audio
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Qt-based music manager with fuzzy search feature

LIB_DEPENDS=	vorbis:${PORTSDIR}/audio/libvorbis \
		tag:${PORTSDIR}/audio/taglib

DEPRECATED=	Depends on Qt3; unmaintained
EXPIRATION_DATE=	2013-07-01

OPTIONS_DEFINE=	XMMS
XMMS_DESC=	XMMS backend support

USE_KDELIBS_VER=	3
USE_GMAKE=	yes
USE_AUTOTOOLS=	autoconf:env automake:env libtool
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-gstreamer

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MXMMS}
CONFIGURE_ARGS+=--enable-xmms
BUILD_DEPENDS+=	xmms-config:${PORTSDIR}/multimedia/xmms
LIB_DEPENDS+=	xmms:${PORTSDIR}/multimedia/xmms
.else
CONFIGURE_ARGS+=--disable-xmms
.endif

post-patch:
	@cd ${WRKSRC}/admin && ${REINPLACE_CMD} -e \
		's|="autoconf"|="${AUTOCONF:T}"|g ; \
		 s|="autoheader"|="${AUTOHEADER:T}"|g ; \
		 s|="autom4te"|="${AUTOM4TE:T}"|g ; \
		 s|="automake"|="${AUTOMAKE:T}"|g ; \
		 s|="aclocal"|="${ACLOCAL:T}"|g' detect-autoconf.sh

pre-configure:
	@cd ${WRKSRC}/admin && ${RM} -f ltmain.sh && ${CP} -f ${LTMAIN} .
	@cd ${WRKSRC} && ${GMAKE} -f admin/Makefile.common

.include <bsd.port.mk>
