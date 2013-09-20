# Created by: Ryan Steinmetz <zi@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libcidr
DISTVERSION=	1.2.1
CATEGORIES=	devel
MASTER_SITES=	http://www.over-yonder.net/~fullermd/projects/${PORTNAME}/ \
		http://distfiles.over-yonder.net/${PORTNAME}/ \
		http://mirrors.rit.edu/zi/

MAINTAINER=	zi@FreeBSD.org
COMMENT=	A library to handle manipulating CIDR netblocks

LICENSE=	BSD
LICENSE_FILE=	${WRKSRC}/LICENSE

USE_XZ=		yes
USE_LDCONFIG=	yes
MAKE_ENV+=	CIDR_DOCDIR=${DOCSDIR} CIDR_EXDIR=${EXAMPLESDIR}

MAN3=		libcidr.3

.if defined(NOPORTDOCS)
MAKE_ENV+=	NO_DOCS=yes
.endif

.if defined(NOPORTEXAMPLES)
MAKE_ENV+=	NO_EXAMPLES=yes
.endif

NO_STAGE=	yes
.include <bsd.port.mk>
