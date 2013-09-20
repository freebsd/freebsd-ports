# Created by: Sofian Brabez <sbrabez@gmail.com>
# $FreeBSD$

PORTNAME=	elfkickers
PORTVERSION=	3.0
PORTREVISION=	1
CATEGORIES=	devel sysutils
MASTER_SITES=	http://www.muppetlabs.com/~breadbox/pub/software/
DISTNAME=	ELFkickers-${PORTVERSION}

MAINTAINER=	sbz@FreeBSD.org
COMMENT=	Collection of programs to manipulate ELF files

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USE_GMAKE=	yes

PLIST_FILES=	bin/ebfc \
		bin/elfls \
		bin/elftoc \
		bin/infect \
		bin/objres \
		bin/rebind \
		bin/sstrip

PORTDOCS=	COPYING Changelog README

MAN1=		ebfc.1 elfls.1 elftoc.1 infect.1 objres.1 rebind.1 sstrip.1

NO_STAGE=	yes
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
