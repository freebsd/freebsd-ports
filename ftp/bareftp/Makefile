# Ports collection makefile for:  bareftp
# Date created:			Sat June 20, 2009
# Whom:				Chris Petrik (chris@officialunix.com)
#
# $FreeBSD$
#

PORTNAME=	bareftp
PORTVERSION=	0.3.2
CATEGORIES=	ftp
MASTER_SITES=	http://www.bareftp.org/release/ \
		http://www.predatorlabs.net/dl/

MAINTAINER=	rfarmer@predatorlabs.net
COMMENT=	Ftp client made in C sharp

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--datarootdir="${PREFIX}/share" --libdir="${PREFIX}/lib" \
		--localedir="${PREFIX}/share/locale" --includedir="${LOCALBASE}/include" \
		--without-gnomekeyring

INSTALLS_ICONS=	yes
USE_GETTEXT=	yes
USE_GNOME=	gtksharp20 gnomesharp20
USE_GMAKE=	yes

USE_LDCONFIG=	yes

MAKE_JOBS_SAFE=	yes

MAN1=		bareftp.1

# TODO
# Ugly way but configure ignore "--localedir=" fu* ;/
pre-build:
	@${REINPLACE_CMD} -e 's|$$(prefix)/$$(DATADIRNAME)|${PREFIX}/share|g' \
		${WRKSRC}/po/Makefile

.include <bsd.port.mk>
