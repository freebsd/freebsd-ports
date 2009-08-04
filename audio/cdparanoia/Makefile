# New ports collection makefile for:	cdparanoia
# Date created:		5 Jan 2003
# Whom:			Simon 'corecode' Schubert <corecode@corecode.ath.cx>
#
# $FreeBSD$
#

PORTNAME=	cdparanoia
PORTVERSION=	3.9.8
PORTREVISION=	8
CATEGORIES=	audio sysutils
MASTER_SITES=	http://www.xiph.org/paranoia/download/
DISTNAME=	${PORTNAME}-${PORTVERSION:C/^3\./III-alpha/}
EXTRACT_SUFX=	.src.tgz

MAINTAINER=	markus@FreeBSD.org
COMMENT=	A CDDA extraction tool (also known as ripper)

USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
MAKE_JOBS_UNSAFE=	yes

MAN1=		cdparanoia.1

post-patch:
	@${REINPLACE_CMD} -e 's/\(^ *default:\)/\1break;/' ${WRKSRC}/interface/utils.h

.include <bsd.port.mk>
