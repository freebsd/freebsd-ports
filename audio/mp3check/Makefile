# New ports collection makefile for:	mp3check
# Date created:			Apr 16, 2001
# Whom:				Mark Pulford <mark@kyne.com.au>
#
# $FreeBSD$
#

PORTNAME=	mp3check
PORTVERSION=	1.1
CATEGORIES=	audio
MASTER_SITES=	http://www.icculus.org/mp3check/
DISTNAME=	${PORTNAME}
EXTRACT_SUFX=

MAINTAINER=	mark@kyne.com.au

RUN_DEPENDS=	${LOCALBASE}/bin/id3tool:${PORTSDIR}/audio/id3tool \
		${LOCALBASE}/bin/mp3_check:${PORTSDIR}/audio/mp3_check

USE_PERL5=	yes
NO_WRKSUBDIR=	yes
EXTRACT_CMD=	${CP}
EXTRACT_BEFORE_ARGS=
EXTRACT_AFTER_ARGS=	${WRKSRC}
NO_BUILD=	yes

pre-patch:
	@${PERL} -pi -e "s|^#!.+|#!${PERL}|" ${WRKSRC}/mp3check

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/mp3check ${PREFIX}/bin

.include <bsd.port.mk>
