PORTNAME=	asl
PORTVERSION=	1.42.183
CATEGORIES=	devel
MASTER_SITES=	http://john.ccac.rwth-aachen.de:8000/ftp/as/source/c_version/
DISTNAME=	${PORTNAME}-${VERSION}

MAINTAINER=	doconnor@gsoft.com.au
COMMENT=	Assembler for a variety of microcontrollers/-processors

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BROKEN_i386=	typedef redefinition with different types ('unsigned long' vs 'unsigned long long')

ONLY_FOR_ARCHS=	amd64 i386

USES=		alias gmake
MAKE_ARGS+=	INSTROOT=${STAGEDIR}
WRKSRC=		${WRKDIR}/asl-current

VERSION=	current-142-bld183

post-extract:
	${CP} ${FILESDIR}/Makefile.def ${WRKSRC}

.include <bsd.port.mk>
