# New ports collection makefile for:	dia
# Date created:        21 December 1999
# Whom:                saper@system.pl
#
# $FreeBSD$
#

PORTNAME=	dia
PORTVERSION=	0.86
CATEGORIES=	graphics gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	stable/sources/dia

MAINTAINER=	saper@system.pl

LIB_DEPENDS=	xml.5:${PORTSDIR}/textproc/libxml	\
		popt.0:${PORTSDIR}/devel/popt

USE_X_PREFIX=	yes
USE_GMAKE=	yes
USE_IMLIB=	yes
WANT_GNOME=	yes
USE_LIBTOOL=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib"

MAN1=		dia.1

.include <bsd.port.pre.mk>

.if defined(HAVE_GNOME)
USE_GNOME=	yes
CONFIGURE_ARGS=	--enable-gnome
.endif

pre-patch:
	@${PERL} -pi -e 's|-lpthread|${PTHREAD_LIBS}|g ; \
		 s|DATADIRNAME=lib|DATADIRNAME=share|g' ${WRKSRC}/configure
	@find ${WRKSRC} -name "Makefile.in" | xargs ${PERL} -pi -e \
		's|\$\(datadir\)/gnome/|\$\(datadir\)/|g ; \
		 s|\$\(datadir\)/locale|\$\(prefix\)/share/locale|g'

post-install:
	${SED} "s|%%PREFIX%%|${PREFIX}|g" ${FILESDIR}/dia.sh > ${WRKDIR}/dia.sh
	${INSTALL_SCRIPT} ${WRKDIR}/dia.sh ${PREFIX}/bin/dia

.include <bsd.port.post.mk>
