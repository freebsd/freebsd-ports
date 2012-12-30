# New ports collection makefile for:	k3bmonkeyaudioplugin
# Date created:				Wed Jan  4 02:53:56 CET 2006
# Whom:					Markus Brueffer <markus@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=	k3bmonkeyaudioplugin
PORTVERSION=	3.1
PORTREVISION=	7
CATEGORIES=	audio kde
MASTER_SITES=	SF/k3b/${PORTNAME}/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	K3b plugin for Monkey's Audio files

LIB_DEPENDS=	k3b:${PORTSDIR}/sysutils/k3b

DEPRECATED=	Depends on QT3; unmaintained
EXPIRATION_DATE=	2013-07-01

USE_BZIP2=	yes
USE_KDELIBS_VER=3
USE_GMAKE=	yes
USE_AUTOTOOLS=	libtool
USE_LDCONFIG=	${PREFIX}/lib/kde3

post-patch:
	@${REINPLACE_CMD} -e 's|-O2||g'	${WRKSRC}/${CONFIGURE_SCRIPT}

.include <bsd.port.mk>
