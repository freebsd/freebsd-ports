# New ports collection makefile for:	orc
# Date created:				Mar 09, 2010
# Whom:					mm
#
# $FreeBSD$

PORTNAME=	orc
PORTVERSION=	0.4.16
CATEGORIES=	devel
MASTER_SITES=	http://code.entropywave.com/download/orc/

MAINTAINER=	mm@FreeBSD.org
COMMENT=	Library and toolset to operate arrays of data

LICENSE=	BSD
LICENSE_FILE=	${WRKSRC}/COPYING

USE_GNOME=	pkgconfig
USE_AUTOTOOLS=	libtool
USE_LDCONFIG=	yes
USE_GMAKE=	yes

CONFIGURE_ARGS+=	--disable-gtk-doc

SUBDIRS=	orc orc-test tools

EXAMPLES_DATA=	example1orc.orc example2orc.orc example3orc.orc \
		mt19937arorc.orc
EXAMPLES_EXEC=	example1 example2 example3 mt19937ar volscale

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
		-E -e '/LIBS/s/-lrt(\ )*//; /LIBRT/s/-lrt//' \
		-e 's|pkgconfigdir=.*|pkgconfigdir=\"\\$$(prefix)/libdata/pkgconfig\"|g' \
		${WRKSRC}/configure 

post-install:
.if defined(WITH_EXAMPLES) && !defined(NOPORTEXAMPLES)
	@${MKDIR} ${EXAMPLESDIR}
.for FILE in ${EXAMPLES_DATA}
	@${INSTALL_DATA} ${WRKSRC}/examples/${FILE} ${EXAMPLESDIR}/${FILE}
.endfor
.for FILE in ${EXAMPLES_EXEC}
	@${INSTALL_SCRIPT} ${WRKSRC}/examples/${FILE} ${EXAMPLESDIR}/${FILE}
.endfor
.endif

.include <bsd.port.post.mk>
