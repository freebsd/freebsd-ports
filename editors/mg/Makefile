# Created by: Dima Dorfman <dima@unixfreak.org>
# $FreeBSD$

PORTNAME=	mg
PORTVERSION=	20180408
CATEGORIES=	editors

MAINTAINER=	tobik@FreeBSD.org
COMMENT=	Small, fast Emacs-like editor

LICENSE=	PD

USES=		ncurses
USE_GITHUB=	yes
GH_ACCOUNT=	hboetes
PLIST_FILES=	bin/mg man/man1/mg.1.gz
PORTDOCS=	README tutorial

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

.if ${OPSYS} != FreeBSD || ${OSVERSION} < 1100072
EXTRA_PATCHES=	${FILESDIR}/extra-patch-def.h

post-patch:
	${CP} ${FILESDIR}/reallocarray.c ${WRKSRC}
	@${REINPLACE_CMD} 's| tags.c| tags.c reallocarray.c|' ${WRKSRC}/Makefile
.endif

pre-configure:
	@${REINPLACE_CMD} 's|-lcurses|-lncurses|' ${WRKSRC}/Makefile
	@${REINPLACE_CMD} 's|__dead|__dead2|' ${WRKSRC}/main.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN}  ${WRKSRC}/${PORTNAME}.1 ${STAGEDIR}${MAN1PREFIX}/man/man1

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
