# New ports collection makefile for:	QuIRC
# Date created:		21 May 1999
# Whom:			Chris Piazza <cpiazza@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	quirc
PORTVERSION=	0.9.80
CATEGORIES=	irc tk82
MASTER_SITES=	http://patearl.powersurfr.com/quirc/
DISTNAME=	${PORTNAME}-0.9.79

MAINTAINER=	ports@FreeBSD.org

LIB_DEPENDS=	tk82.1:${PORTSDIR}/x11-toolkits/tk82

USE_XLIB=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CXXFLAGS="${CXXFLAGS} -pedantic"
CONFIGURE_ARGS=	--with-wish=${PREFIX}/bin/wish8.2 \
		--with-tcl-include-dir=${LOCALBASE}/include/tcl8.2 \
		--with-tk-include-dir=${LOCALBASE}/include/tk8.2 \
		--with-tcl-lib-dir=${LOCALBASE}/lib/tcl8.2 \
		--with-tk-lib-dir=${LOCALBASE}/lib/tk8.2 \
		--with-tcl-lib=tcl82 \
		--with-tk-lib=tk82 \
		--with-tcl-version=8.2

PORTDOCS=	AUTHORS ChangeLog FAQ NEWS README doc/color.txt \
		doc/nickcomp.txt doc/quedit.txt doc/rfc1459.txt

post-install:
#	${INSTALL_SCRIPT} ${WRKSRC}/quirc.inst ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/quirc
.for file in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${file} ${PREFIX}/share/doc/quirc
.endfor
.endif

.include <bsd.port.mk>
