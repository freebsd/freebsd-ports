PORTNAME=	autoconf
PORTVERSION=	20220527
CATEGORIES=	devel
MASTER_SITES=	# none
PKGNAMESUFFIX=	-switch
DISTFILES=	# none

MAINTAINER=	tijl@FreeBSD.org
COMMENT=	Wrapper script to switch between autoconf versions

LICENSE=	BSD2CLAUSE

NO_ARCH=	yes
NO_BUILD=	yes

do-install:
	${INSTALL_SCRIPT} ${FILESDIR}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/
.for l in autoheader autom4te autoreconf autoscan autoupdate ifnames
	${LN} ${STAGEDIR}${PREFIX}/bin/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/${l}
.endfor

.include <bsd.port.mk>
