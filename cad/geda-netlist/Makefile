# New ports collection makefile for:	gnetlist
# Date created:			4 April 2001
# Whom:				bruno schwander <bruno@tinkerbox.org>
#
# $FreeBSD$
#

PORTNAME=	netlist
PORTVERSION=	20060123
PORTREVISION=	1
CATEGORIES=	cad
MASTER_SITES=	ftp://ftp.geda.seul.org/pub/geda/devel/${PORTVERSION}/ \
		http://geda.seul.org/devel/${PORTVERSION}/ \
		http://www.tinkerbox.org/projects/files/gEDA/
PKGNAMEPREFIX=	geda-
DISTNAME=	${PKGNAMEPREFIX}g${PORTNAME}-${PORTVERSION}

MAINTAINER=	ssedov@mbsd.msk.ru
COMMENT=	The gEDA's netlister

LIB_DEPENDS=	geda.25:${PORTSDIR}/cad/libgeda
RUN_DEPENDS=	${LOCALBASE}/share/geda/sym:${PORTSDIR}/cad/geda-symbols

DATADIR=	${PREFIX}/share/geda
DOCSDIR=	${PREFIX}/share/doc/geda

GNU_CONFIGURE=	yes
USE_GNOME=	gtk20
CONFIGURE_ARGS=	--with-docdir=${DOCSDIR}
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

MAN1=		gnetlist.1

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
BROKEN=		does not compile on 4.x
.endif

.include <bsd.port.post.mk>
