# New ports collection makefile for:	kluje
# Date created:				27 July 2003
# Whom:                                 Jesse McConnell <jesse@gallup.com>
#
# $FreeBSD$
#

PORTNAME=	kluje
PORTVERSION=	0.7
PORTREVISION=	1
CATEGORIES=	deskutils kde
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A KDE application for submitting updates to livejournal.com

USE_KDELIBS_VER=	3
USE_GMAKE=		yes
GNU_CONFIGURE=		yes
USE_REINPLACE=		yes

post-patch:
	@${REINPLACE_CMD} -e 's|-O2||g' ${WRKSRC}/${CONFIGURE_SCRIPT}

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/x11/kde3/Makefile.kde"
.include <bsd.port.post.mk>
