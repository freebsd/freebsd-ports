# New ports collection makefile for:	udis86
# Date created:				7 June 2006
# Whom:					Lutz Boehne <lboehne@damogran.de>
#
# $FreeBSD$
#

PORTNAME=	udis86
PORTVERSION=	1.7
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	bf1783@gmail.com
COMMENT=	Minimalistic x86 and x86-64 disassembler library

GNU_CONFIGURE=	yes

.if !defined(NOPORTDOCS)
PORTDOCS=	index.html ss.jpg style.css udis86.odt udis86.pdf x86optable.xml x86optable.xsl
.else
post-patch:
	${REINPLACE_CMD} -e '/SUBDIRS \=/s/\. docs//' ${WRKSRC}/Makefile.in
.endif

regression-test: build
	@(cd ${WRKSRC} ; ${SETENV} ${MAKE_ENV} ${MAKE} ${_MAKE_JOBS} ${MAKE_ARGS} check)

.include <bsd.port.mk>
