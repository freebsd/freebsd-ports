# New ports collection makefile for:	cu-Prolog
# Date created:		7 July 1999
# Whom:			Issei Suzuki <issei@jp.FreeBSD.ORG>
#
# $FreeBSD$
#

PORTNAME=	cu-prolog
PORTVERSION=	3.94
CATEGORIES=	lang
MASTER_SITES=	ftp://ftp.icot.or.jp/ifs/kbms-clp/unix/cuprolog/ \
		http://mbsd.msk.ru/dist/
DISTNAME=	cupsrc
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} cupdoc${EXTRACT_SUFX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Experimental constraint logic programming language

WRKSRC=		${WRKDIR}/src
MAKEFILE=	makefile
ALL_TARGET=	cup
PORTDOCS=	*
MYPORTDOCS=	CHANGES COPYRIGHT COPYRIGHT.j INSTALL INSTALL.j README \
		README.j doc/cu3eman.dvi doc/cu3man.dvi doc/newpred_e.doc \
		doc/newpred_j.doc

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/cup3 ${PREFIX}/bin/cuprolog
	${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKDIR}/sample/* ${EXAMPLESDIR}
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for i in ${MYPORTDOCS}
	${INSTALL_DATA} ${WRKDIR}/$i ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
