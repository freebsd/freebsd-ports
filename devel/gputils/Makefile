# New ports collection makefile for:	gputils
# Date created:				21 Jan 2002
# Whom:					Samuel Tardieu <sam@inf.enst.fr>
#
# $FreeBSD$
#

PORTNAME=	gputils
PORTVERSION=	0.10.3
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	sam@inf.enst.fr

GNU_CONFIGURE=	yes

MAN1=	gpasm.1 gpdasm.1 gputils.1 gpvc.1

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for ext in ps pdf lyx
	@${INSTALL_DATA} ${WRKSRC}/doc/gputils.${ext} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
