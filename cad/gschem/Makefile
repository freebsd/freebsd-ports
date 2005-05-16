# New ports collection makefile for:	geda
# Date created:			4 April 2001
# Whom:				bruno schwander <bruno@tinkerbox.org>
#
# $FreeBSD$
#

PORTNAME=	gschem
PORTVERSION=	20050313
CATEGORIES=	cad
MASTER_SITES=	ftp://ftp.geda.seul.org/pub/geda/devel/${PORTVERSION}/ \
		http://geda.seul.org/devel/${PORTVERSION}/ \
		http://www.tinkerbox.org/projects/files/gEDA/
DISTNAME=	geda-${PORTNAME}-${PORTVERSION}

MAINTAINER=	bruno@tinkerbox.org
COMMENT=	gEDA electronic schematic capture tools

RUN_DEPENDS=	${LOCALBASE}/share/gEDA/sym:${PORTSDIR}/cad/geda-symbols
LIB_DEPENDS=	geda.23:${PORTSDIR}/cad/libgeda

GNU_CONFIGURE=	yes
USE_GNOME=	gtk20
CONFIGURE_ARGS=	--enable-gdgeda
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

INFO=		gschemdoc
MAN1=		gschem.1

.include <bsd.port.mk>
