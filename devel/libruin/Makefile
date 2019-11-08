# Created by: ijliao
# $FreeBSD$

PORTNAME=	libruin
PORTVERSION=	0.2.0
PORTREVISION=	2
CATEGORIES=	devel scheme
MASTER_SITES=	SAVANNAH

MAINTAINER=	ndowens@yahoo.com
COMMENT=	Renderer for User Interfaces in Ncurses

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

NOT_FOR_ARCHS=	mips
NOT_FOR_ARCHS_REASON=	glib needs gcc7(Not available for mips)

BUILD_DEPENDS=	guile-lib>0:devel/guile-lib
LIB_DEPENDS=	libguile-2.2.so:lang/guile2 \
		libgc-threaded.so:devel/boehm-gc-threaded
RUN_DEPENDS=	guile-lib>0:devel/guile-lib

GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
USES=		gnome libtool ncurses pkgconfig
USE_GNOME=	glib20
USE_LDCONFIG=	yes

INFO=	libruin

OPTIONS_DEFINE=	DOCS EXAMPLES

PORTDOCS=	ChangeLog
PORTEXAMPLES=	css21-conformance-uris.txt ruinview.c

post-patch:
# XXX: must remove spaces from the PACKAGE_STRING because of this:
# http://git.savannah.gnu.org/cgit/guile.git/commit/libguile/guile-snarf.in?id=f775ab3654357fcaad294b95efb0b1c16de1eda8 (yes, it's a bug in the new guile)
	@${REINPLACE_CMD} -e 's,guile-2\.0,guile-2.2,' \
		-e '/^PACKAGE_STRING=/s, ,-,' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's,@appendixsubsec,@appendixsec,' \
		${WRKSRC}/doc/fdl.texi

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
