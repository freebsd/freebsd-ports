# ex:ts=8
# New ports collection makefile for:	bitbox
# Date created:			Apr 8, 2001
# Whom:				Ying-Chieh Liao <ijliao@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	bitbox
PORTVERSION=	0.3.0
CATEGORIES=	archivers
MASTER_SITES=	http://www.gizmodrome.com/

MAINTAINER=	ijliao@FreeBSD.org

LIB_DEPENDS=	gnugetopt.1:${PORTSDIR}/devel/libgnugetopt

WRKSRC=		${WRKDIR}/${PORTNAME}
MAKEFILE=	makefile
ALL_TARGET=	${PORTNAME}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/${PORTNAME}
	${CP} ${WRKSRC}/quickstart.txt ${PREFIX}/share/doc/${PORTNAME}
.endif

.include <bsd.port.mk>
