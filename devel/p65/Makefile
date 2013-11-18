# Created by: ijliao
# $FreeBSD$

PORTNAME=	p65
PORTVERSION=	1.1
CATEGORIES=	devel
MASTER_SITES=	https://hkn.eecs.berkeley.edu/~mcmartin/P65/pl/
EXTRACT_SUFX=	# empty

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An assembler for the 6502 microprocessor

EXTRACT_CMD=	${CP}
EXTRACT_BEFORE_ARGS=	# empty
EXTRACT_AFTER_ARGS=	${WRKSRC}
USES=		dos2unix perl5 shebangfix
SHEBANG_FILES=	${DISTNAME}
NO_WRKSUBDIR=	yes
NO_BUILD=	yes
PLIST_FILES=	bin/p65

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${DISTNAME} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
