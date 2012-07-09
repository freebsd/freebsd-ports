# New ports collection makefile for:	libcheck
# Date created:		December 4, 2003
# Whom:			mikeh@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	libcheck
PORTVERSION=	0.9.8
CATEGORIES=	devel
MASTER_SITES=	SF/check/check/${PORTVERSION}
DISTNAME=	check-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	A unit test framework for C

OPTIONS_DEFINE=	DOCS EXAMPLES

GNU_CONFIGURE=	yes
PLIST_SUB=	CHECK_VERSION=${PORTVERSION}
USE_GMAKE=	yes
USE_LDCONFIG=	yes

DOCSDIR=	${PREFIX}/share/doc/check-${PORTVERSION}
EXAMPLESDIR=	${PREFIX}/share/examples/check-${PORTVERSION}
INFO=		check

.include <bsd.port.options.mk>

post-patch:
.if empty(PORT_OPTIONS:MDOCS)
	@${REINPLACE_CMD} \
		-e '/^install-data-am:/ s/ install-docDATA//' \
		${WRKSRC}/Makefile.in
.endif
.if empty(PORT_OPTIONS:MEXAMPLES)
	@${REINPLACE_CMD} \
		-e '/^install-data-am:/ s/ install-exampleDATA//' \
		-e '/^install-data-am:/ s/ install-examplesrcDATA//' \
		-e '/install-exampletestsDATA/ s/install-exampletestsDATA//' \
		${WRKSRC}/doc/Makefile.in
.endif

.include <bsd.port.mk>
