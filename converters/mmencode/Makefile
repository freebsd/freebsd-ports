# Created by: kbyanc
# $FreeBSD$

PORTNAME=	mmencode
PORTVERSION=	2.7
CATEGORIES=	converters
MASTER_SITES=	ftp://ftp.delegate.org/pub/mime/mm2.7/ \
		ftp://ftp.funet.fi/pub/unix/mail/metamail/
DISTNAME=	mm${PORTVERSION}
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	johans@FreeBSD.org
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
