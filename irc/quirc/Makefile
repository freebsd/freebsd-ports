# New ports collection makefile for:	QuIRC
# Date created:		21 May 1999
# Whom:			Chris Piazza <cpiazza@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	quirc
PORTVERSION=	0.9.84
CATEGORIES=	irc tk84
MASTER_SITES=	${MASTER_SITE_LOCAL:S/$/:local/}

MAINTAINER=	kevlo@FreeBSD.org
COMMENT=	An irc client for the X Window System that uses TCL/TK

LIB_DEPENDS=	tk84.1:${PORTSDIR}/x11-toolkits/tk84

USE_X_PREFIX=	yes
USE_XLIB=	yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ARGS=	--with-wish=${LOCALBASE}/bin/wish8.4 \
		--with-tcl-include-dir=${LOCALBASE}/include/tcl8.4 \
		--with-tk-include-dir=${LOCALBASE}/include/tk8.4 \
		--with-tcl-lib-dir=${LOCALBASE}/lib/tcl8.4 \
		--with-tk-lib-dir=${LOCALBASE}/lib/tk8.4 \
		--with-tcl-lib=tcl84 \
		--with-tk-lib=tk84 \
		--with-tcl-version=8.4

MYPORTDOCS=	AUTHORS ChangeLog FAQ NEWS README doc/color.txt \
		doc/dccresum.txt doc/links.txt doc/nickcomp.txt \
		doc/quedit.txt doc/rfc1459.txt doc/tdcc.txt

post-install:
	@${MKDIR} ${DATADIR}/common
	${LN} -sf ../install.tcl ${DATADIR}/common
	@${MKDIR} ${DATADIR}/themes
	${LN} -sf ../default.tcl ${DATADIR}/themes
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in ${MYPORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
