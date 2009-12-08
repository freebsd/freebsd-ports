# New ports collection makefile for: aunit
# Date created:		31 Dec 2006
# Whom:			John Merryweather Cooper
#
#  $FreeBSD$
#

PORTNAME=	aunit
PORTVERSION=	1.05
CATEGORIES=	devel
MASTER_SITES=	http://libre.adacore.com/
DISTFILES=	${PORTNAME}-${PORTVERSION}-src.tgz

MAINTAINER=	john_m_cooper@yahoo.com
COMMENT=	AUnit is an adaption of the Java JUnit unit test framework

BUILD_DEPENDS=	gnatmake:${PORTSDIR}/lang/gnat
RUN_DEPENDS=	gnatgcc:${PORTSDIR}/lang/gnat

BROKEN=		does not build
DEPRECATED=	has been broken for 3 months
EXPIRATION_DATE=2010-01-08

USE_GMAKE=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}-src

.include <bsd.port.pre.mk>

# Check for GNAT sources.
.if !exists(${DISTDIR}/${DISTFILES}) && !defined(PACKAGE_BUILDING)
pre-everything::
	@echo "Because of licensing and registration restrictions, you must"
	@echo "fetch the source distribution manually.  Please access"
	@echo "http://libre.adacore.com/ with a web browser, register"
	@echo "(It's free!) and log in.  Download the source files:"
	@echo
	@echo "	${DISTFILES}"
	@echo
	@echo "and place them in ${DISTDIR}"
	@exit 1
.endif

pre-build:
	@${MV} ${WRKSRC}/makefile ${WRKSRC}/Makefile

# install-info is being called directly because aunit.info does not have an
# entry field
post-install:
	@install-info --entry "AUnit" ${DOCSDIR}/aunit.info \
		${DOCSDIR}/dir

test:
	@${CD} ${WRKSRC} && ${GMAKE} test

.include <bsd.port.post.mk>
