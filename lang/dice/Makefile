# New ports collection makefile for:	dice
# Date created:		Wed Jan 30 13:26:52 CET 2002
# Whom:			Miguel Mendez <flynn@energyhq.homeip.net>
#
# $FreeBSD$
#

PORTNAME=	dice
PORTVERSION=	3.15
CATEGORIES=	lang devel
MASTER_SITES=	http://www.obviously.com/dice/
DISTNAME=	${PORTNAME}-rel-${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	flynn@energyhq.homeip.net

post-patch:
		@${CP} ${FILESDIR}/Makefile ${WRKSRC}

do-install:
		@for i in ${WRKSRC}/ubin/*; \
		do \
			${INSTALL_PROGRAM} $$i ${PREFIX}/bin; \
		done

.if !defined(NOPORTDOCS)
		@${MKDIR} ${PREFIX}/share/doc/dice
		@for i in ${WRKSRC}/doc/* ; \
		do \
			${INSTALL_DATA} $$i ${PREFIX}/share/doc/dice; \
		done
.endif

.include <bsd.port.mk>
