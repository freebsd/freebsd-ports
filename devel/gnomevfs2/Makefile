# New ports collection makefile for:	gnomevfs2
# Date created:				28th June 2000
# Whom:					Ade Lovett <ade@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gnomevfs2
PORTVERSION=	2.4.2
CATEGORIES=	devel gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/gnome-vfs/2.4
DISTNAME=	gnome-vfs-${PORTVERSION}
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GNOME Virtual File System

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_X_PREFIX=	yes
USE_GNOME=	gnomeprefix gnomehack gnomehier gnomemimedata gconf2 libbonobo
USE_REINPLACE=	yes
USE_LIBTOOL=	yes
INSTALLS_SHLIB=	yes
CONFIGURE_ENV=	CPPFLAGS="${PTHREAD_CFLAGS} -I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib ${PTHREAD_LIBS} -lintl" \
		BSD_PTHREAD_LIBS=${PTHREAD_LIBS}

.if !defined(WITHOUT_KDE_MENUS)
EXTRA_PATCHES=	${FILESDIR}/modules_vfolder_applications-all-users.vfolder-info.in
.endif

.include <bsd.port.pre.mk>

.if exists(${LOCALBASE}/lib/libcdda_paranoia.a)
WITH_CDPARANOIA=	yes
.endif
.if exists(${LOCALBASE}/lib/libfam.a)
WITH_FAM=	yes
.endif

.if defined(WITH_CDPARANOIA)
LIB_DEPENDS+=	cdda_paranoia.0:${PORTSDIR}/audio/cdparanoia
PLIST_SUB+=	CDPARANOIA=""
.else
PLIST_SUB+=	CDPARANOIA="@comment "
.endif
.if defined(WITH_FAM)
LIB_DEPENDS+=	fam.0:${PORTSDIR}/devel/fam
.endif

post-patch:
	@${FIND} ${WRKSRC} -name "*info.in" | ${XARGS} ${REINPLACE_CMD} -e \
		's|\@datadir\@/gnome|\@datadir\@|g'
	@${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|g' \
		${WRKSRC}/libgnomevfs/Makefile.in \
		${WRKSRC}/modules/vfolder/applications-all-users.vfolder-info.in
	@${REINPLACE_CMD} -e "/^SUBDIRS =/s/test//" \
		${WRKSRC}/Makefile.in

.include <bsd.port.post.mk>
