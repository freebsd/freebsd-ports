# New ports collection makefile for:	libgda
# Date created:				8th March 2001
# Whom:					Ade Lovett <ade@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	libgda
PORTVERSION=	0.2.90
PORTREVISION=	2
CATEGORIES=	databases gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	stable/sources/gnome-db

MAINTAINER=	gnome@FreeBSD.org

BUILD_DEPENDS=	automake:${PORTSDIR}/devel/automake \
		libtool:${PORTSDIR}/devel/libtool
LIB_DEPENDS=	gdbm.2:${PORTSDIR}/databases/gdbm \
		bonobo.2:${PORTSDIR}/devel/bonobo

USE_X_PREFIX=	yes
USE_GNOMECTRL=	yes
USE_GMAKE=	yes
INSTALLS_SHLIB=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib -lintl -lgdbm"
CONFIGURE_TARGET=	--target=${MACHINE_ARCH}-unknown-freebsd${OSREL}

pre-patch:
	@${PERL} -pi -e 's|-lpthread|-pthread|g ; \
		 s|DATADIRNAME=lib|DATADIRNAME=share|g' ${WRKSRC}/configure
	@find ${WRKSRC} -name "Makefile.in" | xargs ${PERL} -pi -e \
		's|\$\(datadir\)/gnome/|\$\(datadir\)/|g ; \
		 s|share/idl|share/gnome/idl|g ; \
		 s|\$\(datadir\)/locale|\$\(prefix\)/share/locale|g'

# <GNOME release management sucks!!!>
MISSED=		install-sh config.sub config.guess mkinstalldirs

pre-configure:
.for file in ${MISSED}
	@${LN} -sf ${LOCALBASE}/share/automake/${file} ${WRKSRC}/
	@${LN} -sf ${LOCALBASE}/share/automake/${file} ${WRKDIR}/
.endfor

pre-build:
	@${LN} -sf ${LOCALBASE}/bin/libtool ${WRKSRC}/
# </GNOME release management sucks!!!>

.include <bsd.port.mk>
