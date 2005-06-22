# New ports collection makefile for:	malint
# Date created:				20 Jun 2005
# Whom:					Emanuel Haupt <ehaupt@critical.ch>
#
# $FreeBSD$
#

PORTNAME=	malint
DISTVERSION=	0.2
CATEGORIES=	audio
MASTER_SITES=	http://www.nih.at/malint/ \
		ftp://sunsite.univie.ac.at/pub/nih/malint/

MAINTAINER=	ehaupt@critical.ch
COMMENT=	MPEG Audio stream validator

GNU_CONFIGURE=	yes

CONFIGURE_TARGET=	--build=${ARCH}-portbld-freebsd${OSREL}
PORTDOCS=	README
PLIST_FILES=	bin/malint

.if !defined(NOPORTDOCS)
post-install:
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif

.include <bsd.port.mk>
