# New ports collection makefile for: florist-gpl
# Date created:		31 Dec 2006
# Whom:			John Merryweather Cooper
#
# $FreeBSD$
#

PORTNAME=	florist-gpl
PORTVERSION=	2006
CATEGORIES=	devel
MASTER_SITES=	http://libre.adacore.com/
EXTRACT_SUFX=	-src.tgz

MAINTAINER=	john_m_cooper@yahoo.com
COMMENT=	The POSIX Ada Binding

BUILD_DEPENDS=	gnatmake:${PORTSDIR}/lang/gnat

GNU_CONFIGURE=	yes
CFLAGS+=	${PTHREAD_CFLAGS}
CONFIGURE_ENV=	CFLAGS="${CFLAGS}" \
		LIBS="${PTHREAD_LIBS}"

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

WRKSRC=		${WRKDIR}/florist-${PORTVERSION}-src

.include <bsd.port.mk>
