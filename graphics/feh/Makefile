# ports collection makefile for:	feh
# Date created:				16 Oct 2000
# Whom:					Jeremy Norris <ishmael27@home.com>
#
# $FreeBSD$
#

PORTNAME=	feh
PORTVERSION=	1.2.2
PORTCOMMENT=	An image viewer that utilizes Imlib2
CATEGORIES=	graphics
MASTER_SITES=	http://www.linuxbrit.co.uk/downloads/

MAINTAINER=	ports@FreeBSD.org

LIB_DEPENDS=	gnugetopt.1:${PORTSDIR}/devel/libgnugetopt \
		giblib.1:${PORTSDIR}/graphics/giblib

USE_X_PREFIX=	yes
USE_PERL5=	yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib -lgnugetopt"

MAN1=		feh.1

.if defined(NOPORTDOCS)
MAKE_ENV=	NO_DOC=yes
.endif

.include <bsd.port.mk>
