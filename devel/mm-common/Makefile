# Created by: Koop Mast<kwm@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/devel/mm-common/Makefile,v 1.11 2010/05/03 00:54:20 avl Exp $

PORTNAME=	mm-common
PORTVERSION=	0.9.2
PORTREVISION=	2
CATEGORIES=	devel gnome
MASTER_SITES=	GNOME

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Common build infrastructure for the GNOME C++ binding libraries

LIB_DEPENDS=	curl:${PORTSDIR}/ftp/curl

USES=	pathfix
USE_BZIP2=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes

MAN1=		mm-common-prepare.1

NO_STAGE=	yes
.include <bsd.port.mk>
