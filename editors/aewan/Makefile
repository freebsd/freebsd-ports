# New ports collection makefile for:	aewan
# Date created:				07.05.2004
# Whom:					krion
#
# $FreeBSD$
#

PORTNAME=	aewan
PORTVERSION=	0.9.2
CATEGORIES=	editors
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	aewan

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Curses-based program for the creation and editing of ascii art

USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}

PLIST_FILES=	bin/aecat bin/aewan
PORTDOCS=	README

MAN1=		aecat.1 aewan.1
MAN5=		aewan.5

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for i in README
	${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
