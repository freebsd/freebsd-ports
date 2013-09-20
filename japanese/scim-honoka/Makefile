# Created by: Masashi CHIBA
# $FreeBSD$

PORTNAME=	scim-honoka
PORTVERSION=	0.9.1
PORTREVISION=	10
CATEGORIES=	japanese
MASTER_SITES=	http://nop.net-p.org/files/honoka/
DISTNAME=	honoka-${PORTVERSION}

MAINTAINER=	chiba.masashi@gmail.com
COMMENT=	SCIM IMEngine module using various input methods

BUILD_DEPENDS=	scim:${PORTSDIR}/textproc/scim
RUN_DEPENDS:=	${BUILD_DEPENDS}

USE_LDCONFIG=	yes
USES=		gettext iconv pathfix gmake pkgconfig
USE_GNOME=	lthack
USE_AUTOTOOLS=	libtool

CONFIGURE_ENV=	PTHREAD_CFLAGS="${PTHREAD_CFLAGS}" \
		PTHREAD_LIBS="${PTHREAD_LIBS}"

CPPFLAGS+=	-I${LOCALBASE}/include -D__STDC_ISO_10646__
LDFLAGS+=	-L${LOCALBASE}/lib

NO_STAGE=	yes
post-install:
	@${ECHO_CMD}
	@${CAT} ${PKGMESSAGE}
	@${ECHO_CMD}

.include <bsd.port.mk>
