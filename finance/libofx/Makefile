# New ports collection makefile for:   libofx
# Date created:        February 16 2003
# Whom:                Glenn Johnson <glennpj@charter.net>
#
# $FreeBSD$
#

PORTNAME=	libofx
PORTVERSION=	0.6.4
CATEGORIES=	finance
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	libofx

MAINTAINER=	ports@FreeBSD.org
COMMENT=	OpenSource implementation of the OFX (Open Financial eXchange)

LIB_DEPENDS=	osp.3:${PORTSDIR}/textproc/opensp

INSTALLS_SHLIB=	yes
USE_LIBTOOL=	yes
CONFIGURE_ARGS=	--with-opensp-includes=${LOCALBASE}/include/OpenSP \
		--with-opensp-libs=${LOCALBASE}/lib

.include <bsd.port.mk>
