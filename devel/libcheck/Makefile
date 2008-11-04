# New ports collection makefile for:	libcheck
# Date created:		December 4, 2003
# Whom:			mikeh@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	libcheck
PORTVERSION=	0.9.5
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	SF/check
DISTNAME=	check-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A unit test framework for C

GNU_CONFIGURE=	yes
PLIST_SUB=	CHECK_VERSION=${PORTVERSION}
USE_GMAKE=	yes
USE_LDCONFIG=	yes

DOCSDIR=	${PREFIX}/share/doc/check-${PORTVERSION}
EXAMPLESDIR=	${PREFIX}/share/examples/check-${PORTVERSION}

INFO=		check

post-patch:
.ifdef (NOPORTDOCS)
	@${REINPLACE_CMD} \
		's/^install-data-am: install-docDATA/install-data-am:/' \
		${WRKSRC}/Makefile.in
.endif
.ifdef (NOPORTEXAMPLES)
	@${REINPLACE_CMD} -e \
		's/^\(install-data-am:\) install-exampleDATA install-examplesrcDATA/\1/; \
		s/.*install-exampletestsDATA \(install-info-am\)/\1/' \
		${WRKSRC}/doc/Makefile.in
.endif

.include <bsd.port.mk>
