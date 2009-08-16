# New ports collection makefile for:	jd
# Date created:     			10 May 2009
# Whom:             			Takashi Kato <townwear@gmail.com>
#
# $FreeBSD$
#

PORTNAME=		jd
PORTVERSION=		2.4.1
PORTREVISION=		1
CATEGORIES=		japanese www
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE_JP}
MASTER_SITE_SUBDIR=	jd4linux/41293
DISTNAME=	${PORTNAME}-${PORTVERSION}-090712
EXTRACT_SUFX=	.tgz

MAINTAINER=	townwear@gmail.com
COMMENT=	A 2ch browser

MAKE_JOBS_SAFE=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_AUTOTOOLS=	autoconf:262 automake:110 libtool:22

LIB_DEPENDS+=	gnutls:${PORTSDIR}/security/gnutls \
		gtkmm:${PORTSDIR}/x11-toolkits/gtkmm24

.if defined(WITH_ONIGURUMA)
CONFIGURE_ARGS+=	--with-oniguruma
LIB_DEPENDS+=		onig:${PORTSDIR}/devel/oniguruma5
.endif

.if defined(WITH_GNOMEUI)
CONFIGURE_ARGS+=	--with-sessionlib=gnomeui
USE_GNOME+=		libgnomeui
.endif

.if defined(WITH_PANGOLAYOUT)
CONFIGURE_ARGS+=	--with-pangolayout
.endif

pre-configure:
	@cd ${WRKSRC} && ${AUTORECONF} -i

.include <bsd.port.mk>
