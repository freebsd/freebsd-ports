# New ports collection makefile for:	kdegames3
# Date created:				Sun 14 May 2000 02:47:57
# Whom:					Will Andrews <will@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	kdegames
PORTVERSION=	${KDE_VERSION}
CATEGORIES=	games kde
MASTER_SITES=	${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=	stable/${PORTVERSION}/src
DIST_SUBDIR=	KDE

MAINTAINER=	kde@FreeBSD.org

USE_KDELIBS_VER=3
USE_BZIP2=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes

.include "${.CURDIR}/../../x11/kde3/Makefile.kde"

post-patch:
	@${PERL} -pi -e 's@(defined\(__sgi\))$$@\1 || defined(__FreeBSD__)@' \
		${WRKSRC}/ksirtet/lib/wizard.cpp

.include <bsd.port.mk>
