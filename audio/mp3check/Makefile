# New ports collection makefile for:	mp3check
# Date created:			Apr 16, 2001
# Whom:				Mark Pulford <mark@kyne.com.au>
#
# $FreeBSD$
#

PORTNAME=	mp3check
PORTVERSION=	1.6
CATEGORIES=	audio
MASTER_SITES=	http://www.icculus.org/mp3check/
EXTRACT_SUFX=

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A tool for checking and fixing mp3 archive inconsistencies

RUN_DEPENDS=	${LOCALBASE}/bin/id3tool:${PORTSDIR}/audio/id3tool \
		${LOCALBASE}/bin/mp3_check:${PORTSDIR}/audio/mp3_check

USE_PERL5_RUN=	yes
NO_WRKSUBDIR=	yes
EXTRACT_CMD=	${CP}
EXTRACT_BEFORE_ARGS=
EXTRACT_AFTER_ARGS=	${WRKSRC}
NO_BUILD=	yes
PLIST_FILES=	bin/mp3check

pre-patch:
	${REINPLACE_CMD} -E "s|^#!.+|#!${PERL}|" ${WRKSRC}/${DISTNAME}

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${DISTNAME} ${PREFIX}/bin/mp3check

.include <bsd.port.mk>
