# New ports collection makefile for: 	fhist
# Date created:				Jan 05 2000
# Whom: 				<jkoshy@freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	fhist
PORTVERSION=	1.10
CATEGORIES=	devel
MASTER_SITES=	http://www.canb.auug.org.au/~millerp/		\
		ftp://ftp.agso.gov.au/pub/Aegis/ 		\
		ftp://ftp.u-aizu.ac.jp/pub/misc/tools/Aegis/	\
		http://gd.tuwien.ac.at/softeng/Aegis/

MAINTAINER=	jkoshy@freebsd.org
COMMENT=	Utilities to maintain file history, do file comparisions and merges

.include <bsd.port.pre.mk>

MAN1=		fcomp.1 fhist.1 fmerge.1
ALL_TARGET=	binaries
INSTALL_TARGET=	install-bin

GNU_CONFIGURE=	yes
CONFIGURE_ARGS= --includedir=${PREFIX}/include

post-extract:
	cd ${WRKSRC}/lib/en/man1 && ${LN} -s ${WRKSRC}/etc/*.so .

post-install:
.for file in fhist fcomp fmerge
	${STRIP_CMD} ${PREFIX}/bin/${file}
	(cd ${WRKSRC}/lib/en/man1; soelim ${file}.1 > tmp; \
	${INSTALL_MAN} tmp ${PREFIX}/man/man1/${file}.1)
.endfor

.include <bsd.port.post.mk>
