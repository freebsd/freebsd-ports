# New ports collection makefile for:	aop
# Date created:				22. April 2004
# Whom:					Aaron Zauner <az_mail@gmx.at>
#
# $FreeBSD$
#

PORTNAME=	aop
PORTVERSION=	0.6
CATEGORIES=	games
MASTER_SITES=	http://raffi.at/code/aop/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A curses based arcade game with only 64 lines of code

DOCS=		COPYING README

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/local|${PREFIX}|g' \
		${WRKSRC}/Makefile

.if !defined(NOPORTDOCS)
post-install:
	@${MKDIR} ${DOCSDIR}
.for ii in ${DOCS}
	@${INSTALL_DATA} ${WRKSRC}/${ii} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
