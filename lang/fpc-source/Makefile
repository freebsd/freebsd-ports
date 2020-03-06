# $FreeBSD$

PORTNAME=	fpc
PORTVERSION=	3.0.4
PORTREVISION=	2
DISTVERSIONSUFFIX=.source
CATEGORIES=	lang
MASTER_SITES=	ftp://ftp.freepascal.org/pub/fpc/dist/${PORTVERSION}/source/ \
		ftp://planetmirror.com/pub/fpc/dist/${PORTVERSION}/source/ \
		ftp://ftp.jp.freepascal.org/mirror/fpc/dist/${PORTVERSION}/source/ \
		ftp://freepascal.stack.nl/pub/fpc/dist/${PORTVERSION}/source/ \
		ftp://ftp.no.freepascal.org/pub/fpc/dist/${PORTVERSION}/source/ \
		ftp://ftp.us.freepascal.org/pub/fpc/dist/${PORTVERSION}/source/ \
		SF/freepascal/Source/${PORTVERSION}
PKGNAMESUFFIX=  -source
DIST_SUBDIR=	freepascal

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Free Pascal compiler with Turbo and Delphi (source)

ONLY_FOR_ARCHS=	amd64 i386
NO_BUILD=	yes

PORTDATA=	*

PATCHDIR=	${PORTSDIR}/lang/fpc/files
DATADIR=	${PREFIX}/share/${PORTNAME}${PKGNAMESUFFIX}-${PORTVERSION}
WRKSRC=		${WRKDIR}/${PORTNAME}-${DISTVERSION}

do-install:
	(cd ${WRKSRC} && ${COPYTREE_SHARE} . \
		${STAGEDIR}${DATADIR})

.include <bsd.port.mk>
