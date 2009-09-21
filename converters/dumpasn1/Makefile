# New ports collection makefile for:	dumpasn1
# Date created:		6 May 2000
# Whom:			kris@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	dumpasn1
PORTVERSION=	20090721
CATEGORIES=	converters security
MASTER_SITES=	http://www.cs.auckland.ac.nz/~pgut001/
DISTFILES=	dumpasn1.c dumpasn1.cfg
DIST_SUBDIR=	${PORTNAME}-${PORTVERSION}
EXTRACT_ONLY=	yes

MAINTAINER=	ale@FreeBSD.org
COMMENT=	Dumps the contents of an ASN.1 encoded file, e.g. an SSL certificate

do-extract:
	@${MKDIR} ${WRKSRC}
	@${CP} ${DISTDIR}/${DIST_SUBDIR}/dumpasn1.c ${WRKSRC}

do-build:
	cd ${WRKSRC} && \
	${CC} ${CFLAGS} -DCONFIG_NAME=\"${PREFIX}/share/dumpasn1/dumpasn1.cfg\" -o dumpasn1 dumpasn1.c

do-install:
	${MKDIR} ${PREFIX}/share/dumpasn1
	${INSTALL_PROGRAM} ${WRKSRC}/dumpasn1 ${PREFIX}/bin
	${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/dumpasn1.cfg ${PREFIX}/share/dumpasn1

.include <bsd.port.mk>
