# New ports collection makefile for:	gperiodic
# Date created:				16 July 1999
# Whom:					Andrey Zakhvatov
#
# $FreeBSD$
#

PORTNAME=	gperiodic
PORTVERSION=	1.2.2
CATEGORIES=	biology
MASTER_SITES=	ftp://ftp.seul.org/pub/gperiodic/

MAINTAINER=	ports@FreeBSD.org

WRKSRC=		${WRKDIR}/gperiodic

USE_X_PREFIX=	yes
USE_GMAKE=	yes
USE_GTK=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib"

MAN1=		gperiodic.1

post-install:
	${INSTALL_MAN} ${WRKSRC}/man/gperiodic.1 ${PREFIX}/man/man1
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/gperiodic
.for file in AUTHORS COPYING Changes README
	${INSTALL_DATA} ${WRKSRC}/${file} ${PREFIX}/share/doc/gperiodic
.endfor
.endif

.include <bsd.port.mk>
