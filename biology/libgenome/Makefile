# ex:ts=8
# Ports collection makefile for:	libgenome
# Date created:			Jul 30, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	libgenome
PORTVERSION=	0.5.2
PORTREVISION=	1
CATEGORIES=	biology
MASTER_SITES=	http://pages.cs.wisc.edu/~darling/libgenome/releases/
DISTNAME=	libGenome-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Toolkit for developing bioinformatic related software in C++

USE_AUTOTOOLS=	libtool:22
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

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
