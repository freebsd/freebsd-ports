# ports collection makefile for:	feh
# Date created:				16 Oct 2000
# Whom:					Jeremy Norris <ishmael27@home.com>
#
# $FreeBSD$
#

PORTNAME=	feh
PORTVERSION=	1.1.1
CATEGORIES=	graphics
MASTER_SITES=	http://www.linuxbrit.co.uk/downloads/

MAINTAINER=	ishmael27x@yahoo.com

LIB_DEPENDS=	Imlib2.1:${PORTSDIR}/graphics/imlib2

GNU_CONFIGURE=	yes
USE_PERL5=	yes
USE_X_PREFIX=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${X11BASE}/include" \
		LIBS="-L${X11BASE}/lib"
CONFIGURE_TARGET=	--target=${MACHINE_ARCH}-portbld-freebsd${OSREL}

.if defined(NOPORTDOCS)
MAKE_ENV=	NO_DOC=yes
.endif

MAN1=		feh.1

.include <bsd.port.mk>
