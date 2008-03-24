# New ports collection makefile for:	gconf2
# Date created:				28th June 2000
# Whom:					Ade Lovett <ade@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/devel/gconf2/Makefile,v 1.96 2008/03/10 16:25:56 ahze Exp $
#

PORTNAME=	gconf2
PORTVERSION=	2.22.0
PORTREVISION?=	0
CATEGORIES=	devel gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/GConf/${PORTVERSION:C/^([0-9]+\.[0-9]+).*/\1/}
DISTNAME=	GConf-${PORTVERSION}
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	A configuration database system for GNOME

USE_BZIP2=	yes

.if !defined(REFERENCE_PORT)

USE_GMAKE=	yes
USE_GETTEXT=	yes
USE_GNOME=	gnomehier gnomehack orbit2 gtk20 libxml2 ltverhack \
		referencehack intlhack
USE_LDCONFIG=	yes
USE_AUTOTOOLS=	libtool:15
CONFIGURE_ARGS=	--with-html-dir=${PREFIX}/share/doc \
		--disable-gtk-doc
#		--enable-gconf-source=${PREFIX}/etc/gconf/schemas \

CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
MAN1=		gconftool-2.1

.include <bsd.port.pre.mk>

.if defined(WITH_LDAP) || exists(${LOCALBASE}/include/ldap.h)
USE_OPENLDAP=	yes

PLIST_SUB+=	LDAP=""
.else
PLIST_SUB+=	LDAP="@comment "
.endif

pre-everything::
.if !defined(WITH_LDAP)
	@${ECHO_MSG}
	@${ECHO_MSG} "You can enable ldap support by defining"
	@${ECHO_MSG} "WITH_LDAP"
	@${ECHO_MSG}
.endif

.include <bsd.port.post.mk>

.endif
