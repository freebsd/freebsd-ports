# Created by: Ade Lovett <ade@lovett.com>
# $FreeBSD$
#   $MCom: ports/devel/bonobo/Makefile,v 1.5 2007/05/19 21:36:04 marcus Exp $

PORTNAME=	bonobo
PORTVERSION=	1.0.22
PORTREVISION=	12
CATEGORIES=	devel gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	The component and compound document system for GNOME

USE_BZIP2=	yes
USE_GNOME=	gnomehack gnomeprefix oaf gnomehier gnomeprint
USES=		gettext gmake perl5
GNOME_HTML_DIR=	${PREFIX}/share/doc/bonobo
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	LIBS="-L${LOCALBASE}/lib"
CPPFLAGS+=	-I${LOCALBASE}/include

NO_STAGE=	yes
post-patch:
	@${REINPLACE_CMD} -e 's|echo aout|echo elf|g' \
	    	${WRKSRC}/configure \
		${WRKSRC}/libefs/configure

.include <bsd.port.mk>
