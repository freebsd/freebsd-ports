# New ports collection makefile for:	regexxer
# Date created:				15 February 2003
# Whom:					Rui Lopes <rui@ruilopes.com>
#
# $FreeBSD$
#

PORTNAME=		regexxer
PORTVERSION=		0.9
PORTREVISION=	4
CATEGORIES=		devel textproc gnome
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=		bg1tpt@gmail.com
COMMENT=		An interactive tool for performing search and replace operations

LIB_DEPENDS=		gconfmm-2.6:${PORTSDIR}/devel/gconfmm26 \
			glademm-2.4:${PORTSDIR}/devel/libglademm24 \
			pcre.0:${PORTSDIR}/devel/pcre

USE_GETTEXT=		yes
GNU_CONFIGURE=		yes
USE_GMAKE=		yes
USE_GNOME=		gnomehack gnomeprefix gnometarget intltool intlhack
CONFIGURE_ENV=		CPPFLAGS="-I${LOCALBASE}/include" \
			LDFLAGS="-L${LOCALBASE}/lib"

GCONF_SCHEMAS=		regexxer.schemas
INSTALLS_ICONS=		regexxer.png

# This target is only meant to be used by the port maintainer.
x-generate-plist:
	(${PORTSDIR}/Tools/scripts/plist -d -m ${MTREE_FILE} ${PREFIX}|${GREP} regexxer) > temp-pkg-plist

.include <bsd.port.mk>
