# Created by: Sofian Brabez <sbrabez@gmail.com>
# $FreeBSD$

PORTNAME=	elfkickers
PORTVERSION=	3.1
CATEGORIES=	devel sysutils
MASTER_SITES=	http://www.muppetlabs.com/~breadbox/pub/software/
DISTNAME=	ELFkickers-${PORTVERSION}

MAINTAINER=	sbz@FreeBSD.org
COMMENT=	Collection of programs to manipulate ELF files

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		gmake

ELFBINS=	ebfc elfls elftoc infect objres rebind sstrip
PORTDOCS=	COPYING Changelog README

OPTIONS_DEFINE=	DOCS

post-patch:
	@${GREP} -lR "gcc" ${WRKSRC}/*/Makefile | ${XARGS} \
	${REINPLACE_CMD} -e 's,gcc,${CC},g'

do-build:
.for f in ${ELFBINS}
	@(cd ${WRKSRC}/$f; ${SETENV} ${MAKE_ENV} ${MAKE_CMD})
.endfor

do-install:
.for f in ${ELFBINS}
	${INSTALL_SCRIPT} ${WRKSRC}/${f}/${f} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/${f}/${f:S,$,.1,} ${STAGEDIR}${PREFIX}/man/man1
.endfor

post-install:
.for f in ${ELFBINS}
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${f}
.endfor

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
