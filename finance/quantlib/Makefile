# ex:ts=8
# New ports collection makefile for:	quantlib
# Date created:			Aug 12, 2001
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	quantlib
PORTVERSION=	0.3.1
CATEGORIES=	misc finance
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	QuantLib-${PORTVERSION}-src

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A comprehensive software framework for quantitative finance

WRKSRC=		${WRKDIR}/QuantLib-${PORTVERSION}

USE_REINPLACE=	yes
USE_LIBTOOL=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
INSTALLS_SHLIB=	yes

MAN1=		DiscreteHedging.1 EuropeanOption.1 SwapValuation.1 \
		quantlib-config.1

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500035
CFLAGS+=	-O0
.endif

post-patch:
	@${FIND} ${WRKSRC} -name "Makefile.in" | ${XARGS} ${REINPLACE_CMD} -e \
		's|(prefix)/aclocal|(datadir)/aclocal|g'

.include <bsd.port.post.mk>
