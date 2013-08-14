# Created by: Takashi Kato <townwear@gmail.com>
# $FreeBSD$

PORTNAME=		jd
PORTVERSION=		2.8.5
PORTREVISION=	2
CATEGORIES=		japanese www
MASTER_SITES=		SFJP
MASTER_SITE_SUBDIR=	jd4linux/56721
DISTNAME=	${PORTNAME}-${PORTVERSION}-120826
EXTRACT_SUFX=	.tgz

MAINTAINER=	townwear@gmail.com
COMMENT=	2ch browser

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	gnutls:${PORTSDIR}/security/gnutls \
		gcrypt:${PORTSDIR}/security/libgcrypt \
		gtkmm:${PORTSDIR}/x11-toolkits/gtkmm24

USE_GMAKE=	yes
USE_AUTOTOOLS=	autoconf automake libtool
USE_GNOME=	gtk20 libgnomeui
GNU_CONFIGURE=	yes

CONFIGURE_ARGS+=	--with-sessionlib=gnomeui

OPTIONS_DEFINE=	ONIGURUMA PANGOLAYOUT
ONIGURUMA_DESC=	Use oniguruma regular expressions library
PANGOLAYOUT_DESC=	Use PANGOLayout instead of PangoGlyphString

.include <bsd.port.options.mk>
.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MONIGURUMA}
CONFIGURE_ARGS+=	--with-oniguruma
LIB_DEPENDS+=		onig:${PORTSDIR}/devel/oniguruma5
.endif

.if ${PORT_OPTIONS:MPANGOLAYOUT}
CONFIGURE_ARGS+=	--with-pangolayout
.endif

pre-configure:
	@cd ${WRKSRC} && ${AUTORECONF} -i

.include <bsd.port.post.mk>
