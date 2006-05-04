# New ports collection makefile for:	Planner
# Date created:				15 July 2001
# Whom:					Dmitry Sivachenko <demon@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/deskutils/planner/Makefile,v 1.1 2005/10/08 19:33:55 marcus Exp $
#

PORTNAME=	planner
PORTVERSION=	0.13
PORTREVISION=	3
CATEGORIES=	deskutils gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/${PORTNAME}/0.13
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Project management application for Gnome 2

USE_BZIP2=	yes
USE_X_PREFIX=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomeprefix gnomehack intlhack libgnomeui libgnomeprintui \
		libgsf
WANT_GNOME=	yes
INSTALLS_OMF=	yes
INSTALLS_ICONS=	yes
INSTALLS_SHLIB=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-static \
		--disable-python \
		--disable-dotnet
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

GCONF_SCHEMAS=	planner.schemas

.include <bsd.port.pre.mk>

.if ${HAVE_GNOME:Mlibgda2}!=""
USE_GNOME+=	libgda2
CONFIGURE_ARGS+=--enable-database=yes
PLIST_SUB+=	GDA=""
.else
PLIST_SUB+=	GDA="@comment "
.endif

post-patch:
	@${FIND} ${WRKSRC} -name "Makefile.in" | ${XARGS} ${REINPLACE_CMD} -e \
		's|[(]datadir[)]/doc|(prefix)/share/doc|g'

.include <bsd.port.post.mk>
