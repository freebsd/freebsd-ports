# New ports collection makefile for:	qico
# Date created:				13 Jan 2000
# Whom:					Denis Shaposhnikov <dsh@vlink.ru>
#
# $FreeBSD$
#

PORTNAME=	qico
PORTVERSION=	0.45.3.1
CATEGORIES=	comms
MASTER_SITES=	${MASTER_SITE_LOCAL} \
		http://www.ruxy.org.ru/~aaz/files/
MASTER_SITE_SUBDIR=	will
DISTNAME=	${PORTNAME}-0.45pl3.1

MAINTAINER=	dsh@vlink.ru

USE_GMAKE=	yes
MAKE_ENV+=	SH=${SH} AWK=${AWK} DEFS="${DEFS}"

.if defined(WITH_AMIGA4D)
DEFS+=		-DAMIGA4D
.endif

do-install:
	${INSTALL_DATA} ${WRKSRC}/qico.conf ${PREFIX}/etc/qico.conf.sample
	${INSTALL_PROGRAM} ${WRKSRC}/src/qico ${PREFIX}/libexec
	${INSTALL_PROGRAM} ${WRKSRC}/src/qcc ${PREFIX}/bin

.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/qico
	${INSTALL_MAN} ${WRKSRC}/FAQ ${PREFIX}/share/doc/qico/FAQ.ru
	${INSTALL_MAN} ${WRKSRC}/README ${PREFIX}/share/doc/qico/README.ru
.endif

.include <bsd.port.mk>
