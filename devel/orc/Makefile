# Created by: mm
# $FreeBSD$

PORTNAME=	orc
PORTVERSION=	0.4.17
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

OPTIONS_DEFINE=	DOCS EXAMPLES
DOCS_DESC=	Include gtk-doc documentation

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDOCS}
SUBDIRS+=	doc
.else
NOPORTDOCS=	yes
.endif

.if ${PORT_OPTIONS:MEXAMPLES}
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
.if ${PORT_OPTIONS:MEXAMPLES}
	@${MKDIR} ${EXAMPLESDIR}
.for FILE in ${EXAMPLES_DATA}
	@${INSTALL_DATA} ${WRKSRC}/examples/${FILE} ${EXAMPLESDIR}/${FILE}
.endfor
.for FILE in ${EXAMPLES_EXEC}
	@${INSTALL_SCRIPT} ${WRKSRC}/examples/${FILE} ${EXAMPLESDIR}/${FILE}
.endfor
.endif

.include <bsd.port.mk>
