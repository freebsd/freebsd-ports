# ex:ts=8
# New ports collection makefile for:	dact
# Date created:			May 2, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	dact
PORTVERSION=	0.8.39
PORTREVISION=	1
CATEGORIES=	archivers
MASTER_SITES=	http://www.rkeene.org/files/oss/dact/release/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Dynamic Adaptive Compression Tool

LIB_DEPENDS=	mcrypt.8:${PORTSDIR}/security/libmcrypt \
		lzo.2:${PORTSDIR}/archivers/lzo
.if !exists(/usr/bin/bzip2)
LIB_DEPENDS+=	bz2.1:${PORTSDIR}/archivers/bzip2
.endif

USE_GETOPT_LONG=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL} \
			--libdir=${PREFIX}/lib
CONFIGURE_ENV=	CPPFLAGS="${CXXFLAGS} -I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

MAN1=		dact.1
INSTALLS_SHLIB=	yes

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/Docs/dact.txt ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif

.include <bsd.port.mk>
