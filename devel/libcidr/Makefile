# New ports collection makefile for:		libcidr
# Date created:					Mar 31 2012
# Whom:						Ryan Steinmetz <zi@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	libcidr
DISTVERSION=	1.1
CATEGORIES=	devel dns
MASTER_SITES=	http://www.over-yonder.net/~fullermd/projects/${PORTNAME}/ \
		http://distfiles.over-yonder.net/${PORTNAME}/ \
		http://mirrors.rit.edu/zi/

MAINTAINER=	zi@FreeBSD.org
COMMENT=	A library to handle manipulating CIDR netblocks

USE_BZIP2=	yes
USE_LDCONFIG=	yes
MAKE_ENV+=	DOCDIR=${DOCSDIR} EXDIR=${EXAMPLESDIR}

MAN3=		libcidr.3.gz

post-patch:
	@${REINPLACE_CMD} -e 's|CC = cc|CC = ${CC}|g' \
		${WRKSRC}/src/Makefile.inc
	@${REINPLACE_CMD} -e 's|/usr/local|${PREFIX}|g' \
		-e 's|LIBDIR|CIDRLIBDIR|g' ${WRKSRC}/Makefile

.if defined(NOPORTDOCS)
MAKE_ENV+=	NO_DOCS=yes
.endif

.if defined(NOPORTEXAMPLES)
MAKE_ENV+=	NO_EXAMPLES=yes
.endif

.include <bsd.port.mk>
