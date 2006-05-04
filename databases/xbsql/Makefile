# New ports collection makefile for:	xbsql
# Date created:				Nov 22, 2003
# Whom:					Thierry Thomas <thierry@pompo.net>
#
# $FreeBSD$

PORTNAME=	xbsql
PORTVERSION=	0.11
PORTREVISION=	1
CATEGORIES=	databases
MASTER_SITES=	http://www.rekallrevealed.org/packages/
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An SQL wrapper for the XBase DBMS library

LIB_DEPENDS=	xbase-2.0.0:${PORTSDIR}/databases/xbase

USE_BISON=	yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
INSTALLS_SHLIB=	yes

LB2FIX=		Makefile.in test/Makefile.in xbsql/Makefile.in

PORTDOCS=	chap1.html chap2.html chap3.html chap4.html chap5.html	\
		chap6.html chap7.html index.html

post-patch:
.for mkin in ${LB2FIX}
	@${REINPLACE_CMD} -e "s|/usr/local|${LOCALBASE}|g" ${WRKSRC}/${mkin}
.endfor

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for doc in ${PORTDOCS}
	@${INSTALL_DATA} ${WRKSRC}/doc/${doc} ${DOCSDIR}
.endfor
	@${ECHO_MSG} "===> Documentation installed in ${DOCSDIR}."
.endif

.if defined(MAINTAINER_MODE)
test:	install
	@${ECHO_MSG} "Please be patient!"
	(cd ${WRKSRC}/test;	\
	./runtests S001_basic.xql S002_big.pl S004_cross_fast.sh S004_cross_slow.sh;	\
	ls -l *.diff)
.endif

.include <bsd.port.mk>
