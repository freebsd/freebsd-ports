# New ports collection makefile for:	geda
# Date created:			4 April 2001
# Whom:				bruno schwander <bruno@tinkerbox.org>
#
# $FreeBSD$
#

PORTNAME=	geda-utils
PORTVERSION=	20060123
CATEGORIES=	cad
MASTER_SITES=	ftp://ftp.geda.seul.org/pub/geda/devel/${PORTVERSION}/ \
		http://geda.seul.org/devel/${PORTVERSION}/ \
		http://www.tinkerbox.org/projects/files/gEDA/

MAINTAINER=	bruno@tinkerbox.org
COMMENT=	gEDA utilities

RUN_DEPENDS=	${LOCALBASE}/share/gEDA/sym:${PORTSDIR}/cad/geda-symbols
LIB_DEPENDS=	geda.25:${PORTSDIR}/cad/libgeda

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_GNOME=	gtk20
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

MAN1=		grenum.1

.include <bsd.port.mk>
