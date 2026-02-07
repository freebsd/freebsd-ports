PORTNAME=	nickle
PORTVERSION=	2.97
PORTREVISION=	1
CATEGORIES=	lang
MASTER_SITES=	http://www.nickle.org/release/

MAINTAINER=	wen@FreeBSD.org
COMMENT=	Numeric-oriented programming language
WWW=		https://www.nickle.org/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		gmake localbase ncurses readline shebangfix

SHEBANG_FILES=	bench/runbench.sh

GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=	${PREFIX}/share
PORTEXAMPLES=	*

# Nickle now has bindings which are likely to pull in libraries that need
# libpthread.  Link to it now explicitly, or it wouldn't work at runtime.
LDFLAGS+=	-pthread

OPTIONS_DEFINE=	EXAMPLES

post-patch:
	@${REINPLACE_CMD} -e '/^SUBDIRS/s|examples|| ; s| -O2||' \
		${WRKSRC}/Makefile.in

post-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${FIND} ${WRKSRC}/examples -name 'Makefile*' -exec ${RM} {} +
	cd ${WRKSRC}/examples && ${COPYTREE_SHARE} . "${STAGEDIR}${EXAMPLESDIR}"

.include <bsd.port.mk>
