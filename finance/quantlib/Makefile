# ex:ts=8
# New ports collection makefile for:	quantlib
# Date created:			Aug 12, 2001
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	quantlib
PORTVERSION=	0.3.5
CATEGORIES=	finance
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	QuantLib-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A comprehensive software framework for quantitative finance

WRKSRC=		${WRKDIR}/QuantLib-${PORTVERSION}

USE_REINPLACE=	yes
USE_GCC=	3.3
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	LDFLAGS="${PTHREAD_LIBS}"
INSTALLS_SHLIB=	yes

MAN1=	quantlib-config.1 quantlib-test-suite.1
PLIST_FILES=	bin/quantlib-config \
		lib/libQuantLib.a \
		lib/libQuantLib.so \
		lib/libQuantLib.so.0 \
		share/aclocal/quantlib.m4

post-install:
	@${FIND} ${PREFIX}/include/ql -type f | \
		${SED} 's,^${PREFIX}/,,' >> ${TMPPLIST}
	@${FIND} ${PREFIX}/include/ql -type d | ${SORT} -r | \
		${SED} 's,^${PREFIX}/,@dirrm ,' >> ${TMPPLIST}

.include <bsd.port.mk>
