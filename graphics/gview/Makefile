# New ports collection makefile for:	gview
# Date created:				30 April 1999
# Whom:					Andrey Zakhvatov
#
# $FreeBSD$
#

PORTNAME=	gview
PORTVERSION=	0.1.15
CATEGORIES=	graphics
MASTER_SITES=	http://netpedia.net/hosting/gview/ \
		http://homepages.petech.ac.za/~bruces/ \
		ftp://ftp.petech.ac.za/pub/viewers/

MAINTAINER=	cpiazza@FreeBSD.org

USE_X_PREFIX=	yes
USE_IMLIB=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib"

pre-patch:
	@${PERL} -pi -e 's|-lpthread|${PTHREAD_LIBS}|g ; \
		 s|DATADIRNAME=lib|DATADIRNAME=share|g ; \
		 s|USE_INCLUDED_LIBINTL=yes|#USE_INCLUDED_LIBINTL=yes|g ; \
		 s|\$$\(top_builddir\)/intl/libintl.a|-lintl|g' ${WRKSRC}/configure

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/gview
.for file in AUTHORS BUGS ChangeLog NEWS README TODO
	${INSTALL_DATA} ${WRKSRC}/${file} ${PREFIX}/share/doc/gview
.endfor
.endif

.include <bsd.port.mk>
