# New ports collection makefile for:	cint
# Date created:				21 Aug 2007
# Whom:					Max Khon <fjoe@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	cint
PORTVERSION=	5.16.19
DISTVERSIONSUFFIX=	-source
PORTREVISION=	1
CATEGORIES=	lang
MASTER_SITES=	ftp://root.cern.ch/root/

MAINTAINER=	fjoe@FreeBSD.org
COMMENT=	C/C++ interpreter

BUILD_DEPENDS=	bash:${PORTSDIR}/shells/bash

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
HAS_CONFIGURE=	yes
USE_GMAKE=	yes
USE_LDCONFIG=	${PREFIX}/lib/cint
ALL_TARGET=
MAN1=		cint.1 makecint.1

INSTALL_ARGS=	--bindir=${PREFIX}/bin  \
		--libdir=${PREFIX}/lib/cint \
		--mandir=${PREFIX}/man

.if !defined(NOPORTDOCS)
INSTALL_ARGS+=	--docdir=${DOCSDIR}
.endif

do-configure:
	cd ${WRKSRC} && ${LOCALBASE}/bin/bash configure __have_the_proper_shell@

do-install:
	cd ${WRKSRC} && ${LOCALBASE}/bin/bash tool/INSTALLBIN ${INSTALL_ARGS}

.include <bsd.port.mk>
