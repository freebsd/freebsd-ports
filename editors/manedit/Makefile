# New ports collection makefile for:	manedit
# Date created:				9 February 2001
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	manedit
PORTVERSION=	0.5.6
CATEGORIES=	editors
MASTER_SITES=	ftp://wolfpack.twu.net/users/wolfpack/

MAINTAINER=	sobomax@FreeBSD.org

WRKSRC=		${WRKDIR}/${DISTNAME}/${PORTNAME}

USE_BZIP2=	yes
USE_X_PREFIX=	yes
USE_GNOMENG=	yes
USE_GNOME=	gtk12
MAKEFILE=	Makefile.FreeBSD

MAN1=		manedit.1

pre-patch:
	@find ${WRKSRC} -name "*.[ch]" | \
		xargs ${PERL} -pi -e 's|malloc\.h|stdlib.h|g'

.include <bsd.port.mk>
