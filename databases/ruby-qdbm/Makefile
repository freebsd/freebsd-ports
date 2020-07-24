# Created by: Michael Johnson <ahze@FreeBSD.org>
# $FreeBSD$

PORTNAME=	qdbm
PORTVERSION=	1.8.78
PORTREVISION=	4
CATEGORIES=	databases
MASTER_SITES=	https://dbmx.net/qdbm/
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	Ruby API for QDBM

LICENSE=	LGPL21
LICENSE_FILE=	${WRKDIR}/${PORTNAME}-${PORTVERSION}/COPYING

LIB_DEPENDS=	libqdbm.so:databases/qdbm

USES=		iconv shebangfix
SHEBANG_FILES=	curia/rbcrtest depot/rbdptest myrbdoc villa/rbvltest
USE_RUBY=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}/ruby
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
CONFIGURE_ENV=	ac_cv_lib_iconv_main=yes
MAKE_ENV=	CFLAGS="${CFLAGS}" LDFLAGS="${LDFLAGS}" \
		LOCALBASE="${LOCALBASE}"
CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

post-configure:
	cd ${WRKSRC} && ${SETENV} RB_USER_INSTALL=yes ${MAKE_ENV} \
	    ${MAKE} configure

post-install:
	${STRIP_CMD} ${STAGEDIR}${RUBY_SITEARCHLIBDIR}/mod_depot.so \
	    ${STAGEDIR}${RUBY_SITEARCHLIBDIR}/mod_curia.so \
	    ${STAGEDIR}${RUBY_SITEARCHLIBDIR}/mod_villa.so

.include <bsd.port.mk>
