# New ports collection makefile for:	homebank
# Date created:				24 June 2006
# Whom:					Mezz <mezz@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	homebank
DISTVERSION=	3.2alpha2
CATEGORIES=	finance
MASTER_SITES=	http://homebank.free.fr/public/

MAINTAINER=	mezz@FreeBSD.org
COMMENT=	Manage your personal accounts at home

WRKSRC=		${WRKDIR}/${PORTNAME}
USE_GMAKE=	yes
USE_GNOME=	gtk20
USE_GETTEXT=	yes
USE_DOS2UNIX=	src/*
USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib ${PTHREAD_LIBS}"

DOCS=		AUTHORS COPYING ChangeLog LICENSE NEWS README

post-extract:
	@${RM} -rf ${WRKSRC}/autom4te.cache ${WRKSRC}/po/*.gmo

.ifndef (NOPORTDOCS)
post-install:
	@${MKDIR} ${DOCSDIR}
.for i in ${DOCS}
	@${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
