# New ports collection makefile for:	qico
# Date created:		13 Jan 2000
# Whom:			Denis Shaposhnikov <dsh@vlink.ru>
#
# $FreeBSD$
#

PORTNAME=	qico
PORTVERSION=	0.48.5
PORTREVISION=	1
CATEGORIES=	comms
MASTER_SITES=	http://lev.serebryakov.spb.ru/download/0.48/

MAINTAINER=	dsh@vlink.ru
COMMENT=	An FidoNet Technology Network (FTN) compatible mailer for Unix systems

USE_GMAKE=	yes
MAKE_ENV+=	SH=${SH} AWK=${AWK} MORDA="${MORDA}" DEFS="${DEFS}"

.if defined(WITH_QICO_AMIGA4D)
DEFS+=		-DAMIGA4D
.endif

.if defined(WITH_QICO_MORDA)
MORDA=		1
PLIST_SUB+=	WITH_QICO_MORDA=""
.else
PLIST_SUB+=	WITH_QICO_MORDA="@comment "
.endif

do-install:
	${INSTALL_DATA} ${WRKSRC}/qico.conf.sample ${PREFIX}/etc/
	${INSTALL_PROGRAM} ${WRKSRC}/src/qico ${PREFIX}/libexec/
.if defined(WITH_QICO_MORDA)
	${INSTALL_PROGRAM} ${WRKSRC}/src/qcc ${PREFIX}/bin/
.endif

.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/qico
	${INSTALL_DATA} ${WRKSRC}/FAQ ${PREFIX}/share/doc/qico/FAQ.ru
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/qico/README.ru
.endif

.include <bsd.port.mk>
