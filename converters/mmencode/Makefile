# New ports collection makefile for:	mmencode
# Date created:		30 September 1999
# Whom:			kbyanc
#
# $FreeBSD$
#

PORTNAME=	mmencode
PORTVERSION=	2.7
CATEGORIES=	converters
MASTER_SITES=	ftp://wall.etl.go.jp/pub/mime/mm2.7/ \
		ftp://ftp.delegate.org/pub/mime/mm2.7/ \
		ftp://ftp.funet.fi/pub/unix/mail/metamail/
DISTNAME=	mm${PORTVERSION}
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Translate to and from mail-oriented encoding formats

WRKSRC=		${WRKDIR}/${DISTNAME}/src/metamail

PLIST_FILES=	bin/mmencode bin/mimencode
MAN1=		mmencode.1
MLINKS=		mmencode.1 mimencode.1

ALL_TARGET=	mmencode
MAKE_ARGS=	CFLAGS="${CFLAGS}"

do-install:
	@cd ${WRKSRC}		&& ${INSTALL_PROGRAM} mmencode ${PREFIX}/bin
	@cd ${WRKSRC}/../man	&& ${INSTALL_MAN} mmencode.1 ${PREFIX}/man/man1
	@cd ${PREFIX}/bin	&& ${LN} -s mmencode mimencode

.include <bsd.port.mk>
