# ex:ts=8
# New ports collection makefile for:	quantlib
# Date created:			Aug 12, 2001
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	quantlib
PORTVERSION=	0.3.0
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	QuantLib-${PORTVERSION}-src

MAINTAINER=	ports@FreeBSD.org

PORTCOMMENT=	A comprehensive software framework for quantitative finance

WRKSRC=		${WRKDIR}/QuantLib-${PORTVERSION}

USE_REINPLACE=	yes
USE_BZIP2=	yes
USE_LIBTOOL=	yes
CONFIGURE_TARGET=	--build=${ARCH}-portbld-freebsd${OSREL}
INSTALLS_SHLIB=	yes

MAN1=		DiscreteHedging.1 EuropeanOption.1 SwapValuation.1 \
		quantlib-config.1

pre-patch:
	@${REINPLACE_CMD} -e 's|-g -O3|\$$CXXFLAGS|g' ${WRKSRC}/configure
	@${FIND} ${WRKSRC} -name "Makefile.in" | \
		${XARGS} ${REINPLACE_CMD} -e 's|-g -O.|\@CXXFLAGS\@|g'
	@${FIND} ${WRKSRC}/Examples -name "Makefile.in" | \
		${XARGS} ${REINPLACE_CMD} -e 's|-pedantic -Wall|-O0|g'

.include <bsd.port.mk>
