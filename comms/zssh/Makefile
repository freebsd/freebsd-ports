# New ports collection makefile for:	zssh
# Date created:			13 October 2001
# Whom:				Gea-Suan Lin (gslin@ccca.nctu.edu.tw)
#
# $FreeBSD$
#

PORTNAME=	zssh
PORTVERSION=	1.5a
PORTREVISION=	1
CATEGORIES=	comms security
MASTER_SITES=	http://prdownloads.sf.net/zssh/
EXTRACT_SUFX=	.tgz

MAINTAINER=	gslin@ccca.nctu.edu.tw

RUN_DEPENDS=	lrz:${PORTSDIR}/comms/lrzsz

HAS_CONFIGURE=	yes

MAN1=		zssh.1 ztelnet.1

post-configure:
	@${PERL} -pi -e 's,^prefix.*,prefix = ${PREFIX},g' ${WRKSRC}/Makefile

.include <bsd.port.mk>
