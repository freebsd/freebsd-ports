# ex:ts=8
# Ports collection makefile for:	cbrpager
# Date created:			Oct 28, 2004
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	cbrpager
PORTVERSION=	0.9.13
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A viewer for cbr (comic book archive) files

USE_GNOME=	gnometarget libgnomeui
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

PLIST_FILES=	bin/cbrpager share/locale/es/LC_MESSAGES/cbrpager.mo

.include <bsd.port.mk>
