# New ports collection makefile for:	k3bmonkeyaudioplugin
# Date created:				Wed Jan  4 02:53:56 CET 2006
# Whom:					Markus Brueffer <markus@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=	k3bmonkeyaudioplugin
PORTVERSION=	3.1
PORTREVISION=	3
CATEGORIES=	audio kde
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE_EXTENDED}
MASTER_SITE_SUBDIR=	k3b

MAINTAINER=	markus@FreeBSD.org
COMMENT=	K3b plugin for Monkey's Audio files

LIB_DEPENDS=	k3b:${PORTSDIR}/sysutils/k3b

USE_BZIP2=	yes
USE_KDELIBS_VER=3
USE_GMAKE=	yes
USE_AUTOTOOLS=	libtool:15
USE_LDCONFIG=	${PREFIX}/lib/kde3

post-patch:
	@${REINPLACE_CMD} -e 's|-O2||g'	${WRKSRC}/${CONFIGURE_SCRIPT}

.include <bsd.port.mk>
