# New ports collection makefile for:	rolo
# Date created:				04 April 2003
# Whom:	      				Andrew Hsu <ahsu@users.sf.net>
#
# $FreeBSD$
#

PORTNAME=	rolo
PORTVERSION=	010
PORTREVISION=	1
CATEGORIES=	deskutils
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	obraun@FreeBSD.org
COMMENT=	Text-based contact management software

USE_BZIP2=	yes
USE_BISON=	yes
GNU_CONFIGURE=	yes
USE_REINPLACE=	yes

MAN1=		rolo.1

post-patch:
	@${REINPLACE_CMD} "s/mutt_vc_query//" ${WRKSRC}/Makefile.*

post-install:
	@${ECHO_CMD} "***************************************************************"
	@${ECHO_CMD} "mutt_vc_query is no longer available as part of deskutils/rolo."
	@${ECHO_CMD} "Install mail/mutt_vc_query instead."
	@${ECHO_CMD} "***************************************************************"

.include <bsd.port.mk>
