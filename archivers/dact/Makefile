# ex:ts=8
# New ports collection makefile for:	dact
# Date created:			May 2, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	dact
PORTVERSION=	0.8.41
PORTREVISION=	0
CATEGORIES=	archivers
MASTER_SITES=	http://www.rkeene.org/files/oss/dact/release/

MAINTAINER=	freebsd@unixfreunde.de
COMMENT=	Dynamic Adaptive Compression Tool

LIB_DEPENDS=	mcrypt.8:${PORTSDIR}/security/libmcrypt \
		lzo.1:${PORTSDIR}/archivers/lzo

USE_GETOPT_LONG=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL} \
			--libdir=${PREFIX}/lib
CONFIGURE_ENV=	CPPFLAGS="${CXXFLAGS} -I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
MAKE_ARGS=	CONF=${EXAMPLESDIR}/dact.conf \
		TOBUILD="dact libdact.so dact.conf"

MAN1=		dact.1
INSTALLS_SHLIB=	yes

pre-install:
	@${MKDIR} ${EXAMPLESDIR}
	@${RM} -f ${WRKSRC}/libdact.a

post-install:
	@${CP} -n ${EXAMPLESDIR}/dact.conf ${PREFIX}/etc
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/Docs/dact.txt ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif

.include <bsd.port.mk>
