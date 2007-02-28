# ex:ts=8
# Ports collection makefile for:	g-wrap
# Date created:		Jun 29, 2000
# Whom:			Matthew Condell (mcondell@alum.mit.edu)
#
# $FreeBSD$
#    $MCom: ports/devel/g-wrap/Makefile,v 1.6 2006/12/24 18:45:08 ahze Exp $

PORTNAME=	g-wrap
PORTVERSION=	1.9.6
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	devel scheme
MASTER_SITES=	SAVANNAH

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	A tool for exporting C libraries into Scheme interpreters

BUILD_DEPENDS=	guile>=1.6.8_2:${PORTSDIR}/lang/guile \
		slib-guile>0:${PORTSDIR}/lang/slib-guile
RUN_DEPENDS=	guile>=1.6.8_2:${PORTSDIR}/lang/guile \
		slib-guile>0:${PORTSDIR}/lang/slib-guile

INFO=		g-wrap

USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_GNOME=	glib20 gnomehack

post-patch:
	@${REINPLACE_CMD} -e 's|"glib"|"glib-2.0"|' \
		${WRKSRC}/configure

pre-install:
	@${REINPLACE_CMD} -e 's|libffi||' ${WRKSRC}/${MAKEFILE}

post-install:
	${MKDIR} ${PREFIX}/include/g-wrap/ffi
.for f in ffi.h ffitarget.h
	${INSTALL_DATA} ${WRKSRC}/libffi/include/${f} ${PREFIX}/include/g-wrap/ffi
.endfor

.include <bsd.port.mk>
