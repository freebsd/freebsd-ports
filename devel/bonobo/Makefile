# New ports collection makefile for:	bonobo
# Date created:				8th October 1999
# Whom:					Ade Lovett <ade@lovett.com>
#
# $FreeBSD$
#   $MCom: ports/devel/bonobo/Makefile,v 1.2 2006/09/10 00:51:07 mezz Exp $
#

PORTNAME=	bonobo
PORTVERSION=	1.0.22
PORTREVISION=	3
CATEGORIES=	devel gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/${PORTNAME}/1.0
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	The component and compound document system for GNOME

USE_BZIP2=	yes
USE_XLIB=	yes
USE_PERL5=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomehack gnomeprefix oaf gnomehier gnomeprint
USE_GETTEXT=	yes
GNOME_HTML_DIR=	${PREFIX}/share/doc/bonobo
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib"
CONFIGURE_TARGET=	--target=${MACHINE_ARCH}-unknown-freebsd${OSREL}

post-patch:
	@${REINPLACE_CMD} -e 's|echo aout|echo elf|g' \
	    	${WRKSRC}/configure \
		${WRKSRC}/libefs/configure

.include <bsd.port.mk>
