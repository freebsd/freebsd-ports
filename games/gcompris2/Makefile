# New ports collection makefile for:	gcompris
# Date created:				21 July 2000
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gcompris
PORTVERSION=	0.5.1
CATEGORIES=	games gnome
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
EXTRACT_SUFX=	.tgz

MAINTAINER=	sobomax@FreeBSD.org

BUILD_DEPENDS=	${LOCALBASE}/share/automake/install-sh:${PORTSDIR}/devel/automake

USE_X_PREFIX=	yes
USE_GMAKE=	yes
USE_GNOME=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib"

post-extract:
	@${LN} -sf ${LOCALBASE}/share/automake/install-sh ${WRKSRC}/install-sh
	@${LN} -sf ${LOCALBASE}/share/automake/mkinstalldirs ${WRKSRC}/mkinstalldirs
	@${RM} -f ${WRKSRC}/config.cache

pre-patch:
	@${PERL} -pi -e 's|-lpthread|${PTHREAD_LIBS}|g ; \
		 s|DATADIRNAME=lib|DATADIRNAME=share|g' ${WRKSRC}/configure
	@find ${WRKSRC} -name "Makefile.in" | xargs ${PERL} -pi -e \
		's|\$$\(datadir\)/gnome/|\$$\(datadir\)/|g ; \
		 s|\$$\(datadir\)/locale|\$$\(prefix\)/share/locale|g'

.include <bsd.port.mk>
