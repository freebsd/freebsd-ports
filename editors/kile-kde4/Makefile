# New ports collection makefile for: kile
# Date created:		21 Jun 2002
# Whom:			Stefan Jahn <stefan.jahn@nemesis-sektor.de>
#
# $FreeBSD$
#

PORTNAME=	kile
PORTVERSION=	1.6
PORTREVISION=	1
CATEGORIES=	editors kde
MASTER_SITES=	${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=stable/apps/KDE3.x/office

MAINTAINER=	stefan.jahn@nemesis-sektor.de
COMMENT=	A LaTeX source editor for KDE

RUN_DEPENDS=	latex:${PORTSDIR}/print/teTeX

USE_KDELIBS_VER=3
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_REINPLACE=	yes

post-extract:
	@${TOUCH} ${WRKSRC}/config.h.in

post-patch:
	@${REINPLACE_CMD} -e 's|-O2||g' ${WRKSRC}/configure

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/x11/kde3/Makefile.kde"
.include <bsd.port.post.mk>
