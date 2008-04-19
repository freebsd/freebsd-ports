# New ports collection makefile for:	tkgate
# Date created:				28 May 1999
# Whom:					Jeffery Hansen <hansen@cmu.edu>
#
# $FreeBSD$
#

PORTNAME=	tkgate
PORTVERSION=	1.8.7
PORTREVISION=	3
CATEGORIES=	cad
MASTER_SITES=	ftp://gadoid.ices.cmu.edu/pub/tkgate/
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A Tcl/Tk based digital circuit editor and simulator

LIB_DEPENDS=	tk84.1:${PORTSDIR}/x11-toolkits/tk84
RUN_DEPENDS=	tclsh8.4:${PORTSDIR}/lang/tcl84
BUILD_DEPENDS=	xmkmf:${PORTSDIR}/devel/imake

HAS_CONFIGURE=	yes
USE_BISON=	build
USE_XORG=	x11

PLIST_SUB=	VERSION=${PORTVERSION}

post-patch:
	@${REINPLACE_CMD} -e 's,/usr/X11R6,${LOCALBASE},g' \
		${WRKSRC}/Imakefile ${WRKSRC}/config.h

.include <bsd.port.mk>
