# ex:ts=8
# Ports collection makefile for:	cbrpager
# Date created:			Oct 28, 2004
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	cbrpager
PORTVERSION=	0.9.22
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A viewer for cbr (comic book archive) files

LICENSE=	GPLv3

USE_GNOME=	libgnomeui
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
MAKE_JOBS_SAFE=	yes

DESKTOP_ENTRIES=	"cbrPager" "Comic book files viewer" "" \
			"cbrpager" "Application;Graphics;Viewer;" true

PLIST_FILES=	bin/cbrpager \
		share/locale/es/LC_MESSAGES/cbrpager.mo \
		share/locale/fr/LC_MESSAGES/cbrpager.mo

.include <bsd.port.mk>
