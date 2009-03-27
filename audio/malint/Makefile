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
		ftp://sunsite.univie.ac.at/pub/nih/malint/ \
		CRITICAL

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	MPEG Audio stream validator

GNU_CONFIGURE=	yes
MAKE_JOBS_SAFE=	yes

PORTDOCS=	README
PLIST_FILES=	bin/malint

.if !defined(NOPORTDOCS)
post-install:
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif

.include <bsd.port.mk>
