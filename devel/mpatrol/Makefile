# New ports collection makefile for:	mpatrol
# Date created:				8 July 2003
# Whom:					Patrick MARIE <mycroft@virgaria.org>
# $FreeBSD$
#

PORTNAME=	mpatrol
PORTVERSION=	1.4.8
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://www.cbmamiga.demon.co.uk/mpatrol/files/
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	mycroft@virgaria.org
COMMENT=	A dynamic memory debugging and profiling library

LIB_DEPENDS=	elf.0:${PORTSDIR}/devel/libelf

WRKSRC=		${WRKDIR}/${PORTNAME}/build/unix

ONLY_FOR_ARCHS=	i386
INSTALLS_SHLIB=	yes

USE_GMAKE=	yes
MAKE_ENV=	LOCALBASE="${LOCALBASE}" CXX="${CXX}" \
		PTHREAD_CFLAGS="${PTHREAD_CFLAGS}" \
		PTHREAD_LIBS="${PTHREAD_LIBS}"

MAN1=		hexwords.1 mleak.1 mpatrol.1 mprof.1 \
		mpsym.1 mptrace.1 mpedit.1
MAN3=		libmpatrol.3 libmpalloc.3

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

do-install:
.for file in hexwords mpedit mpsym mupdate
	${INSTALL_SCRIPT} ${WRKSRC}/../../bin/${file} ${PREFIX}/bin
.endfor
.for file in mpatrol mleak mptrace mprof
	${INSTALL_PROGRAM} ${WRKSRC}/${file} ${PREFIX}/bin
.endfor
.for file in ${MAN1}
	${INSTALL_MAN} ${WRKSRC}/../../man/man1/${file} ${PREFIX}/man/man1
.endfor
.for file in ${MAN3}
	${INSTALL_MAN} ${WRKSRC}/../../man/man3/${file} ${PREFIX}/man/man3
.endfor
.for lib in mpalloc mpatrol mpatrolmt
	${INSTALL_DATA} ${WRKSRC}/lib${lib}.a ${PREFIX}/lib
	${INSTALL_PROGRAM} ${WRKSRC}/lib${lib}.so.1 ${PREFIX}/lib
	${LN} -sf ${PREFIX}/lib/lib${lib}.so.1 ${PREFIX}/lib/lib${lib}.so
.endfor
	${INSTALL_DATA} ${WRKSRC}/libmptools.a ${PREFIX}/lib
.for file in mpatrol.h mpalloc.h mpdebug.h
	${INSTALL_DATA} ${WRKSRC}/../../src/${file} ${PREFIX}/include
.endfor
	${MKDIR} ${PREFIX}/include/mpatrol
	${INSTALL_DATA} ${WRKSRC}/../../tools/*.h ${PREFIX}/include/mpatrol
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/../../doc/${file} ${DOCSDIR}
.endfor
	@${MKDIR} ${DOCSDIR}/images
.for file in ${DOCSIMG}
	${INSTALL_DATA} ${WRKSRC}/../../doc/images/${file} ${DOCSDIR}/images/
.endfor
.endif

.include <bsd.port.mk>
