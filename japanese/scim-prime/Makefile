# Created by: Norikatsu Shigemura <nork@FreeBSD.org>
# $FreeBSD$

PORTNAME=	scim-prime
PORTVERSION=	0.3.0
PORTREVISION=	11
CATEGORIES=	japanese
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE_JP}
MASTER_SITE_SUBDIR=	scim-imengine/17192

MAINTAINER=	ports@FreeBSD.org
COMMENT=	SCIM IMEngine module using PRIME

BUILD_DEPENDS=	scim:${PORTSDIR}/textproc/scim \
		prime:${PORTSDIR}/japanese/prime
RUN_DEPENDS:=	${BUILD_DEPENDS}

USE_GNOME=	lthack
USES=		gmake iconv pkgconfig
GNU_CONFIGURE=	yes

CPPFLAGS+=	-I${LOCALBASE}/include -D__STDC_ISO_10646__
LDFLAGS+=	-L${LOCALBASE}/lib

NO_STAGE=	yes
post-install:
	@${CAT} ${PKGMESSAGE}
	@${ECHO}
	@${ECHO} To display this message again, type \`pkg_info -D ${PKGNAME}\'
	@${ECHO}

.include <bsd.port.mk>
