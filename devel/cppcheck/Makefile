# New ports collection makefile for:	cppcheck
# Date created:		March 3, 2009
# Whom:	      		Gabor Pali <pgj@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	cppcheck
PORTVERSION=	1.29
CATEGORIES=	devel
MASTER_SITES=	SF

MAINTAINER=	pgj@FreeBSD.org
COMMENT=	Static analysis of C/C++ code

BUILD_DEPENDS=	xsltproc:${PORTSDIR}/textproc/libxslt \
		${LOCALBASE}/share/xsl/docbook/manpages/docbook.xsl:${PORTSDIR}/textproc/docbook-xsl

MANCOMPRESSED=	no
MAN1=		cppcheck.1

USE_GMAKE=	yes
ALL_TARGET=	cppcheck cppcheck.1

PLIST_FILES=	bin/cppcheck

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/cppcheck ${PREFIX}/bin
	@${INSTALL_MAN} ${WRKSRC}/cppcheck.1 ${PREFIX}/man/man1

.include <bsd.port.mk>
