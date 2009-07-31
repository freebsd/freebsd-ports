# New ports collection makefile for:    ja-scim-honoka
# Date created:		2 June 2006
# Whom:			Masashi CHIBA
#
# $FreeBSD$
#

PORTNAME=	scim-honoka
PORTVERSION=	0.9.1
PORTREVISION=	6
CATEGORIES=	japanese
MASTER_SITES=	http://nop.net-p.org/files/honoka/
DISTNAME=	honoka-${PORTVERSION}

MAINTAINER=	chiba.masashi@gmail.com
COMMENT=	SCIM IMEngine module using various Imput Methods

BUILD_DEPENDS=	scim:${PORTSDIR}/textproc/scim
RUN_DEPENDS:=	${BUILD_DEPENDS}

USE_LDCONFIG=	yes
USE_GETTEXT=	yes
USE_GNOME=	lthack gnomehack
USE_ICONV=	yes
USE_GMAKE=	yes
USE_AUTOTOOLS=	libtool:15

CONFIGURE_ENV=	PTHREAD_CFLAGS="${PTHREAD_CFLAGS}" \
		PTHREAD_LIBS="${PTHREAD_LIBS}" \
		CPPFLAGS="-I${LOCALBASE}/include -D__STDC_ISO_10646__" \
		LDFLAGS="-L${LOCALBASE}/lib"

post-install:
	@${ECHO_CMD}
	@${CAT} ${PKGMESSAGE}
	@${ECHO_CMD}

.include <bsd.port.mk>
