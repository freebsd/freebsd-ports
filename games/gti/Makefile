PORTNAME=	gti
PORTVERSION=	1.9.1
DISTVERSIONPREFIX=	v
CATEGORIES=	games

MAINTAINER=	tota@FreeBSD.org
COMMENT=	Just a silly git launcher, basically. Inspired by sl
WWW=		https://r-wos.org/hacks/gti

LICENSE=	GTI
LICENSE_NAME=	MIT-like license
LICENSE_FILE=	${WRKSRC}/README.md
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

USE_GITHUB=	yes
GH_ACCOUNT=	rwos

GTI_SPEED?=	50
CFLAGS+=	-DGTI_SPEED=${GTI_SPEED}

PLIST_FILES=	bin/${PORTNAME} \
		man/man6/${PORTNAME}.6.gz
PORTDOCS=	README.md

OPTIONS_DEFINE=	DOCS

pre-everything::
	@${ECHO_MSG}
	@${ECHO_MSG} " You can change the speed of the car at compile time."
	@${ECHO_MSG} " For example: \"make GTI_SPEED=100\" # default is 50"
	@${ECHO_MSG}

do-build:
	@${CC} ${CFLAGS} -o ${WRKSRC}/${PORTNAME} ${WRKSRC}/${PORTNAME}.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.6 ${STAGEDIR}${MANPREFIX}/man/man6

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/${PORTDOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
