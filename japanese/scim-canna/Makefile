# New ports collection makefile for:    ja-scim-canna
# Date created:				2005-04-03
# Whom:					Norikatsu Shigemura <nork@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	scim-canna
PORTVERSION=	1.0.0
PORTREVISION=	12
CATEGORIES=	japanese
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE_JP}
MASTER_SITE_SUBDIR=	scim-imengine/18849

MAINTAINER=	ports@FreeBSD.org
COMMENT=	SCIM IMEngine module using Canna

BUILD_DEPENDS=	scim:${PORTSDIR}/textproc/scim
LIB_DEPENDS+=	canna.1:${PORTSDIR}/japanese/canna-lib
RUN_DEPENDS:=	${BUILD_DEPENDS}

USE_AUTOTOOLS=	libtool
USE_GNOME=	lthack
USE_ICONV=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes

CPPFLAGS+=	-I${LOCALBASE}/include -D__STDC_ISO_10646__
LDFLAGS+=	-L${LOCALBASE}/lib

post-install:
	@${CAT} ${PKGMESSAGE}
	@${ECHO}
	@${ECHO} To display this message again, type \`pkg_info -D ${PKGNAME}\'
	@${ECHO}

.include <bsd.port.mk>
