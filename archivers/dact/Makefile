# ex:ts=8
# New ports collection makefile for:	dact
# Date created:			May 2, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	dact
PORTVERSION=	0.8.42
CATEGORIES=	archivers
MASTER_SITES=	http://www.rkeene.org/files/oss/dact/release/

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	Dynamic Adaptive Compression Tool

LIB_DEPENDS=	mcrypt.8:${PORTSDIR}/security/libmcrypt \
		lzo.1:${PORTSDIR}/archivers/lzo

USE_GMAKE=	yes
GNU_CONFIGURE=	yes
MAKE_JOBS_SAFE=	yes
CONFIGURE_ARGS=	--libdir=${PREFIX}/lib
CONFIGURE_ENV=	CPPFLAGS="${CXXFLAGS} -I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
MAKE_ARGS=	TOBUILD="dact libdact.so dact.conf"

MAN1=		dact.1
USE_LDCONFIG=	yes

post-patch:
	@${REINPLACE_CMD} -e "s|prefix = @prefix@|prefix = ${PREFIX}|" \
	-e "s|libdir = @libdir@|libdir = ${PREFIX}/lib|" \
		${WRKSRC}/Makefile.in

pre-install:
	@${RM} -f ${WRKSRC}/libdact.a

post-install:
.if !defined(NOPORTEXAMPLES)
	@${MKDIR} ${EXAMPLESDIR}
	${CP} -n ${WRKSRC}/dact.conf ${EXAMPLESDIR}
.endif
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/Docs/dact.txt ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif

.include <bsd.port.mk>
