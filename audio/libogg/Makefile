# New ports collection makefile for:	libogg
# Date created:				18 October 2000
# Whom:					t.vanklaveren@student.utwente.nl
#
# $FreeBSD$
#

PORTNAME=	libogg
PORTVERSION=	20001018
CATEGORIES=	audio
MASTER_SITES=	http://home.student.utwente.nl/t.vanklaveren/distfiles/
DISTNAME=	ogg-${PORTVERSION}

MAINTAINER=	t.vanklaveren@student.utwente.nl

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_LIBTOOL=	yes
USE_AUTOMAKE=	yes
AUTOMAKE_ARGS=	--add-missing
WRKSRC=		${WRKDIR}/ogg

AUTOHEADER?=	${LOCALBASE}/bin/autoheader

pre-configure:
	cd ${WRKSRC} && ${AUTOHEADER}

.include <bsd.port.mk>
