# New ports collection makefile for:	devhelp
# Date created:				29 May 2003
# Whom:					Adam Weinberger <adamw@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	devhelp
PORTVERSION=	0.19
CATEGORIES=	devel gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/${PORTNAME}/${PORTVERSION:C,^([[:digit:]]+\.[[:digit:]]+).*,\1,}
DIST_SUBDIR=	gnome2

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Developer help browser for GNOME 2

BUILD_DEPENDS=	${LOCALBASE}/lib/${MOZILLA}/components/libwidget_gtk2.so:${PORTSDIR}/www/${MOZILLA}
RUN_DEPENDS=	${LOCALBASE}/lib/${MOZILLA}/components/libwidget_gtk2.so:${PORTSDIR}/www/${MOZILLA}

MOZILLA=	firefox

.if !defined(WITH_MOZILLA)
MOZILLA=	firefox
.else
.if ${WITH_MOZILLA} == "xulrunner"
MOZILLA=	xulrunner
.elif ${WITH_MOZILLA} == "seamonkey"
MOZILLA=	seamonkey
.endif
.endif

USE_BZIP2=	yes
USE_XLIB=	yes
USE_GETTEXT=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomehack intlhack gnomeprefix libgnomeui libwnck
USE_AUTOTOOLS=	libtool:15
GNU_CONFIGURE=	yes
INSTALLS_ICONS=	yes
USE_LDCONFIG=	${LOCALBASE}/lib/${MOZILLA}
GCONF_SCHEMAS=	devhelp.schemas
CONFIGURE_ENV=	CPPFLAGS="${PTHREAD_CFLAGS} -I${LOCALBASE}/include" \
		LDFLAGS="${PTHREAD_LIBS} -L${LOCALBASE}/lib"
CONFIGURE_ARGS=	--with-gecko=${MOZILLA}

OPTIONS=		GEDIT "Enable GEdit plug-in support" off

.include <bsd.port.pre.mk>

.if defined(WITH_GEDIT)
BUILD_DEPENDS+=	gedit:${PORTSDIR}/editors/gedit
RUN_DEPENDS+=	gedit:${PORTSDIR}/editors/gedit
PLIST_SUB+=	GEDIT=""
.else
PLIST_SUB+=	GEDIT="@comment "
.endif

# This target is only meant to be used by the port maintainer.
x-generate-plist:
	(${PORTSDIR}/Tools/scripts/plist -d -m ${MTREE_FILE} ${PREFIX}|${SED} -E 's,.*share/nls/.+$$,,g;s,^@dirrm share/((gnome/[^d]|pixmaps|application|locale).*|gnome$$),,;s,^@dirrm etc/gconf.*,,;s,^etc/gconf/gconf.*,,'|${TR} -s '\n') > temp-pkg-plist

post-patch:
.if defined(WITHOUT_GEDIT)
	@${REINPLACE_CMD} -e 's|gedit-plugin||' \
		${WRKSRC}/misc/Makefile.in
.endif

pre-everything::
	@${ECHO_MSG} ""
	@${ECHO_MSG} " By default the port uses www/firefox for html rendering, but you can"
	@${ECHO_MSG} " change this by defining WITH_MOZILLA to one of the following values:"
	@${ECHO_MSG}
	@${ECHO_MSG} "  xulrunner seamonkey      "
	@${ECHO_MSG} ""

.include <bsd.port.post.mk>
