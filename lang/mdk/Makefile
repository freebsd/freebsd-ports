# ex:ts=8
# New ports collection makefile for:  mdk
# Date created:			Apr 1, 2001
# Whom:				Ying-Chieh Liao <ijliao@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	mdk
PORTVERSION=	1.0.1
PORTREVISION=	1
CATEGORIES=	lang gnome
MASTER_SITES=	${MASTER_SITE_GNU} \
		${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	MIX Development Kit offers an emulation of MIX and MIXAL

LIB_DEPENDS=	iconv.3:${PORTSDIR}/converters/libiconv \
		intl.5:${PORTSDIR}/devel/gettext-old \
		guile.15:${PORTSDIR}/lang/guile

USE_REINPLACE=	yes
USE_GETOPT_LONG=	yes
USE_X_PREFIX=	yes
USE_GNOME=	glib12 gtk12 libglade gnomehack gnomehier gnomeprefix
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib" \
		MAKEINFO="makeinfo --no-split"

.include <bsd.port.pre.mk>

post-extract:
	@${RM} -f ${WRKSRC}/doc/*.info*

post-patch:
.if ${OSVERSION} < 500028
	@${REINPLACE_CMD} 's/#include <stdint.h>//g' \
		${WRKSRC}/mixlib/mix_scanner.c
.endif

.include <bsd.port.post.mk>
