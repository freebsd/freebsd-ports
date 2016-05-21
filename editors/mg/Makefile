# Created by: Dima Dorfman <dima@unixfreak.org>
# $FreeBSD$

PORTNAME=	mg
PORTVERSION=	20160421
CATEGORIES=	editors
MASTER_SITES=	http://homepage.boetes.org/software/mg/

MAINTAINER=	darcsis@gmail.com
COMMENT=	Small, fast Emacs-like editor

PLIST_FILES=	bin/mg man/man1/mg.1.gz
PORTDOCS=	README tutorial

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

.if ${OSVERSION} < 1002506
BROKEN=	does not build, requires futimens system call
.endif

pre-configure:
	@${REINPLACE_CMD} -e 's|__dead|__dead2|' ${WRKSRC}/main.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN}  ${WRKSRC}/${PORTNAME}.1 ${STAGEDIR}${MAN1PREFIX}/man/man1

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
