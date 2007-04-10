# New ports collection makefile for:	orange
# Date Created:				January 2005
# Whom:					Sam Lawrance <boris@brooknet.com.au>
#
# $FreeBSD$
#

PORTNAME=	orange
PORTVERSION=	0.3
PORTREVISION=	1
CATEGORIES=	archivers
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	synce

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Extract Microsoft Cabinet files from self-extracting installers

LIB_DEPENDS=	synce.0:${PORTSDIR}/palm/synce-libsynce \
		rapi.2:${PORTSDIR}/palm/synce-librapi2 \
		dynamite.0:${PORTSDIR}/archivers/dynamite \
		unshield.0:${PORTSDIR}/archivers/unshield

USE_AUTOTOOLS=	libtool:15
GNU_CONFIGURE=	yes
USE_GNOME=	gnometarget
CONFIGURE_ARGS=	--with-libsynce=${LOCALBASE}
USE_ICONV=	yes
USE_LDCONFIG=	yes

.include <bsd.port.mk>
