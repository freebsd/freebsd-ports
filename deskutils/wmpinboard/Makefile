# New ports collection makefile for:	wmpinboard
# Date created:			17 January 1999
# Whom:				Jim Mock <jim@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	wmpinboard
PORTVERSION=	1.0
CATEGORIES=	deskutils afterstep windowmaker
MASTER_SITES=	${MASTER_SITE_DEBIAN_POOL}
DISTNAME=	${PORTNAME}_${PORTVERSION}.orig

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Post-it notes for the WindowMaker dock or AfterStep Wharf

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}.orig

USE_XPM=	yes
USE_GETOPT_LONG=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
MAKE_ARGS=	ACLOCAL="${TRUE}" AUTOCONF="${TRUE}" AUTOMAKE="${TRUE}" \
		AUTOHEADER="${TRUE}"

MAN1=		wmpinboard.1

PLIST_FILES=	bin/wmpinboard

.include <bsd.port.mk>
