# New ports collection makefile for:	THE
# Version required:	2.8
# Date created:		7 May 1999
# Whom:			giffunip@asme.org
#
# $FreeBSD$
#

DISTNAME=	THE-2.8
PKGNAME=	the-2.8
CATEGORIES=	editors
MASTER_SITES=	ftp://ftp.lightlink.com/pub/hessling/THE/	\
		ftp://uiarchive.cso.uiuc.edu/pub/packages/THE/	\
		ftp://ftp.qut.edu.au/pub/markh/THE/		\
		ftp://ftp.rzg.mpg.de/pub/software/the/THE/	\
		ftp://ftp.wu-wien.ac.at/pub/src/Editors/THE/

MAINTAINER=	ports@FreeBSD.org

BUILD_DEPENDS=	rexx:${PORTSDIR}/lang/rexx-imc

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-rexximc --with-ncurses

.include <bsd.port.mk>
