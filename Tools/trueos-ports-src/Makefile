# $FreeBSD$

# NOTE: This port is created from a template when the 
# <ports_root>/Tools/scripts/set_trueos-ports-src.sh
# script is run at the outset of the build procedures

PORTNAME=	trueos-ports-src
PORTVERSION=	%%CHGVERSION%%
CATEGORIES=	ports-mgmt

MAINTAINER=	ken@ixsystems.com
COMMENT=	TrueOS Ports Tree (sources)

LICENSE=	BSD2CLAUSE

USE_GITHUB=	yes
GH_ACCOUNT=	trueos
GH_PROJECT=	freebsd-ports
GH_TAGNAME=	%%GHTAG%%

NO_BUILD=	yes
NO_ARCH=	yes

do-install:
	@cd ${WRKSRC} \
	&& ${MKDIR} -p "${STAGEDIR}/usr/ports" \
	&& ${CP} -R * "${STAGEDIR}/usr/ports/." \
	&& ${CP} ".arcconfig" "${STAGEDIR}/usr/ports/."

.include <bsd.port.mk>
