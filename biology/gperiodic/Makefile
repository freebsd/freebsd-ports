# New ports collection makefile for:	gperiodic
# Date created:				16 July 1999
# Whom:					Andrey Zakhvatov
#
# $FreeBSD$
#

PORTNAME=	gperiodic
PORTVERSION=	1.3.3
CATEGORIES=	biology
MASTER_SITES=	ftp://ftp.seul.org/pub/gperiodic/ \
		http://www.unixpages.org/distfiles/

MAINTAINER=	chris@unixpages.org

USE_X_PREFIX=	yes
USE_GNOMENG=	yes
USE_GNOME=	gtk12
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib"

MAN1=		gperiodic.1

post-extract:
	@${LN} -sf Makefile.in.in ${WRKSRC}/po/Makefile.in

post-install:
	${INSTALL_MAN} ${WRKSRC}/man/gperiodic.1 ${MANPREFIX}/man/man1
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in AUTHORS ChangeLog README
	${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
