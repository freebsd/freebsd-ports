# New ports collection makefile for:	evolution-data-server
# Date created:				09 December 2003
# Whom:					Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	evolution-data-server
PORTVERSION=	1.0.3
CATEGORIES=	databases gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/${PORTNAME}/1.0
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	The data backends for the Evolution integrated mail/PIM suite

LIB_DEPENDS=	soup-2.2.7:${PORTSDIR}/devel/libsoup

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_BISON=	yes
USE_X_PREFIX=	yes
USE_GNOME=	gnomeprefix gnomehack intlhack gnometarget libgnome
USE_REINPLACE=	yes
USE_LIBTOOL_VER=15
INSTALLS_SHLIB=	yes
CONFIGURE_ARGS=	--enable-static
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

PLIST_SUB=	VERSION="1.0" EVO_VERSION="1.0"

.if !defined(WITHOUT_LDAP)
USE_OPENLDAP=	yes
CONFIGURE_ARGS+=--with-openldap=yes
.else
CONFIGURE_ARGS+=--with-openldap=no
.endif

pre-everything::
	@${ECHO_MSG} ""
	@${ECHO_MSG} "evolution-data-server has the following configurable option(s):"
	@${ECHO_MSG} "	WITHOUT_LDAP	Disable LDAP support"
	@${ECHO_MSG} ""

.include <bsd.port.mk>
