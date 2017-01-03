# Created by: Dima Dorfman <dima@unixfreak.org>
# $FreeBSD$

PORTNAME=	mg
PORTVERSION=	20161005
CATEGORIES=	editors
MASTER_SITES=	http://homepage.boetes.org/software/mg/

MAINTAINER=	t@tobik.me
COMMENT=	Small, fast Emacs-like editor

LICENSE=	PD

USES=		ncurses
PLIST_FILES=	bin/mg man/man1/mg.1.gz
PORTDOCS=	README tutorial

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

.if ${OPSYS} != FreeBSD || (${OSVERSION} >= 1002506 && ${OSVERSION} < 1100072)
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
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
