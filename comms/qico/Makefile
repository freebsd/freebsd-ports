# New ports collection makefile for:	qico
# Date created:		13 Jan 2000
# Whom:			Denis Shaposhnikov <dsh@vlink.ru>
#
# $FreeBSD$
#

PORTNAME=	qico
PORTVERSION=	0.48
DISTNAME=	${PORTNAME}-${PORTVERSION}.0
CATEGORIES=	comms
MASTER_SITES=	http://lev.serebryakov.spb.ru/download/
PATCH_SITES=	${MASTER_SITES}
PATCHFILES=	${PORTNAME}-${PORTVERSION}.0-stable.patch.gz

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
