# Created by: Emanuel Haupt <ehaupt@critical.ch>
# $FreeBSD$

PORTNAME=	pecomato
PORTVERSION=	0.0.15
CATEGORIES=	graphics
MASTER_SITES=	http://www.mollux.org/projects/pecomato/download/sources/ \
		LOCAL/ehaupt

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Command-line picture metadata processor

USES=		gmake python:2.7,build

MAKEFILE=	Makefile.unix

PLIST_FILES=	bin/pecomato man/man1/pecomato.1.gz

post-build:
	${PYTHON_CMD} ${WRKSRC}/devtools/txt2tags.py --no-rc -t man \
		-i ${WRKSRC}/doc/manpage.t2t -o ${WRKSRC}/doc/${PORTNAME}.1

post-patch:
	@${REINPLACE_CMD} -e '/^CC/d' ${WRKSRC}/${MAKEFILE}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/doc/${PORTNAME}.1 \
		${STAGEDIR}${MANPREFIX}/man/man1

.include <bsd.port.mk>
