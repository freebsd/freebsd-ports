# New ports collection makefile for:	cppi
# Date created:		2006-11-05
# Whom:			trasz <trasz@pin.if.uz.zgora.pl>
#
# $FreeBSD$
#

PORTNAME=	cppi
PORTVERSION=	1.12
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	coreutils

MAINTAINER=	trasz@freebsd.org
COMMENT=	A tool to indent the C preprocessor directives

USE_BZIP2=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--mandir=${PREFIX}/man
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" LIBS="-L${LOCALBASE}/lib"

PLIST_FILES=	bin/cppi
MAN1=		cppi.1

.include <bsd.port.mk>
