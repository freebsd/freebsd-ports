# New ports collection makefile for:	kexchange
# Date created:				17 October 2003
# Whom:					Adam Weinberger <adamw@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	kexchange
PORTVERSION=	0.3.2
CATEGORIES=	finance kde
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	arved

MAINTAINER=	brueffer@phoenix-systems.de
COMMENT=	KDE currency converter

USE_KDELIBS_VER=	3
GNU_CONFIGURE=		yes
USE_REINPLACE=		yes

CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}

post-patch:
	@${REINPLACE_CMD} -e 's|-O2||g' ${WRKSRC}/${CONFIGURE_SCRIPT}

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/x11/kde3/Makefile.kde"
.include <bsd.port.post.mk>
