# New ports collection makefile for:	glimmer
# Date created:				1 August 2000
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	glimmer
PORTVERSION=	1.2.0
CATEGORIES=	editors gnome python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	gnome@FreeBSD.org

BUILD_DEPENDS=	${PYTHON_SITELIBDIR}/_gtkmodule.so:${PORTSDIR}/x11-toolkits/py-gtk
RUN_DEPENDS=	${PYTHON_SITELIBDIR}/_gtkmodule.so:${PORTSDIR}/x11-toolkits/py-gtk

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

USE_X_PREFIX=	yes
USE_PYTHON=	yes
USE_GMAKE=	yes
USE_GNOME=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-regex
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include -D_REGEX_H_ -D_REGEX_H" \
		LIBS="-L${LOCALBASE}/lib -lgnuregex"
.if exists(/usr/lib/libcrypto.a)
PYTHON_LIBS=	-lssl -lcrypto
.endif
PYTHON_LIBS+=	-lutil -lreadline -lcrypt -lpython

pre-patch:
	@${PERL} -pi -e 's|-lpthread|${PTHREAD_LIBS}|g ; \
		s|-lpython|${PYTHON_LIBS}|g ; \
		s|DATADIRNAME=lib|DATADIRNAME=share|g' ${WRKSRC}/configure
	@find ${WRKSRC} -name "Makefile.in" | xargs ${PERL} -pi -e \
		's|\$\(datadir\)/gnome/|\$\(datadir\)/|g ; \
		 s|\$\(datadir\)/locale|\$\(prefix\)/share/locale|g'

.include <bsd.port.mk>
