# New ports collection makefile for:	dopewars
# Date created:			16 May 1999
# Whom:				Jim Mock <jim@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	dopewars
PORTVERSION=	1.5.2
CATEGORIES=	games
MASTER_SITES=	http://dopewars.sourceforge.net/ \
		http://bellatrix.pcl.ox.ac.uk/~ben/dopewars/

MAINTAINER=	petef@FreeBSD.org

USE_GMAKE=	yes
GNU_CONFIGURE=	yes
USE_GTK=	yes
USE_X_PREFIX=	yes

CONFIGURE_ARGS=	--enable-nls

.if defined(NOPORTDOCS)
MAKE_ENV+=	NOPORTDOCS=yes
.endif

PLIST_SUB=	DOPEWARS=${PKGNAME}

MAN6=	dopewars.6

post-patch:
	@${PERL} -pi -e 's!/pixmaps!/dopewars/pixmaps!' \
		${WRKSRC}/src/Makefile.in
	@${PERL} -pi -e 's!dopewars.sco!dopewars/dopewars.sco!g' \
		${WRKSRC}/src/dopewars.c ${WRKSRC}/Makefile.in

.include <bsd.port.mk>
