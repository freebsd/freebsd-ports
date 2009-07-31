# New ports collection makefile for:    zh-scim-chinese
# Date created:		20 May 2004
# Whom:			Jie Gao	<gaoj@cpsc.ucalgary.ca>
#
# $FreeBSD$
#

PORTNAME=	scim-pinyin
PORTVERSION=	0.5.91
PORTREVISION=	6
CATEGORIES=	chinese
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=scim

MAINTAINER=	ports@FreeBSD.org
COMMENT=	SCIM Chinese Smart Pinyin input method

BUILD_DEPENDS=	scim:${PORTSDIR}/textproc/scim
RUN_DEPENDS=	${BUILD_DEPENDS}

USE_GNOME=	gnomehack lthack
USE_ICONV=	yes
USE_GMAKE=	yes
USE_AUTOTOOLS=	libtool:15

CONFIGURE_ENV=	PTHREAD_CFLAGS="${PTHREAD_CFLAGS}" \
		PTHREAD_LIBS="${PTHREAD_LIBS}" \
		CPPFLAGS="-I${LOCALBASE}/include -D__STDC_ISO_10646__" \
		LDFLAGS="-L${LOCALBASE}/lib -lintl"

.include <bsd.port.pre.mk>

PLIST_SUB=	SKIM="@comment "

pre-fetch:
.if exists(${LOCALBASE}/bin/skim)
	@${ECHO_MSG} "===>  Skim is detected, support enabled."
.else
	@${ECHO_MSG} "Define WITH_SKIM to enable skim support."
.endif

.if exists(${LOCALBASE}/bin/skim)
WITH_SKIM=	yes
.endif

.if !defined(WITH_SKIM)
CONFIGURE_ARGS+=--disable-skim-support
.else
BUILD_DEPENDS+=	skim:${PORTSDIR}/textproc/skim
CONFIGURE_ENV+=	PTHREAD_LIBS="${PTHREAD_LIBS}"
PLIST_SUB=	SKIM="" PREFIX="${PREFIX}"
.endif

post-install:
	@${CAT} ${PKGMESSAGE}
	@${ECHO}
	@${ECHO} To display this message again, type \`pkg_info -D ${PKGNAME}\'
	@${ECHO}

.include <bsd.port.post.mk>
