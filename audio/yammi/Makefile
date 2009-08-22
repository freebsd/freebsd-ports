# New ports collection makefile for:	yammi
# Date created:				27 September 2003
# Whom:					Arjan van Leeuwen <avleeuwen@piwebs.com>
#
# $FreeBSD$
#

PORTNAME=	yammi
PORTVERSION=	1.2.3
PORTREVISION=	7
CATEGORIES=	audio
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A QT-based music manager with fuzzy search

LIB_DEPENDS=	vorbis.4:${PORTSDIR}/audio/libvorbis \
		tag.6:${PORTSDIR}/audio/taglib

OPTIONS=	XMMS "XMMS backend support" off

USE_KDELIBS_VER=	3
USE_GMAKE=	yes
USE_AUTOTOOLS=	autoconf:262:env automake:19:env libtool:22
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-gstreamer

.include <bsd.port.pre.mk>

.if defined(WITH_XMMS)
CONFIGURE_ARGS+=--enable-xmms
BUILD_DEPENDS+=	xmms-config:${PORTSDIR}/multimedia/xmms
LIB_DEPENDS+=	xmms.4:${PORTSDIR}/multimedia/xmms
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

.include <bsd.port.post.mk>
