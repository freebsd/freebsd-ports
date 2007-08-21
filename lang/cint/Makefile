# New ports collection makefile for:	cint
# Date created:				21 Aug 2007
# Whom:					Max Khon <fjoe@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	cint
PORTVERSION=	5.16.19
DISTVERSIONSUFFIX=	-source
CATEGORIES=	lang
MASTER_SITES=	ftp://root.cern.ch/root/

MAINTAINER=	fjoe@FreeBSD.org
COMMENT=	C/C++ interpreter

BUILD_DEPENDS=	bash:../../shells/bash

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
HAS_CONFIGURE=	yes
USE_GMAKE=	yes
ALL_TARGET=
MAN1=		cint.1 makecint.1

do-configure:
	cd ${WRKSRC} && ${LOCALBASE}/bin/bash configure __have_the_proper_shell@

do-install:
	cd ${WRKSRC} && ${SH} tool/INSTALLBIN\
	    --bindir=${PREFIX}/bin\
	    --libdir=${PREFIX}/lib/cint\
	    --docdir=${PREFIX}/share/doc/cint\
	    --mandir=${PREFIX}/man

.include <bsd.port.mk>
