# New ports collection makefile for:	cu-Prolog
# Date created:		7 July 1999
# Whom:			Issei Suzuki <issei@jp.FreeBSD.ORG>
#
# $FreeBSD$
#

PORTNAME=	cu-prolog
PORTVERSION=	3.94
CATEGORIES=	lang
MASTER_SITES=	ftp://ftp.icot.or.jp/ifs/kbms-clp/unix/cuprolog/
DISTFILES=	${DISTNAME}.tar.gz cupdoc.tar.gz
DISTNAME=	cupsrc

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Experimental constraint logic programming language

WRKSRC=		${WRKDIR}/src
MAKEFILE=	makefile
ALL_TARGET=	cup
MYPORTDOCS=	CHANGES COPYRIGHT COPYRIGHT.j INSTALL INSTALL.j README \
		README.j doc/cu3eman.dvi doc/cu3man.dvi doc/newpred_e.doc \
		doc/newpred_j.doc

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/cup3 ${PREFIX}/bin/cuprolog
	${MKDIR} ${PREFIX}/share/examples/cu-prolog
	${INSTALL_DATA} ${WRKDIR}/sample/* ${PREFIX}/share/examples/cu-prolog
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/cu-prolog
.for i in ${MYPORTDOCS}
	${INSTALL_DATA} ${WRKDIR}/$i ${PREFIX}/share/doc/cu-prolog
.endfor
.endif

.include <bsd.port.mk>
