# ex:ts=8
# New ports collection makefile for:	quantlib
# Date created:			Aug 12, 2001
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	quantlib
PORTVERSION=	0.3.5
PORTREVISION=	1
CATEGORIES=	finance
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	QuantLib-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A comprehensive software framework for quantitative finance

WRKSRC=		${WRKDIR}/QuantLib-${PORTVERSION}

USE_GCC=	3.3
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ENV=	CPPFLAGS="${PTHREAD_CFLAGS}" LDFLAGS="${PTHREAD_LIBS}"
INSTALLS_SHLIB=	yes

MAN1=		quantlib-config.1 quantlib-test-suite.1

.include <bsd.port.pre.mk>

.if ${ARCH} == "ia64" || ${ARCH} == "alpha"
BROKEN=		"Does not build on ia64 or alpha"
.endif

post-patch:
	@${FIND} ${WRKSRC} -name "Makefile.in" | ${XARGS} ${REINPLACE_CMD} -e \
		's|: install-dist_lispLISP|:|g ; \
		 s|@CPPUNIT_FOUND_TRUE@|#|g ; \
		 s|@CPPUNIT_FOUND_FALSE@||g'

post-install:
	${INSTALL_DATA} ${WRKSRC}/quantlib.el ${PREFIX}/share/emacs/site-lisp

.include <bsd.port.post.mk>
