# New ports collection makefile for:	gqview
# Version required:			0.6.1
# Date Created:				27 Oct 1998
# Whom:					Vanilla Pooh Shu <vanilla@FreeBSD.org>
#
# $FreeBSD$
#

DISTNAME=	gqview-0.7.0.src
PKGNAME=	gqview-0.7.0
CATEGORIES=	graphics
MASTER_SITES=	http://gqview.netpedia.net/ \
		http://www.geocities.com/SiliconValley/Haven/5235/
EXTRACT_SUFX=	.tgz

MAINTAINER=	nacai@iname.com

LIB_DEPENDS=	gtk12.2:${PORTSDIR}/x11-toolkits/gtk12 \
		Imlib.5:${PORTSDIR}/graphics/imlib

GTK_CONFIG?=	${X11BASE}/bin/gtk12-config

USE_X_PREFIX=	yes

WRKSRC=		${WRKDIR}/${PKGNAME}
ALL_TARGET=	gqview
CONFIGURE_ENV=	GTK_CONFIG="${GTK_CONFIG}"

pre-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/gqview
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/gqview/README
.endif

.include <bsd.port.mk>
