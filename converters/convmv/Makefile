# New ports collection makefile for:	convmv
# Date created:		27 October 2004
# Whom:			Kuang-che Wu <kcwu@csie.org>
#
# $FreeBSD$
#

PORTNAME=	convmv
PORTVERSION=	1.14
CATEGORIES=	converters perl5
MASTER_SITES=	http://www.j3e.de/linux/convmv/ \
		http://www.sfr-fresh.com/unix/privat/

MAINTAINER=	kcwu@csie.org
COMMENT=	Convert filenames from one encoding to another

USE_PERL5=	yes
PLIST_FILES=	bin/convmv

MAN1=		convmv.1

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500701
RUN_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/Encode.pm:${PORTSDIR}/converters/p5-Encode
.endif

.include <bsd.port.post.mk>
