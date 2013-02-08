# New ports collection makefile for:	jd
# Date created:     			10 May 2009
# Whom:             			Takashi Kato <townwear@gmail.com>
#
# $FreeBSD$
#

PORTNAME=		jd
PORTVERSION=		2.8.5
PORTREVISION=		1
CATEGORIES=		japanese www
MASTER_SITES=		SFJP
MASTER_SITE_SUBDIR=	jd4linux/56721
DISTNAME=	${PORTNAME}-${PORTVERSION}-120826
EXTRACT_SUFX=	.tgz

MAINTAINER=	townwear@gmail.com
COMMENT=	A 2ch browser

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	gnutls:${PORTSDIR}/security/gnutls \
		gcrypt:${PORTSDIR}/security/libgcrypt \
		gtkmm:${PORTSDIR}/x11-toolkits/gtkmm24

MAKE_JOBS_SAFE=	yes
USE_GMAKE=	yes
USE_AUTOTOOLS=	autoconf automake libtool
USE_GNOME=	gtk20 libgnomeui
GNU_CONFIGURE=	yes

CONFIGURE_ARGS+=	--with-sessionlib=gnomeui

OPTIONS=	ONIGURUMA "Build with oniguruma regular expressions lib" off \
		PANGOLAYOUT "Use PANGOLayout instead of PangoGlyphString" off

.include <bsd.port.pre.mk>

.if defined(WITH_ONIGURUMA)
CONFIGURE_ARGS+=	--with-oniguruma
LIB_DEPENDS+=		onig:${PORTSDIR}/devel/oniguruma5
.endif

.if defined(WITH_PANGOLAYOUT)
CONFIGURE_ARGS+=	--with-pangolayout
.endif

pre-configure:
	@cd ${WRKSRC} && ${AUTORECONF} -i

.include <bsd.port.post.mk>
