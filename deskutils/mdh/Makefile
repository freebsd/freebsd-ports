# New ports collection makefile for:	mdh
# Date created:				12 November 2003
# Whom:					Adam Weinberger <adamw@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	mdh
PORTVERSION=	1.9.54
PORTREVISION=	1
CATEGORIES=	deskutils gnome
MASTER_SITES=	http://www.gozer.org/my_stuff/gtk/gtk/mdh/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GTK2-based toolbar, sortof a gnomepanel replacement sortof

USE_X_PREFIX=	yes
USE_BZIP2=	yes
GNU_CONFIGURE=	yes
USE_GNOME=	gnomehack gnomeprefix gnometarget gtk20
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib"

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/src/${PORTNAME} ${PREFIX}/bin
.ifndef(NOPORTDOCS)
	@${MKDIR} ${DATADIR}
	@${INSTALL_DATA} ${WRKSRC}/README ${DATADIR}
.endif

.include <bsd.port.mk>
