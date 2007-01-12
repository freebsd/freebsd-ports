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
EXTRACT_SUFX=	-src.tgz

MAINTAINER=	john_m_cooper@yahoo.com
COMMENT=	AUnit is an adaption of the Java JUnit unit test framework

BUILD_DEPENDS=	gnatmake:${PORTSDIR}/lang/gnat
RUN_DEPENDS=	gnatgcc:${PORTSDIR}/lang/gnat

USE_GMAKE=	yes

# Check for GNAT sources.
.if !exists(${DISTDIR}/${DISTFILE}) && !defined(PACKAGE_BUILDING)
ECHO_MSG=	${PRINTF}
IGNORE=Because of licensing and registration restrictions, you must fetch\n \
	the source distribution manually.  Please access\n \
	http://libre.adacore.com/\ with a web browser, register\n \
	(It's free!) and log in.  Download the source files:\n\n \
	\t${DISTFILE}\n\n \
	and place them in ${DISTDIR}\n
	${ECHO_MSG} ${IGNORE}
.endif

WRKSRC=		${WRKDIR}/aunit-${PORTVERSION}-src

pre-build:
	@${MV} ${WRKSRC}/makefile ${WRKSRC}/Makefile

# install-info is being called directly because aunit.info does not have an
# entry field
post-install:
	@install-info --entry "AUnit" ${DOCSDIR}/aunit.info \
		${DOCSDIR}/dir

test:
	@${CD} ${WRKSRC} && ${GMAKE} test

.include <bsd.port.mk>
