# New ports collection makefile for:	gimageview
# Date Created:				5 Feb 2002
# Whom:		TATEISHI Katsuyuki <katsu@iec.hiroshima-u.ac.jp>
#
# $FreeBSD$
#

PORTNAME=	gimageview
PORTVERSION=	0.1.98
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	gtkmmviewer

MAINTAINER=	katsu@iec.hiroshima-u.ac.jp

USE_X_PREFIX=	yes
USE_GMAKE=	yes
USE_IMLIB=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib"

post-patch:
	@${PERL} -pi -e 's/DATADIRNAME=lib/DATADIRNAME=share/g' \
		${WRKSRC}/configure

.include <bsd.port.mk>
