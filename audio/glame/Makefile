# New ports collection makefile for:	glame
# Date created:				26 September 2000
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	glame
PORTVERSION=	1.0.1
CATEGORIES=	audio gnome
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A powerful, fast, stable, and easily extensible sound editor for GNOME

LIB_DEPENDS=	ltdl.4:${PORTSDIR}/devel/libltdl

USE_GNOME=	gnomeprefix gnomehack libglade
USE_X_PREFIX=	yes
USE_GMAKE=	yes
USE_LIBTOOL=	yes
INSTALLS_SHLIB=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib -lltdl ${PTHREAD_LIBS}"

.include <bsd.port.pre.mk>

post-patch:
	@${REINPLACE_CMD} -e 's|-lpthread|${PTHREAD_LIBS}|g ; \
		 s|DATADIRNAME=lib|DATADIRNAME=share|g' ${WRKSRC}/configure
	@find ${WRKSRC} -name "Makefile.in*" | xargs ${REINPLACE_CMD} -e \
		's|-lpthread|${PTHREAD_LIBS}|g'
	@find ${WRKSRC} -name "*.[ch]" | xargs ${REINPLACE_CMD} -e \
		's|<values[.]h>|<limits.h>|'

post-install:
	@install-info ${PREFIX}/info/glame.info \
		--section="Audio Processing" \
		--entry="* glame: (glame).           audio processing tool for GNOME" \
		${PREFIX}/info/dir

.include <bsd.port.post.mk>
