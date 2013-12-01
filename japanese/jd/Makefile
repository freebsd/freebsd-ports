# Created by: Takashi Kato <townwear@gmail.com>
# $FreeBSD$

PORTNAME=		jd
PORTVERSION=		2.8.6
CATEGORIES=		japanese www
MASTER_SITES=		SFJP
MASTER_SITE_SUBDIR=	jd4linux/58841
DISTNAME=	${PORTNAME}-${PORTVERSION}-130518
EXTRACT_SUFX=	.tgz

MAINTAINER=	townwear@gmail.com
COMMENT=	2ch browser

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libgnutls.so:${PORTSDIR}/security/gnutls \
		libgcrypt.so:${PORTSDIR}/security/libgcrypt

USES=		iconv
USE_AUTOTOOLS=	autoconf automake libtool
USE_GNOME=	gtk20 gtkmm24 libgnomeui

CONFIGURE_ARGS=	--with-sessionlib=gnomeui
LDFLAGS+=	-L${LOCALBASE}/lib ${ICONV_LIB}

OPTIONS_DEFINE=	ONIGURUMA PANGOLAYOUT
ONIGURUMA_DESC=	Use oniguruma regular expressions library
PANGOLAYOUT_DESC=	Use PANGOLayout instead of PangoGlyphString

ONIGURUMA_CONFIGURE_WITH=	oniguruma
ONIGURUMA_LIB_DEPENDS=		libonig.so:${PORTSDIR}/devel/oniguruma5

PANGOLAYOUT_CONFIGURE_WITH=	pangolayout

pre-configure:
	@cd ${WRKSRC} && ${AUTORECONF} -i

.include <bsd.port.mk>
