# New ports collection makefile for:	devhelp
# Date created:				29 May 2003
# Whom:					Adam Weinberger <adamw@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	devhelp
PORTVERSION=	0.9.1
CATEGORIES?=	devel gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/${PORTNAME}/${PORTVERSION:C,^([[:digit:]]+\.[[:digit:]]+).*,\1,}
DIST_SUBDIR=	gnome2

MAINTAINER=	rui@ruilopes.com
COMMENT=	Developer help browser for GNOME 2

BUILD_DEPENDS=	${X11BASE}/lib/mozilla/libgtkembedmoz.so:${PORTSDIR}/www/mozilla
RUN_DEPENDS=	${BUILD_DEPENDS}

USE_BZIP2=	yes
USE_X_PREFIX=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomehack intlhack gnomeprefix libgtkhtml libgnomeui
GNU_CONFIGURE=	yes
INSTALLS_SHLIB=	yes
CONFIGURE_ENV=	CPPFLAGS="${PTHREAD_CFLAGS} -I${LOCALBASE}/include" \
		LIBS="${PTHREAD_LIBS} -L${LOCALBASE}/lib"

# This target is only meant to be used by the port maintainer.
x-generate-plist:
	(${PORTSDIR}/Tools/scripts/plist -d -m ${MTREE_FILE} ${PREFIX}|${SED} -E 's,.*share/nls/.+$$,,g;s,^@dirrm share/((gnome/[^d]|pixmaps|application|locale).*|gnome$$),,;s,^@dirrm etc/gconf.*,,;s,^etc/gconf/gconf.*,,'|${TR} -s '\n') > temp-pkg-plist

.include <bsd.port.mk>
