# ex:ts=8
# Ports collection makefile for:	libgenome
# Date created:			Jul 30, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	libgenome
PORTVERSION=	0.5.2
CATEGORIES=	biology
MASTER_SITES=	http://www.cs.wisc.edu/~darling/libgenome/releases/
DISTNAME=	libGenome-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Toolkit for developing bioinformatic related software in C++

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
USE_REINPLACE=	yes
USE_LIBTOOL_VER=15
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
INSTALLS_SHLIB=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|-O2|@CXXFLAGS@|g' ${WRKSRC}/src/Makefile.in

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/html/*.css ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/html/*.png ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/html/*.html ${DOCSDIR}
.endif

.include <bsd.port.mk>
