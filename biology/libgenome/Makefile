# ex:ts=8
# Ports collection makefile for:	libgenome
# Date created:			Jul 30, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	libgenome
PORTVERSION=	0.5.0
PORTREVISION=	1
CATEGORIES=	biology
MASTER_SITES=	http://www.libgenome.org/releases/
DISTNAME=	libGenome-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org

USE_REINPLACE=	yes
USE_LIBTOOL=	yes
CONFIGURE_TARGET=	--build=${ARCH}-portbld-freebsd${OSREL}
INSTALLS_SHLIB=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|-O3|@CXXFLAGS@|g' ${WRKSRC}/src/Makefile.in

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/html/*.css ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/html/*.gif ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/html/*.html ${DOCSDIR}
.endif

.include <bsd.port.mk>
