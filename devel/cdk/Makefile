PORTNAME=	cdk
DISTVERSION=	5.0-20230201
PORTEPOCH=	1
CATEGORIES=	devel
MASTER_SITES=	https://invisible-island.net/archives/${PORTNAME}/\
		https://invisible-mirror.net/archives/${PORTNAME}/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Curses Development Kit for speedy development of full screen programs
WWW=		https://invisible-island.net/cdk/

LICENSE=	BSD4CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		gmake ncurses tar:tgz
GNU_CONFIGURE=	yes
PORTDOCS=	README
MAKE_JOBS_UNSAFE=	yes

CONFIGURE_ARGS+=--with-ncurses
ALL_TARGET=	default cdkshlib
INSTALL_TARGET=	install installCDKSHLibrary
USE_LDCONFIG=	yes

OPTIONS_DEFINE=	DOCS EXAMPLES

post-patch:
	@${REINPLACE_CMD} -e 's|gcc|$$(CC)| ; \
		 /^CDKREADME/s| COPYING||' ${WRKSRC}/Makefile.in

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libcdk*.so

post-install-EXAMPLES-on:
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	(cd ${WRKSRC} && \
		${COPYTREE_SHARE} "cli demos examples" \
		${STAGEDIR}${EXAMPLESDIR})

.include <bsd.port.mk>
