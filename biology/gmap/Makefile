# Ports collection makefile for:   gmap
# Date created:        24 September 2006
# Whom:                Bob Zimmermann <rpz@cse.wustl.edu>
#
# $FreeBSD$
#

PORTNAME=	gmap
PORTVERSION=	2006.04.21
CATEGORIES=	biology
MASTER_SITES=	http://www.gene.com/share/gmap/src/
DISTNAME=	${PORTNAME}-${PORTVERSION:C|\.|-|g}

MAINTAINER=	rpz@cse.wustl.edu
COMMENT=	A Genomic Mapping and Alignment Program for mRNA and EST Sequences

FETCH_DEPENDS=	${LOCALBASE}/bin/wget:${PORTSDIR}/ftp/wget

FETCH_CMD=	${LOCALBASE}/bin/wget
FETCH_BEFORE_ARGS=	--no-check-certificate
DISABLE_SIZE=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500036
EXTRA_PATCHES+=	${PATCHDIR}/extra-*
.endif

.include <bsd.port.post.mk>
