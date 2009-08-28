# New ports collection makefile for:	p5-Bio-SCF
# Date created:				28 Aug, 2009
# Whom:					Wen Heping <wenheping@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	Bio-SCF
PORTVERSION=	1.01
CATEGORIES=	biology perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	wenheping@gmail.com
COMMENT=	Read and Update SCF Chromatographic Sequence Files

BUILD_DEPENDS=	${LOCALBASE}/include/io_lib/scf.h:${PORTSDIR}/biology/iolib
RUN_DEPENDS=	${BUILD_DEPENDS}

CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

PERL_CONFIGURE=	YES

MAN3=		Bio::SCF.3

.include <bsd.port.mk>
