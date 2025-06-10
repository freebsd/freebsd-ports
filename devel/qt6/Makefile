PORTNAME=	qt6
DISTVERSION=	${QT6_VERSION}
CATEGORIES=	devel

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Cross-platform application and UI framework (metaport)
WWW=		https://www.qt.io/

USES=		metaport qt:6
USE_QT=		${_USE_QT_ALL:S/$/:run/}

# Generate distinfo for all Qt components
makesum:
	@for component in $$(${MAKE} -V_USE_QT_ALL); do \
	    port=$$(${MAKE} -Vqt-$${component}_PORT | ${SED} -e 's|@.*$$||'); \
	    ${MAKE} -C ${.CURDIR:H:H}/$${port} makesum; \
	done

.include <bsd.port.mk>
