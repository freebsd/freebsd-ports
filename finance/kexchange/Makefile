# New ports collection makefile for:	kexchange
# Date created:				17 October 2003
# Whom:					Adam Weinberger <adamw@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	kexchange
PORTVERSION=	1.0
PORTREVISION=	1
CATEGORIES=	finance kde
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	brueffer@phoenix-systems.de
COMMENT=	KDE currency converter

USE_KDELIBS_VER=	3
GNU_CONFIGURE=		yes
USE_REINPLACE=		yes

post-patch:
	@${REINPLACE_CMD} -e 's|-O2||g' ${WRKSRC}/${CONFIGURE_SCRIPT}

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/x11/kde3/Makefile.kde"
.include <bsd.port.post.mk>
