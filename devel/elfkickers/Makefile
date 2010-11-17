# New ports collection makefile for:	elfkickers
# Date created:		2010-11-16
# Whom:			Sofian Brabez <sbrabez@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	elfkickers
DISTVERSION=	2.0a
CATEGORIES=	devel sysutils
MASTER_SITES=	http://www.muppetlabs.com/~breadbox/pub/software/
DISTNAME=	ELFkickers-${DISTVERSION}

MAINTAINER=	sbrabez@gmail.com
COMMENT=	Collection of programs to manipulate ELF files

USE_GMAKE=	yes

PLIST_FILES=	bin/ebfc \
		bin/elfls \
		bin/elftoc \
		bin/rebind \
		bin/sstrip

PORTDOCS=	COPYING Changelog README

MAN1=		ebfc.1 elfls.1

WRKSRC=		${WRKDIR}/ELFkickers

post-patch:
	@${GREP} -lR "\/elf.h>" ${WRKSRC} | ${XARGS} ${REINPLACE_CMD} -e \
		's,linux/,,g' -e 's,asm/,,g'

do-build:
.for f in ${PLIST_FILES:S,bin/,,}
	@(cd ${WRKSRC}/$f; ${GMAKE})
.endfor

do-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${DOCSDIR}
.endif
.for f in ${PLIST_FILES:S,bin/,,}
	${INSTALL_SCRIPT} ${WRKSRC}/${f}/${f} ${PREFIX}/bin
.endfor
.for f in ${MAN1}
	${INSTALL_MAN} ${WRKSRC}/${f:S,.1,,}/${f} ${PREFIX}/man/man1
.endfor

.include <bsd.port.mk>
