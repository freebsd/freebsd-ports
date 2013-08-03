# Created by: Tim Vanderhoek <hoek@FreeBSD.org>
# $FreeBSD$

PORTNAME=	cc65
PORTVERSION=	2.13.3
PORTREVISION=	1
DISTVERSIONPREFIX=	sources-
CATEGORIES=	devel
MASTER_SITES=	http://bj.spline.de/cc65/ \
		http://cc65.oldos.net/ \
		ftp://ftp.musoftware.de/pub/uz/cc65/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Cross-compiler for 6502-based systems, includes 65816 assembler

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

USES=		shebangfix perl5
USE_BZIP2=	yes
USE_PERL5=	build
USE_GMAKE=	yes
MAKEFILE=	${WRKSRC}/make/gcc.mak
MAKE_JOBS_UNSAFE=yes
SHEBANG_FILES=	src/ca65html/ca65html \
		src/ca65/macpack/cvt-mac.pl \
		src/ld65/cfg/cvt-cfg.pl

SUB_FILES=	pkg-message

.include <bsd.port.options.mk>

post-patch:
	@${FIND} ${WRKSRC} -name "gcc.mak" | ${XARGS} ${REINPLACE_CMD} -e \
		'/gcc/s|^CC|#CC| ; \
		/-O2/s|^CFLAGS|#CFLAGS|'
	@${REINPLACE_CMD} -e \
		'/^prefix/s|=.*|= $${PREFIX}| ; \
		 /^docdir/s|=.*|=| ; \
		 /^CC65_DOC/s|=.*|=| ;  \
		 /^INSTALL_DATA/s|=.*|= $${BSD_INSTALL_DATA}| ; \
		 /^INSTALL_PROG/s|=.*|= $${BSD_INSTALL_SCRIPT}| ; \
		 /^INSTALL_STRIP/s|=.*|= $${BSD_INSTALL_PROGRAM}| ; \
		 /^all:/s|docs|| ; \
		 /^install:/s|install-docs||' ${WRKSRC}/make/gcc.mak

# XXX: gmake>=3.82 hack:  beats the hell out of me.  Quick fix.
pre-install:
	@${MKDIR} ${PREFIX}/lib/cc65/tgi

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
.for i in BUGS CREDITS compile.txt internal.txt newvers.txt readme.1st
	${INSTALL_DATA} ${WRKSRC}/doc/${i} ${DOCSDIR}
.endfor
	${INSTALL_DATA} ${WRKSRC}/src/ca65/macpack/*.mac ${DOCSDIR}
.endif
.if ${PORT_OPTIONS:MEXAMPLES}
	@${MKDIR} ${EXAMPLESDIR}
	@(cd ${WRKSRC}/samples && ${COPYTREE_SHARE} . ${EXAMPLESDIR})
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
