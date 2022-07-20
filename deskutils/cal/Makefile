PORTNAME=	cal
DISTVERSION=	4.1
CATEGORIES=	deskutils
MASTER_SITES=	http://unicorn.us.com/pub/
DISTNAME=	${PORTNAME}${DISTVERSION:C/[^0-9]//}

MAINTAINER=	0mp@FreeBSD.org
COMMENT=	Enhanced color version of standard calendar utility

LICENSE=	PD
LICENSE_FILE=	${WRKSRC}/readme.cal

USES=		zip

CFLAGS+=	-DPREFIX='"${ETCDIR}"' -DUSE_REMINDER

PORTDOCS=	readme.cal

CONFLICTS_INSTALL=	util-linux

OPTIONS_DEFINE=	DOCS

do-build:
	${SETENV} ${MAKE_ENV} ${CC} ${CFLAGS} -o ${WRKSRC}/cal ${WRKSRC}/src/cal.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/cal ${STAGEDIR}${PREFIX}/bin/cal
	${INSTALL_MAN}  ${WRKSRC}/src/cal.1 ${STAGEDIR}${MANPREFIX}/share/man/man1
	@${MKDIR} ${STAGEDIR}${ETCDIR}
	${INSTALL_DATA} ${WRKSRC}/cal.col ${STAGEDIR}${ETCDIR}/cal.col.sample
	${INSTALL_DATA} ${WRKSRC}/cal.dat ${STAGEDIR}${ETCDIR}/cal.dat.sample

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/${PORTDOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
