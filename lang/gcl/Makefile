# New ports collection makefile for:    gcl
# Date created:         Feb  8 1995
# Whom:                 hsu
#
# $FreeBSD$
#

PORTNAME=	gcl
PORTVERSION=	2.3
CATEGORIES=	lang tk82
MASTER_SITES=	ftp://ftp.ma.utexas.edu/pub/gcl/
EXTRACT_SUFX=	.tgz

MAINTAINER=	jseger@FreeBSD.org

LIB_DEPENDS=	tk82.1:${PORTSDIR}/x11-toolkits/tk82

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 400011
BROKEN=		"GCL isn't compatible with the new signals."
.endif

MAKEFILE=	makefile

GNU_CONFIGURE=	yes

PLIST_SUB=	GCL_VER=2.3

pre-build:
	${RM} -rf ${WRKSRC}/info/gcl-si.info*

post-install:
	${INSTALL_DATA} ${WRKSRC}/info/gcl-si.info ${PREFIX}/info
	@install-info ${PREFIX}/info/gcl-si.info ${PREFIX}/info/dir

.include <bsd.port.post.mk>
