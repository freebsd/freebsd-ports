# Created by: ijliao
# $FreeBSD$

PORTNAME=	libgenome
PORTVERSION=	0.5.2
PORTREVISION=	2
CATEGORIES=	biology
MASTER_SITES=	http://pages.cs.wisc.edu/~darling/libgenome/releases/
DISTNAME=	libGenome-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Toolkit for developing bioinformatic related software in C++

LICENSE=	GPLv2

DEPRECATED=	Unmaintained since 2002
EXPIRATION_DATE=	2014-04-17
MAKE_JOBS_UNSAFE=yes

USE_AUTOTOOLS=	libtool
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

OPTIONS_DEFINE=	DOCS

NO_STAGE=	yes
post-patch:
	@${REINPLACE_CMD} -e 's|-O2|@CXXFLAGS@|g' ${WRKSRC}/src/Makefile.in

.include <bsd.port.options.mk>

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/html/*.css ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/html/*.png ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/html/*.html ${DOCSDIR}
.endif

.include <bsd.port.mk>
