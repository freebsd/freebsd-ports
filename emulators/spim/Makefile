# ex:ts=8
# Ports collection makefile for:  spim
# Date created:			  Mon Oct 28, 1996
# Whom:				  David O'Brien (obrien@cs.ucdavis.edu)
#
# $FreeBSD$
#

PORTNAME=	spim
PORTVERSION=	6.3
PORTREVISION=	1
CATEGORIES=	emulators
MASTER_SITES=	ftp://ftp.cs.wisc.edu/pub/spim/
DISTNAME=	${PORTNAME}${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

USE_XLIB=	yes
HAS_CONFIGURE=	yes
CONFIGURE_SCRIPT=	Configure
MAKEFILE=	Makefile.std
ALL_TARGET=	spim xspim
MAN1=		spim.1 xspim.1

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/spim
	${INSTALL_DATA} ${WRKSRC}/Documentation/*.ps ${PREFIX}/share/doc/spim
	${GZIP_CMD} ${PREFIX}/share/doc/spim/*.ps
.endif

.include <bsd.port.mk>
