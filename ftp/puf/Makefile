# ex:ts=8
# New ports collection makefile for:	puf
# Date created:			Feb 6, 2001
# Whom:				Ying-Chieh Liao <ijliao@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	puf
PORTVERSION=	0.93.2
CATEGORIES=	ftp
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org

BUILD_DEPENDS=	${LOCALBASE}/share/automake/depcomp:${PORTSDIR}/devel/automake

GNU_CONFIGURE=	yes

MAN1=		puf.1

post-extract:
	@${CP} -f ${LOCALBASE}/share/automake/depcomp ${WRKSRC}

.include <bsd.port.mk>
