# New ports collection makefile for:	manedit
# Date created:				9 February 2001
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	manedit
PORTVERSION=	0.4.i
CATEGORIES=	editors
MASTER_SITES=	ftp://fox.mit.edu/pub/xsw/
DISTNAME=	${PORTNAME}${PORTVERSION:S/.i/i/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	sobomax@FreeBSD.org

WRKSRC=		${WRKDIR}/${DISTNAME}/${PORTNAME}

USE_X_PREFIX=	yes
USE_GTK=	yes

MAN1=		manedit.1

pre-patch:
	@find ${WRKSRC} \( -name "*.[ch]" -or -name "*.cpp" \) | \
		xargs ${PERL} -pi -e 's|malloc\.h|stdlib.h|g'

.include <bsd.port.mk>
