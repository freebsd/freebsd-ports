# Created by: Janni <jannisan@t-online.de>
# $FreeBSD$

PORTNAME=	Atlas
PORTVERSION=	0.6.3
CATEGORIES=	devel
MASTER_SITES=	SF/worldforge/${PORTNAME}-C%2B%2B%20%28protocol%20lib%29/${PORTVERSION}
DISTNAME=	${PORTNAME}-C++-${PORTVERSION:S/.r/rc/}

MAINTAINER=	oliver@FreeBSD.org
COMMENT=	A C++ reference implementation of the Atlas protocol

PKGNAMESUFFIX=	-devel
GNU_CONFIGURE=	yes
USE_LDCONFIG=	YES
USE_BZIP2=	YES
USES=	pathfix
USE_GCC=	4.7+

CONFIGURE_ARGS+=--program-transform-name=

NO_STAGE=	yes
post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for docfile in README COPYING AUTHORS THANKS NEWS ChangeLog TODO HACKING ROADMAP
	@${INSTALL_DATA} ${WRKSRC}/${docfile} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
