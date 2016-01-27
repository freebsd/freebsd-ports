# Created by: Tim Vanderhoek <hoek@FreeBSD.org>
# $FreeBSD$

PORTNAME=	cc65
PORTVERSION=	2.13.3
DISTVERSIONPREFIX=	sources-
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://bj.spline.de/cc65/ \
		http://cc65.oldos.net/ \
		ftp://ftp.musoftware.de/pub/uz/cc65/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Cross-compiler for 6502-based systems, includes 65816 assembler

LICENSE=	ZLIB

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

USES=		gmake perl5 shebangfix tar:bzip2
USE_PERL5=	build
MAKEFILE=	${WRKSRC}/make/gcc.mak
MAKE_JOBS_UNSAFE=yes
SHEBANG_FILES=	src/ca65html/ca65html \
		src/ca65/macpack/cvt-mac.pl \
		src/ld65/cfg/cvt-cfg.pl

SUB_FILES=	pkg-message

OPTIONS_DEFINE=	DOCS EXAMPLES

post-patch:
	@${FIND} ${WRKSRC} -name "gcc.mak" | ${XARGS} ${REINPLACE_CMD} -e \
		'/gcc/s|^CC|#CC| ; \
		/-O2/s|^CFLAGS|#CFLAGS|'
	@${REINPLACE_CMD} -E -e '/^prefix/s|=.*|= $${PREFIX}| ; \
		 /^(docdir|CC65_DOC)/ s|=.*|=| ; \
		 /^INSTALL_DATA/s|=.*|= $${BSD_INSTALL_DATA}| ; \
		 /^INSTALL_PROG/s|=.*|= $${BSD_INSTALL_SCRIPT}| ; \
		 /^INSTALL_STRIP/s|=.*|= $${BSD_INSTALL_PROGRAM}| ; \
		 /^all:/s|docs|| ; /^install:/s|install-docs|| ; \
		 s|MKDIR) |&-p $$(DESTDIR)|g ; \
		 /INSTALL_(PROG|STRIP)/ s,bindir),DESTDIR)$$(&,g ; \
		 /INSTALL_DATA/ s,(CA|CC|LD)65_(CFG|INC|HOME|LIB|OBJ),DESTDIR)$$(&,g' \
		${WRKSRC}/make/gcc.mak

# XXX: gmake>=3.82 hack:  beats the hell out of me.  Quick fix.
pre-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/cc65/tgi

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for i in BUGS CREDITS compile.txt internal.txt newvers.txt readme.1st
	${INSTALL_DATA} ${WRKSRC}/doc/${i} ${STAGEDIR}${DOCSDIR}
.endfor
	${INSTALL_DATA} ${WRKSRC}/src/ca65/macpack/*.mac ${STAGEDIR}${DOCSDIR}

post-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	(cd ${WRKSRC}/samples && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR})

.include <bsd.port.mk>
