# New ports collection makefile for:	QuIRC
# Date created:		21 May 1999
# Whom:			Chris Piazza <cpiazza@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	quirc
PORTVERSION=	0.9.84
PORTREVISION=	5
CATEGORIES=	irc tk
MASTER_SITES=	${MASTER_SITE_LOCAL:S/$/:local/}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An irc client for the X Window System that uses TCL/TK

USE_TK=		84+
USE_XORG=	xt

GNU_CONFIGURE=	yes

MYPORTDOCS=	AUTHORS ChangeLog FAQ NEWS README doc/color.txt \
		doc/dccresum.txt doc/links.txt doc/nickcomp.txt \
		doc/quedit.txt doc/rfc1459.txt doc/tdcc.txt

.include <bsd.port.pre.mk>
CONFIGURE_ARGS=	--with-wish=${WISH} \
		--with-tcl-include-dir=${TCL_INCLUDEDIR} \
		--with-tk-include-dir=${TK_INCLUDEDIR} \
		--with-tcl-lib-dir=${TCL_LIBDIR} \
		--with-tk-lib-dir=${TK_LIBDIR} \
		--with-tcl-lib=tcl${TCL_VER:S/.//} \
		--with-tk-lib=tk${TCL_VER:S/.//} \
		--with-tcl-version=${TCL_VER}

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

.include <bsd.port.post.mk>
