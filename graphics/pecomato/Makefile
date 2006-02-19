# New ports collection makefile for:	pecomato
# Date created:				16 Sep 2005
# Whom:					Emanuel Haupt <ehaupt@critical.ch>
#
# $FreeBSD$
#

PORTNAME=	pecomato
PORTVERSION=	0.0.12
CATEGORIES=	graphics
MASTER_SITES=	http://critical.ch/distfiles/

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	A command-line picture metadata processor

USE_GMAKE=	yes
USE_PYTHON=	yes

MAKEFILE=	Makefile.unix
MAKE_ENV=	CC="${CC}" CFLAGS="${CFLAGS}"

PLIST_FILES=	bin/pecomato
MAN1=		pecomato.1
PORTDOCS=	*

post-patch:
	@${REINPLACE_CMD} -e 's|^\(CC.*\)=|\1?=|; s|^\(all:.*\)|\1 docs|' \
		${WRKSRC}/Makefile.unix
	@${REINPLACE_CMD} -e 's|^\(PYTHON\).*|\1 = ${PYTHON_CMD}|' \
		${WRKSRC}/Makefile.posix.inc
.if !defined(NOPORTDOCS)
	@${REINPLACE_CMD} \
	 	-E 's/^(HTML_DOCS|TXT_DOCS).*=.*(README\.(html|txt)\ TODO\.(html|txt)).*/\1=\2/' \
		${WRKSRC}/doc/Makefile.posix
.else
	@${REINPLACE_CMD} -E '/^(HTML_DOCS|TXT_DOCS)/d' \
		${WRKSRC}/doc/Makefile.posix
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/doc/.man/manpage.man \
		${MANPREFIX}/man/man1/${PORTNAME}.1

.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}/html ${DOCSDIR}/txt
.for f in README TODO
.for t in txt html
	${INSTALL_DATA} ${WRKSRC}/doc/.${t}/${f}.${t} ${DOCSDIR}/${t}
.endfor
.endfor
.endif

.include <bsd.port.mk>
