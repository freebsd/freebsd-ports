# New ports collection makefile for:	par2cmdline
# Whom:					Chris Larsen <darth@vader.dk>
# Date created:				24 July 2003
#
# $FreeBSD$
#

PORTNAME=	par2cmdline
PORTVERSION=	0.3
CATEGORIES=	archivers
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	parchive
DISTNAME=	${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Tools for using Parity v2 Archive files

WRKSRC=		${WRKDIR}/${DISTNAME}

GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/README ${DOCSDIR}
.endif

.include <bsd.port.mk>
