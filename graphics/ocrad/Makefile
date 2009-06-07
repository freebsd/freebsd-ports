# New ports collection makefile for:	graphics/ocrad
# Date created:				12.11.2003
# Whom:					Ulrich Spoerlein <q@uni.de>
#
# $FreeBSD$
#

PORTNAME=	ocrad
PORTVERSION=	0.18
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	lippe@FreeBSD.org
COMMENT=	OCR program implemented as filter

HAS_CONFIGURE=	yes

CONFIGURE_ARGS=	--prefix=${PREFIX} CXXFLAGS="${CXXFLAGS}" CXX="${CXX}"
CXXFLAGS+=	-Wall -W
MAKE_ARGS=	-j`${SYSCTL} -n hw.ncpu`

DOCS=		AUTHORS COPYING ChangeLog NEWS README TODO INSTALL
EXAMPLES=	test.pbm test.txt check.sh
MAN1=		ocrad.1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ocrad ${PREFIX}/bin/
	${INSTALL_MAN} ${WRKSRC}/doc/ocrad.1 ${MAN1PREFIX}/man/man1/
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${DOCS:S,^,${WRKSRC}/,} ${DOCSDIR}/
.endif
.if !defined(NOPORTEXAMPLES)
	@${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${EXAMPLES:S,^,${WRKSRC}/testsuite/,} ${EXAMPLESDIR}/
.endif

.include <bsd.port.mk>
