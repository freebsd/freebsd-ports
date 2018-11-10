# Created by: ijliao
# $FreeBSD$

PORTNAME=	libruin
PORTVERSION=	0.2.0
PORTREVISION=	1
CATEGORIES=	devel scheme
MASTER_SITES=	SAVANNAH

MAINTAINER=	ndowens@yahoo.com
COMMENT=	Renderer for User Interfaces in Ncurses

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

NOT_FOR_ARCHS=	mips
NOT_FOR_ARCHS_REASON=	glib needs gcc7(Not available for mips)

BUILD_DEPENDS=	guile-lib>0:devel/guile-lib
LIB_DEPENDS=	libguile-2.0.so:lang/guile2 \
		libgc-threaded.so:devel/boehm-gc-threaded
RUN_DEPENDS=	guile-lib>0:devel/guile-lib

GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
USES=		libtool ncurses pkgconfig
USE_GNOME=	glib20
USE_LDCONFIG=	yes

INFO=	libruin

OPTIONS_DEFINE=	DOCS EXAMPLES

PORTDOCS=	ChangeLog
PORTEXAMPLES=	css21-conformance-uris.txt ruinview.c

post-configure:
	# Avoid compiling examples, which fails to compile
	# As the examples needs the library to be already installed
	${REINPLACE_CMD} -e '/^SUBDIRS/s,examples,,' ${WRKSRC}/Makefile

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC}/doc && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR})

do-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	(cd ${WRKSRC}/examples && ${INSTALL_DATA} ${PORTEXAMPLES} ${STAGEDIR}${EXAMPLESDIR})

.include <bsd.port.mk>
