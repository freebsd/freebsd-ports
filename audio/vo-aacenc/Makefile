# New ports collection makefile for:	vo-aacenc
# Date created:		23 Jun 2011
# Whom:			Martin Matuska <mm@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	vo-aacenc
PORTVERSION=	0.1.1
CATEGORIES=	audio
MASTER_SITES=	https://github.com/mstorsjo/${PORTNAME}/tarball/v${PORTVERSION}/
DISTNAME=	mstorsjo-${PORTNAME}-v${PORTVERSION}-0-g${GITVERSION}

MAINTAINER=	mm@FreeBSD.org
COMMENT=	VisualOn AAC encoder library

LICENSE=	ASL
LICENSE_FILE=	${WRKSRC}/COPYING

GITVERSION=	4646ab8
FETCH_ARGS=	-pRr
WRKSRC=		${WRKDIR}/mstorsjo-${PORTNAME}-${GITVERSION}

GNU_CONFIGURE=	yes

USE_AUTOTOOLS=	libtoolize aclocal autoheader autoconf automake
ACLOCAL_ARGS=	-I m4
AUTOCONF_ARGS=	-I m4

.include <bsd.port.pre.mk>

post-patch:
	@${REINPLACE_CMD} -E -e \
	's|^pkgconfigdir = .*|pkgconfigdir = $$(prefix)/libdata/pkgconfig|g' \
	${WRKSRC}/Makefile.am

.include <bsd.port.post.mk>
