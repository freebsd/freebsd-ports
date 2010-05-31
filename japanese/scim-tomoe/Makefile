# New ports collection makefile for:	ja-scim-tomoe
# Date created:				18 Dec 2005
# Whom:					Hajimu UMEMOTO <ume@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	scim-tomoe
PORTVERSION=	0.6.0
PORTREVISION=	7
CATEGORIES=	japanese
MASTER_SITES=	SF/tomoe/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	ume@FreeBSD.org
COMMENT=	SCIM IMEngine module using Tomoe

BUILD_DEPENDS=	scim:${PORTSDIR}/textproc/scim
LIB_DEPENDS=	tomoe.1:${PORTSDIR}/japanese/tomoe \
		tomoe-gtk.1:${PORTSDIR}/japanese/libtomoe-gtk

USE_GNOME=	lthack intlhack
USE_GETTEXT=	yes
USE_ICONV=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes

CONFIGURE_ENV=	PTHREAD_CFLAGS="${PTHREAD_CFLAGS}" \
		PTHREAD_LIBS="${PTHREAD_LIBS}" \
		CPPFLAGS="-I${LOCALBASE}/include -D__STDC_ISO_10646__" \
		LDFLAGS="-L${LOCALBASE}/lib"

PLIST_FILES=	bin/scim-tomoe \
		lib/scim-1.0/1.4.0/Helper/tomoe.a \
		lib/scim-1.0/1.4.0/Helper/tomoe.la \
		lib/scim-1.0/1.4.0/Helper/tomoe.so \
		share/locale/ja/LC_MESSAGES/scim-tomoe.mo \
		share/scim/icons/scim-tomoe.png

post-install:
	@${CAT} ${PKGMESSAGE}
	@${ECHO}
	@${ECHO} To display this message again, type \`pkg_info -D ${PKGNAME}\'
	@${ECHO}

.include <bsd.port.mk>
