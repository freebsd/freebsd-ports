# New ports collection makefile for:	THE
# Date created:		7 May 1999
# Whom:			giffunip@asme.org
#
# $FreeBSD$
#

PORTNAME=	the
PORTVERSION=	3.0
CATEGORIES=	editors
MASTER_SITES=	ftp://ftp.lightlink.com/pub/hessling/THE/	\
		ftp://ftp.qut.edu.au/pub/markh/THE/		\
		ftp://ftp.wu-wien.ac.at/pub/src/Editors/THE/
DISTNAME=	THE-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org

BUILD_DEPENDS=	rexx:${PORTSDIR}/lang/rexx-imc
RUN_DEPENDS=	rexx:${PORTSDIR}/lang/rexx-imc

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-ncurses --with-rexximc \
		--with-rexxincdir=${LOCALBASE}/include \
		--with-rexxlibdir=${LOCALBASE}/lib

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/THE
	${INSTALL_DATA} ${WRKSRC}/*.html ${PREFIX}/share/doc/THE
.endif

.include <bsd.port.mk>
