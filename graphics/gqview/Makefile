# New ports collection makefile for:	gqview
# Version required:			0.6.0
# Date Created:				27 Oct 1998
# Whom:					Vanilla Pooh Shu <vanilla@FreeBSD.ORG>
#
# $Id: Makefile,v 1.9 1999/01/17 18:17:51 nectar Exp $
#

DISTNAME=	gqview-0.6.0.src
PKGNAME=	gqview-0.6.0
CATEGORIES=	graphics
MASTER_SITES=	http://www.geocities.com/SiliconValley/Haven/5235/
EXTRACT_SUFX=	.tgz

MAINTAINER=	nacai@iname.com

LIB_DEPENDS=	gtk12.1:${PORTSDIR}/x11-toolkits/gtk12 \
		Imlib.2:${PORTSDIR}/graphics/imlib

USE_X_PREFIX=	yes

WRKSRC=		${WRKDIR}/${PKGNAME}
ALL_TARGET=	gqview
CONFIGURE_ENV=	GTK_CONFIG="${X11BASE}/bin/gtk12-config"


pre-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/gqview
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/gqview/README
.endif

.include <bsd.port.mk>
