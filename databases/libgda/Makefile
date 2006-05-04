# New ports collection makefile for:	libgda
# Date created:				8th March 2001
# Whom:					Ade Lovett <ade@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	libgda
PORTVERSION=	0.2.96
PORTREVISION=	3
CATEGORIES=	databases gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/${PORTNAME}/0.2
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Provides uniform access to different kinds of data sources

LIB_DEPENDS=	gdbm.3:${PORTSDIR}/databases/gdbm

USE_BZIP2=	yes
USE_X_PREFIX=	yes
USE_GNOME=	gnomehack gnomeprefix gnomehier gconf bonobo
USE_GMAKE=	yes
INSTALLS_SHLIB=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-gtk-doc
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib -lintl -lgdbm"
CONFIGURE_TARGET=	--target=${MACHINE_ARCH}-unknown-freebsd${OSREL}
PLIST_SUB=	VERSION=${PORTVERSION}

post-patch:
	@${FIND} ${WRKSRC} -name "Makefile.in" | ${XARGS} ${REINPLACE_CMD} -e \
		's|share/idl|share/gnome/idl|g'

.include <bsd.port.mk>
