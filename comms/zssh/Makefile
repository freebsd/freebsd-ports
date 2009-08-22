# New ports collection makefile for:	zssh
# Date created:			13 October 2001
# Whom:				Gea-Suan Lin (gslin@ccca.nctu.edu.tw)
#
# $FreeBSD$
#

PORTNAME=	zssh
PORTVERSION=	1.5c
PORTREVISION=	0
CATEGORIES=	comms security
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/1.5
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Interactively transferring files to a remote machine while using ssh

RUN_DEPENDS=	lrz:${PORTSDIR}/comms/lrzsz

HAS_CONFIGURE=	yes

PLIST_FILES=	bin/zssh bin/ztelnet
MAN1=		zssh.1 ztelnet.1

post-configure:
	@${REINPLACE_CMD} -e 's,^prefix.*,prefix = ${PREFIX},g' ${WRKSRC}/Makefile

.include <bsd.port.mk>
