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
WRKSRC=		${WRKDIR}/ogg

ACLOCAL?=	${LOCALBASE}/bin/aclocal
AUTOHEADER?=	${LOCALBASE}/bin/autoheader

post-patch:
	cd ${WRKSRC} && ${ACLOCAL}
	cd ${WRKSRC} && ${AUTOHEADER}
	cd ${WRKSRC} && ${AUTOMAKE} --add-missing
	cd ${WRKSRC} && ${AUTOCONF}

.include <bsd.port.mk>
