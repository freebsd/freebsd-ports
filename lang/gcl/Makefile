# New ports collection makefile for:    gcl
# Date created:         Feb  8 1995
# Whom:                 hsu
#
# $FreeBSD$
#

PORTNAME=	gcl
PORTVERSION=	2.4.0
CATEGORIES=	lang
MASTER_SITES=	ftp://ftp.ma.utexas.edu/pub/gcl/
EXTRACT_SUFX=	.tgz

MAINTAINER=	twp@unchi.org

BROKEN=		"Dies with sig11 during build"

GNU_CONFIGURE=	yes
CONFIGURE_ARGS= --enable-machine=FreeBSD
MAKEFILE=	makefile

PLIST_SUB=	GCL_VER=${PORTVERSION}

pre-configure:
	@${LN} -sf unexelf.c ${WRKSRC}/o/unexec.c

pre-build:
	${RM} -rf ${WRKSRC}/info/gcl-si.info* ${WRKSRC}/info/gcl-tk.info*

post-install:
	${INSTALL_DATA} ${WRKSRC}/info/gcl-si.info ${PREFIX}/info
	${INSTALL_DATA} ${WRKSRC}/info/gcl-tk.info ${PREFIX}/info
	@install-info ${PREFIX}/info/gcl-si.info ${PREFIX}/info/dir
	@install-info ${PREFIX}/info/gcl-tk.info ${PREFIX}/info/dir

.include <bsd.port.mk>
