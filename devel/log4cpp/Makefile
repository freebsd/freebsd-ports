# ex:ts=8
# New ports collection makefile for:	log4cpp
# Date created:			May 1, 2001
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	log4cpp
PORTVERSION=	0.2.7
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org

GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${ARCH}-portbld-freebsd${OSREL}
INSTALLS_SHLIB=	yes

post-patch:
	@${PERL} -pi -e 's, endl, std::endl,g' ${WRKSRC}/tests/Clock.cpp \
		${WRKSRC}/tests/testbench.cpp

.include <bsd.port.mk>
