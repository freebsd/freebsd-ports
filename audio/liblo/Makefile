PORTNAME=	liblo
PORTVERSION=	0.32
CATEGORIES=	audio
MASTER_SITES=	SF

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Lightweight Open Sound Control implementation
WWW=		https://liblo.sourceforge.net/ \
		https://github.com/radarsat1/liblo

LICENSE=	LGPL21

USES=		compiler:c++11-lang gmake libtool

GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
USE_LDCONFIG=	yes

OPTIONS_DEFINE=	DOCS DOXYGEN EXAMPLES
OPTIONS_SUB=	yes
DOXYGEN_IMPLIES=DOCS

DOXYGEN_BUILD_DEPENDS=	doxygen:devel/doxygen

.include <bsd.port.options.mk>

.if ${ARCH} == i386 || ${ARCH} == powerpc || ${ARCH} == powerpcspe
EXTRA_PATCHES+=	${PATCHDIR}/extra-patch-32bit
.endif

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} AUTHORS ChangeLog NEWS README TODO ${STAGEDIR}${DOCSDIR}

post-install-DOXYGEN-on:
	cd ${WRKSRC}/doc/man/man3 && ${INSTALL_MAN} l*.3 p*.3 ${STAGEDIR}${PREFIX}/share/man/man3/
	cd ${WRKSRC}/doc && ${COPYTREE_SHARE} html ${STAGEDIR}${DOCSDIR}

post-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_PROGRAM} ${WRKSRC}/examples/.libs/* ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
