# New ports collection makefile for:	QuIRC
# Date created:		21 May 1999
# Whom:			Chris Piazza <cpiazza@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	quirc
PORTVERSION=	0.9.83
CATEGORIES=	irc tk83
MASTER_SITES=	http://quirc.org/

MAINTAINER=	kevlo@FreeBSD.org
COMMENT=	An irc client for the X Window System that uses TCL/TK

LIB_DEPENDS=	tk83.1:${PORTSDIR}/x11-toolkits/tk83

USE_XLIB=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CXXFLAGS="${CXXFLAGS} -pedantic"
CONFIGURE_ARGS=	--with-wish=${PREFIX}/bin/wish8.3 \
		--with-tcl-include-dir=${LOCALBASE}/include/tcl8.3 \
		--with-tk-include-dir=${LOCALBASE}/include/tk8.3 \
		--with-tcl-lib-dir=${LOCALBASE}/lib/tcl8.3 \
		--with-tk-lib-dir=${LOCALBASE}/lib/tk8.3 \
		--with-tcl-lib=tcl83 \
		--with-tk-lib=tk83 \
		--with-tcl-version=8.3

MYPORTDOCS=	AUTHORS ChangeLog FAQ NEWS README doc/color.txt \
		doc/dccresum.txt doc/links.txt doc/nickcomp.txt \
		doc/quedit.txt doc/rfc1459.txt doc/tdcc.txt

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 500113
BROKEN=		"Does not compile on FreeBSD ${OSVERSION}"
.endif

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/quirc
.for file in ${MYPORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${file} ${PREFIX}/share/doc/quirc
.endfor
.endif

.include <bsd.port.post.mk>
