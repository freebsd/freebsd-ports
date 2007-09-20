# ex:ts=8
# Ports collection makefile for:	qfsm
# Date created:			Mar 14, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	qfsm
PORTVERSION=	0.44
CATEGORIES=	cad
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A graphical tool for designing finite state machines

USE_QT_VER=	3
USE_PERL5_BUILD=yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ARGS=	--with-qtdir=${QT_PREFIX}
MAKE_ARGS=	LDADD="-lqt-mt ${PTHREAD_LIBS}"

post-extract:
	@${ECHO_CMD} '#!/bin/sh' > ${WRKSRC}/qfsm.sh
	@${ECHO_CMD} 'QFSMDIR=${DATADIR}' >> ${WRKSRC}/qfsm.sh
	@${ECHO_CMD} 'export QFSMDIR' >> ${WRKSRC}/qfsm.sh
	@${ECHO_CMD} '' >> ${WRKSRC}/qfsm.sh
	@${ECHO_CMD} 'exec ${PREFIX}/bin/qfsm.exec "$$@"' >> ${WRKSRC}/qfsm.sh

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/qfsm.sh ${PREFIX}/bin/qfsm
	${INSTALL_PROGRAM} ${WRKSRC}/src/qfsm ${PREFIX}/bin/qfsm.exec
	@${MKDIR} ${DATADIR}/po
	${INSTALL_DATA} ${WRKSRC}/po/*.qm ${DATADIR}/po
	${INSTALL_DATA} ${WRKSRC}/po/*.ts ${DATADIR}/po
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/user/*.docbook ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/user/*.html ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/user/*.pdf ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/user/*.png ${DOCSDIR}
.endif
.if !defined(NOPORTEXAMPLES)
	@${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/*.fsm ${EXAMPLESDIR}
.endif

.include <bsd.port.mk>
