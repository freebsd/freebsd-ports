# ex:ts=8
# Ports collection makefile for:	qfsm
# Date created:			Mar 14, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	qfsm
PORTVERSION=	0.41
PORTREVISION=	2
CATEGORIES=	cad
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A graphical tool for designing finite state machines

USE_QT_VER=	3
USE_REINPLACE=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}

post-patch:
	@${FIND} ${WRKSRC} -name "Makefile.in" | ${XARGS} ${REINPLACE_CMD} -e \
		's|^AM_CXXFLAGS =.*$$|AM_CXXFLAGS =|g'

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/qfsm ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	@${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/*.fsm ${EXAMPLESDIR}
.endif

.include <bsd.port.mk>
