# Created by: Emanuel Haupt <ehaupt@critical.ch>
# $FreeBSD$

PORTNAME=	pecomato
PORTVERSION=	0.0.15
CATEGORIES=	graphics
MASTER_SITES=	http://www.mollux.org/projects/pecomato/download/sources/ \
		CRITICAL

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Command-line picture metadata processor

USES=			gmake
USE_PYTHON_BUILD=	yes
MAKE_JOBS_SAFE=		yes

MAKEFILE=	Makefile.unix

MAN1=		pecomato.1
PLIST_FILES=	bin/pecomato

post-build:
	${PYTHON} ${WRKSRC}/devtools/txt2tags.py --no-rc -t man \
		-i ${WRKSRC}/doc/manpage.t2t -o ${WRKSRC}/doc/${MAN1}

post-patch:
	@${REINPLACE_CMD} -e '/^CC/d' ${WRKSRC}/${MAKEFILE}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/doc/${MAN1} ${MANPREFIX}/man/man1

.include <bsd.port.mk>
