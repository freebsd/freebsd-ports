# New ports collection makefile for:	orc
# Date created:				Mar 09, 2010
# Whom:					mm
#
# $FreeBSD$

PORTNAME=	orc
PORTVERSION=	0.4.6
CATEGORIES=	devel
MASTER_SITES=	http://code.entropywave.com/download/orc/

MAINTAINER=	mm@FreeBSD.org
COMMENT=	Library and toolset to operate arrays of data

USE_GNOME=	pkgconfig
USE_AUTOTOOLS=	libtool:22
USE_LDCONFIG=	yes
USE_GMAKE=	yes

CONFIGURE_ARGS+=	--disable-gtk-doc

SUBDIRS=	orc orc-test tools

OPTIONS=	DOCS "Include gtk-doc documentation" off \
		EXAMPLES "Install example files" off

.include <bsd.port.pre.mk>

.if defined(WITH_DOCS) && !defined(NOPORTDOCS)
SUBDIRS+=	doc
.else
NOPORTDOCS=	yes
.endif

.if defined(WITH_EXAMPLES) && !defined(NOPORTEXAMPLES)
SUBDIRS+=	examples
.else
NOPORTEXAMPLES=	yes
.endif

MAKE_ARGS+=	SUBDIRS="${SUBDIRS}"

post-patch:
	@${REINPLACE_CMD} \
		-e 's|pkgconfigdir=.*|pkgconfigdir=\"\\$$(prefix)/libdata/pkgconfig\"|g' \
		${WRKSRC}/configure ${WRKSRC}/configure.ac

.include <bsd.port.post.mk>
