# Created by: Dima Dorfman <dima@unixfreak.org>
# $FreeBSD$

PORTNAME=	mg
PORTVERSION=	20110905
CATEGORIES=	editors
MASTER_SITES=	ftp://ftp.SpringDaemons.com/soft/ \
		http://homepage.boetes.org/software/mg/

MAINTAINER=	darcsis@gmail.com
COMMENT=	A small, fast Emacs-like editor

MAN1=	mg.1
MANCOMPRESSED=	no

PLIST_FILES=	bin/mg
PORTDOCS=	README tutorial

HAS_CONFIGURE=	yes

NO_STAGE=	yes
pre-configure:
	@${REINPLACE_CMD} -e 's|-Wno-error=unused-but-set-variable||g' \
		-e '/^CC=/d' -e 's|-g -Wall|-Wall|' -e 's|/usr/local|${PREFIX}|' \
		${WRKSRC}/Makefile.in

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin
	${INSTALL_MAN}  ${WRKSRC}/${PORTNAME}.1 ${MAN1PREFIX}/man/man1
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
