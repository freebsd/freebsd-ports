# New ports collection makefile for:	cascade
# Date created:				9 November 2002
# Whom:					Marc Fonvieille <blackend@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	cascade
PORTVERSION=	1.4
CATEGORIES=	cad
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:S/%SUBDIR%/rfcascade/}
DISTNAME=	${PORTNAME}-${PORTVERSION}

MAINTAINER=	blackend@FreeBSD.org
COMMENT=	A simple tool to analyze noise and distortion of a RF system

GNU_CONFIGURE=	YES

MAN1=		cascade.1

do-install:
		@${INSTALL_SCRIPT} ${WRKSRC}/cascade ${PREFIX}/bin
		@${INSTALL_MAN} ${WRKSRC}/cascade.1 ${MANPREFIX}/man/man1
		@${MKDIR} ${PREFIX}/share/examples/${PORTNAME}
		@${INSTALL_DATA} ${WRKSRC}/examples/* \
			${PREFIX}/share/examples/${PORTNAME}
		@${INSTALL_DATA} ${WRKSRC}/cascade-mode.el \
			${PREFIX}/share/emacs/site-lisp
.if !defined(NOPORTDOCS)
		@${MKDIR} ${PREFIX}/share/doc/${PORTNAME}
		@${INSTALL_DATA} ${WRKSRC}/doc/* \
			${PREFIX}/share/doc/${PORTNAME}
.endif

.include <bsd.port.mk>
