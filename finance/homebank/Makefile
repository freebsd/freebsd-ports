# New ports collection makefile for:	homebank
# Date created:				24 June 2006
# Whom:					Mezz <mezz@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	homebank
DISTVERSION=	3.2alpha2
PORTREVISION=	1
CATEGORIES=	finance
MASTER_SITES=	http://homebank.free.fr/public/

MAINTAINER=	mezz@FreeBSD.org
COMMENT=	Manage your personal accounts at home

WRKSRC=		${WRKDIR}/${PORTNAME}
USE_XLIB=	yes
USE_GMAKE=	yes
USE_GNOME=	gtk20
USE_GETTEXT=	yes
USE_DOS2UNIX=	src/*
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib ${PTHREAD_LIBS}"

DOCS=		AUTHORS COPYING ChangeLog LICENSE NEWS README

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
BROKEN=	Does not build on FreeBSD 4.x
.endif

post-extract:
	@${RM} -rf ${WRKSRC}/autom4te.cache ${WRKSRC}/po/*.gmo

.ifndef (NOPORTDOCS)
post-install:
	@${MKDIR} ${DOCSDIR}
.for i in ${DOCS}
	@${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.post.mk>
