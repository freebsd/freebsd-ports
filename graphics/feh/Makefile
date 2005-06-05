# ports collection makefile for:	feh
# Date created:				16 Oct 2000
# Whom:					Jeremy Norris <ishmael27@home.com>
#
# $FreeBSD$
#

PORTNAME=	feh
PORTVERSION=	1.3.3
CATEGORIES=	graphics
MASTER_SITES=	http://www.linuxbrit.co.uk/downloads/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An image viewer that utilizes Imlib2

LIB_DEPENDS=	giblib.1:${PORTSDIR}/graphics/giblib

USE_X_PREFIX=	yes
USE_PERL5=	yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

MAN1=		feh.1

post-patch:
	@${PERL} -pi.bak -e 's|^LDFLAGS =.*$$|LDFLAGS = \@LDFLAGS\@|g ; \
		 s|^INCLUDES =.*$$|INCLUDES = -I. -I$$(includedir)|g ; \
		 s|-man install-docsDATA|-man|g' ${WRKSRC}/Makefile.in

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in AUTHORS ChangeLog README TODO
	${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
