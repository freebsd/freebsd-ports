# ex:ts=8
# Ports collection makefile for:	qfsm
# Date created:			Mar 14, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	qfsm
PORTVERSION=	0.46
CATEGORIES=	cad
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A graphical tool for designing finite state machines

USE_QT_VER=	3
USE_PERL5_BUILD=yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ARGS=	--with-qt-dir=${QT_PREFIX}

QTCPPFLAGS=	${PTHREAD_CFLAGS}
QTCFGLIBS=	${PTHREAD_LIBS}

post-patch:
	@${REINPLACE_CMD} -e '/^SUBDIRS/s| doc/user||g' ${WRKSRC}/Makefile.in

post-install:
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
