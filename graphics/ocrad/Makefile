# New ports collection makefile for:	graphics/ocrad
# Date created:				12.11.2003
# Whom:					Ulrich Spoerlein <q@uni.de>
#
# $FreeBSD$
#

PORTNAME=	ocrad
PORTVERSION=	0.17
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	lippe@FreeBSD.org
COMMENT=	OCR program implemented as filter

USE_BZIP2=	yes
HAS_CONFIGURE=	yes
USE_GMAKE=	yes
USE_GETOPT_LONG=	yes

CONFIGURE_ARGS=	--prefix=${PREFIX}
MAKE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}" \
		CXX="${CXX}"

DOCS=		AUTHORS COPYING ChangeLog NEWS README TODO INSTALL
EXAMPLES=	test.pbm test.txt
INFO=		ocrad
MAN1=		ocrad.1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ocrad ${PREFIX}/bin/
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${DOCS:S,^,${WRKSRC}/,} ${DOCSDIR}/
	${INSTALL_DATA} ${WRKSRC}/doc/ocrad.info ${PREFIX}/${INFO_PATH}/
	${INSTALL_MAN} ${WRKSRC}/doc/ocrad.1 ${MAN1PREFIX}/man/man1/
.endif
.if !defined(NOPORTEXAMPLES)
	@${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${EXAMPLES:S,^,${WRKSRC}/examples/,} ${EXAMPLESDIR}/
.endif

.include <bsd.port.mk>
