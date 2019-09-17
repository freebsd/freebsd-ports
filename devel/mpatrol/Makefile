# Created by: Patrick MARIE <mycroft@virgaria.org>
# $FreeBSD$

PORTNAME=	mpatrol
PORTVERSION=	1.4.8
PORTREVISION=	4
CATEGORIES=	devel
MASTER_SITES=	SF
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Dynamic memory debugging and profiling library

ONLY_FOR_ARCHS=	amd64 i386
.if ${/usr/bin/ld:L:tA} == /usr/bin/ld.lld
BROKEN_i386=	ld: error: relocation R_386_PC32 cannot be used against symbol __mp_init
.endif

LIB_DEPENDS=	libelf.so.0:devel/libelf

WRKSRC=		${WRKDIR}/${PORTNAME}/build/unix

USES=		gettext gmake
USE_LDCONFIG=	yes

DOCS=		README mpatrol.dvi mpatrol.guide mpatrol.html mpatrol.info \
		mpatrol.pdf mpatrol.ps mpatrol.texi mpatrol.txt refcard.dvi \
		refcard.pdf refcard.ps refcard.tex source.tex \
		texinfo.tex
DOCSIMG=	cc1.eps cc1.jpg cc1.pdf \
		collect2.eps collect2.jpg collect2.pdf \
		cpp.eps cpp.jpg cpp.pdf \
		gcc.eps gcc.jpg gcc.pdf \
		mpatrol.eps mpatrol.jpg mpatrol.pdf mpatrol.txt \
		test.eps test.jpg test.pdf \
		trace.eps trace.jpg trace.pdf
MAKE_JOBS_UNSAFE=	yes

OPTIONS_DEFINE=	DOCS

.include <bsd.port.pre.mk>

.if ${ARCH} == "amd64"
CFLAGS+=	-DENVIRON=\"ENVIRON_64\" -DMP_INIT_SUPPORT=0
.endif

do-install:
.for file in hexwords mpedit mpsym mupdate
	${INSTALL_SCRIPT} ${WRKSRC}/../../bin/${file} ${STAGEDIR}${PREFIX}/bin
.endfor
.for file in mpatrol mleak mptrace mprof
	${INSTALL_PROGRAM} ${WRKSRC}/${file} ${STAGEDIR}${PREFIX}/bin
.endfor
	${INSTALL_MAN} ${WRKSRC}/../../man/man1/*.1 ${STAGEDIR}${PREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/../../man/man3/*.3 ${STAGEDIR}${PREFIX}/man/man3
.for lib in mpalloc mpatrol mpatrolmt
	${INSTALL_DATA} ${WRKSRC}/lib${lib}.a ${STAGEDIR}${PREFIX}/lib
	${INSTALL_PROGRAM} ${WRKSRC}/lib${lib}.so.1 ${STAGEDIR}${PREFIX}/lib
	${LN} -sf lib${lib}.so.1 ${STAGEDIR}${PREFIX}/lib/lib${lib}.so
.endfor
	${INSTALL_DATA} ${WRKSRC}/libmptools.a ${STAGEDIR}${PREFIX}/lib
.for file in mpatrol.h mpalloc.h mpdebug.h
	${INSTALL_DATA} ${WRKSRC}/../../src/${file} ${STAGEDIR}${PREFIX}/include
.endfor
	@${MKDIR} ${STAGEDIR}${PREFIX}/include/mpatrol
	${INSTALL_DATA} ${WRKSRC}/../../tools/*.h ${STAGEDIR}${PREFIX}/include/mpatrol

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for file in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/../../doc/${file} ${STAGEDIR}${DOCSDIR}
.endfor
	@${MKDIR} ${STAGEDIR}${DOCSDIR}/images
.for file in ${DOCSIMG}
	${INSTALL_DATA} ${WRKSRC}/../../doc/images/${file} ${STAGEDIR}${DOCSDIR}/images/
.endfor

.include <bsd.port.post.mk>
