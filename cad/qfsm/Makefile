# ex:ts=8
# Ports collection makefile for:	qfsm
# Date created:			Mar 14, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	qfsm
PORTVERSION=	0.43
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
CONFIGURE_ARGS=	--x-libraries=${X11BASE}/lib --x-includes=${X11BASE}/include

post-extract:
	@${ECHO_CMD} '#!/bin/sh' > ${WRKSRC}/qfsm.sh
	@${ECHO_CMD} 'QFSMDIR=${DATADIR}' >> ${WRKSRC}/qfsm.sh
	@${ECHO_CMD} 'export QFSMDIR' >> ${WRKSRC}/qfsm.sh
	@${ECHO_CMD} '' >> ${WRKSRC}/qfsm.sh
	@${ECHO_CMD} 'exec ${PREFIX}/bin/qfsm.exec "$$@"' >> ${WRKSRC}/qfsm.sh

post-patch:
	@${FIND} ${WRKSRC} -name "Makefile.in" | ${XARGS} ${REINPLACE_CMD} -e \
		's|^AM_CXXFLAGS =.*$$|AM_CXXFLAGS =|g'
	@${REINPLACE_CMD} -e 's|-pedantic||g ; \
		 s|-pthread|${PTHREAD_LIBS}|g' ${WRKSRC}/configure

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/qfsm.sh ${PREFIX}/bin/qfsm
	${INSTALL_PROGRAM} ${WRKSRC}/src/qfsm ${PREFIX}/bin/qfsm.exec
	@${MKDIR} ${DATADIR}/po
	${INSTALL_DATA} ${WRKSRC}/po/*.qm ${DATADIR}/po
	${INSTALL_DATA} ${WRKSRC}/po/*.ts ${DATADIR}/po
.if !defined(NOPORTDOCS)
	@${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/*.fsm ${EXAMPLESDIR}
.endif

.include <bsd.port.mk>
