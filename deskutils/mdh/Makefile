# New ports collection makefile for:	mdh
# Date created:				12 November 2003
# Whom:					Adam Weinberger <adamw@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	mdh
PORTVERSION=	1.9.54
PORTREVISION=	7
CATEGORIES=	deskutils gnome
MASTER_SITES=	http://www.gozer.org/my_stuff/gtk/gtk/mdh/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GTK2-based toolbar, like a smaller GNOME panel

USE_BZIP2=	yes
USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes
USE_GNOME=	gnometarget gtk20
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/${PORTNAME} ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif

.include <bsd.port.mk>
