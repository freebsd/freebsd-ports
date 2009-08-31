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
DISTFILES=	${PORTNAME}-${PORTVERSION}-src.tgz

MAINTAINER=	john_m_cooper@yahoo.com
COMMENT=	The POSIX Ada Binding

BUILD_DEPENDS=	gnatmake:${PORTSDIR}/lang/gnat

BROKEN=		does not build

GNU_CONFIGURE=	yes
CFLAGS+=	${PTHREAD_CFLAGS}
CONFIGURE_ENV=	CFLAGS="${CFLAGS}" \
		LIBS="${PTHREAD_LIBS}"
WRKSRC=		${WRKDIR}/florist-${PORTVERSION}-src

.include <bsd.port.pre.mk>

# Check for GNAT sources.
.if !exists(${DISTDIR}/${DISTFILES}) && !defined(PACKAGE_BUILDING)
pre-everything::
	@echo "Because of licensing and registration restrictions, you must"
	@echo "fetch the source distribution manually.  Please access"
	@echo "http://libre.adacore.com/ with a web browser, register"
	@echo "(It's free!) and log in.  Download the source files:"
	@echo
	@echo "	${DISTFILES}
	@echo
	@echo "and place them in ${DISTDIR}"
	@exit 1
.endif

.include <bsd.port.post.mk>
