# New ports collection makefile for:	pire
# Date created:		17 Jun 2010
# Whom:			Dmitry Marakasov <amdmi3@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	pire
PORTVERSION=	0.0.4
CATEGORIES=	devel
MASTER_SITES=	http://cloud.github.com/downloads/dprokoptsev/${PORTNAME}/ \
		http://mirror.amdmi3.ru/distfiles/

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Perl Incompatible Regular Expressions library

LICENSE=	LGPL3
LICENSE_FILE=	${WRKSRC}/COPYING

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_LDCONFIG=	yes
MAKE_JOBS_SAFE=	yes

ONLY_FOR_ARCHS=	amd64 i386 ia64
ONLY_FOR_ARCHS_REASON=	"not yet ported to big-endian platforms"

OPTIONS=	UNITTEST "Compile with unittest support" off

.include <bsd.port.options.mk>

.if defined(WITH_UNITTEST) || defined(PACKAGE_BUILDING)
BUILD_DEPENDS+=	cppunit-config:${PORTSDIR}/devel/cppunit
CONFIGURE_ARGS=	--with-cppunit-prefix=${LOCALBASE}

regression-test:
	@(cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} check)
.endif

.include <bsd.port.mk>
