# Ports collection Makefile for:	bitnotes
# Date created:				5 September 2000
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	bitnotes
PORTVERSION=	0.9
CATEGORIES=	deskutils gnome
MASTER_SITES=	http://www.bitbuilder.com/bitnotes/
DISTNAME=	BitNotes-${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	sobomax@FreeBSD.org

BUILD_DEPENDS=	automake:${PORTSDIR}/devel/automake

WRKSRC=		${WRKDIR}/BitNotes

USE_X_PREFIX=	yes
USE_AUTOCONF=	yes
USE_GMAKE=	yes
USE_GNOME=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib"

AUTOCONF=	autoconf && \
			${PERL} -pi -e 's|-lpthread|${PTHREAD_LIBS}|g ; \
				s|DATADIRNAME=lib|DATADIRNAME=share|g' \
				${WRKSRC}/configure

pre-patch:
	@find ${WRKSRC} -type l | xargs ${RM} -f
	@cd ${WRKSRC} && automake --add-missing 2>/dev/null
	@${RM} -f ${WRKSRC}/config.cache
	@find ${WRKSRC} \( -name "Makefile.in" -or -name "*.make" \) | xargs ${PERL} -pi -e \
		's|\$\(datadir\)/gnome/|\$\(datadir\)/|g ; \
		 s|\$\(datadir\)/locale|\$\(prefix\)/share/locale|g'

.include <bsd.port.mk>
