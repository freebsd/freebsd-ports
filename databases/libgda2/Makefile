# New ports collection makefile for:	libgda
# Date created:				8th March 2001
# Whom:					Ade Lovett <ade@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	libgda
PORTVERSION=	0.2.10
PORTREVISION=	1
CATEGORIES=	databases gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	stable/sources/gnome-db

MAINTAINER=	gnome@FreeBSD.org

LIB_DEPENDS=	giconv.2:${PORTSDIR}/converters/libiconv \
		gdbm.2:${PORTSDIR}/databases/gdbm

USE_GNOMECTRL=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
INSTALLS_SHLIB=	yes

CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib -lintl -lgdbm"

MAN3=		Gnome::GDA::Client.3 Gnome::GDA::Common.3
MAN3PREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}

pre-patch:
	@${PERL} -pi -e 's|-lpthread|-pthread|g ; \
		 s|DATADIRNAME=lib|DATADIRNAME=share|g' ${WRKSRC}/configure
	@find ${WRKSRC} -name "Makefile.in" | xargs ${PERL} -pi -e \
		's|\$\(datadir\)/gnome/|\$\(datadir\)/|g ; \
		 s|share/idl|share/gnome/idl|g ; \
		 s|\$\(datadir\)/locale|\$\(prefix\)/share/locale|g'

.include <bsd.port.mk>
