# New ports collection makefile for:	agenda-libs
# Date created:		14 June 2001
# Whom:			Lev Serebryakov <lev@serebryakov.spb.ru>
#
# $FreeBSD$
#

PORTNAME=	agenda-libs
PORTVERSION=	1.0
CATEGORIES=	devel
MASTER_SITES=	http://lev.serebryakov.spb.ru/download/agenda/

MAINTAINER=	lev@serebryakov.spb.ru

RUN_DEPENDS=	${LOCALBASE}/${TARGET_PLATFORM}/include/stdio.h:${PORTSDIR}/devel/agenda-headers

TARGET_PLATFORM=mipsel-linux
USE_BZIP2=	yes
NO_FILTER_SHLIBS=	yes

LIBC_SUB=	PREFIX=${PREFIX} TARGET_PLATFORM=${TARGET_PLATFORM}

do-build:
	@${SED} ${LIBC_SUB:S/$/!g/:S/^/ -e s!%%/:S/=/%%!/} < ${WRKSRC}/lib/libc.so > ${WRKSRC}/lib/libc.so.new
	@${MV} ${WRKSRC}/lib/libc.so.new ${WRKSRC}/lib/libc.so

do-install:
	(cd ${WRKSRC} && tar --exclude '*.orig' -cf - *) \
		| (cd ${PREFIX}/${TARGET_PLATFORM} && tar xf -)
.include <bsd.port.mk>
