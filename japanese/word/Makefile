# New ports collection makefile for: word
# Date created:		30 August 1999
# Whom:			sada
#
# $FreeBSD$
#

PORTNAME=	word
PORTVERSION=	0.99.12
CATEGORIES=	japanese
MASTER_SITES=	http://www.linet.gr.jp/~mituiwa/

MAINTAINER=	sada@FreeBSD.ORG

LIB_DEPENDS=	gtk12.2:${PORTSDIR}/x11-toolkits/gtk12

DOCDIR=		${PREFIX}/share/doc/ja-word
EXAMPLEDIR=	${PREFIX}/share/examples/ja-word

do-build:
	(cd ${WRKSRC}; \
	 ${CC} -o word `gtk12-config --cflags` `gtk12-config --libs` word.c )

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/word ${PREFIX}/bin
	${MKDIR} ${DOCDIR}
.for i in Changes LICENSE README
	${INSTALL_DATA} ${WRKSRC}/$i ${DOCDIR}
.endfor
	${MKDIR} ${EXAMPLEDIR}
.for i in default-wordfontrc ricoh-VFlib.ps ricoh-wordfontrc vine-VFlib.ps vine-wordfontrc
	${INSTALL_DATA} ${WRKSRC}/config/$i ${EXAMPLEDIR}
.endfor

.include <bsd.port.mk>
