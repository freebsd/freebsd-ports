# New ports collection makefile for:    napster
# Version required:     0.6b
# Date created:         Thu Nov 18 01:07:00 PST 1999
# Whom:                 dburr@FreeBSD.org
#
# $FreeBSD$
#

DISTNAME=	nap-linux-0.6BETA
PKGNAME=	napster-0.6b
CATEGORIES=	audio net
MASTER_SITES=	http://www.gis.net/~nite/

MAINTAINER=	dburr@FreeBSD.org

RUN_DEPENDS=	/compat/linux/usr/i486-linux-libc5/lib/libc.so.5:${PORTSDIR}/emulators/linux_base

ONLY_FOR_ARCHS=	i386
WRKSRC=		${WRKDIR}/nap
NO_BUILD=	yes

do-patch:
	brandelf -t Linux ${WRKSRC}/nap

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/nap ${PREFIX}/bin/nap
	${MKDIR} ${PREFIX}/share/nap
	${INSTALL_DATA} ${WRKSRC}/nap.conf ${PREFIX}/share/nap
.if (!defined(NOPORTDOCS))
	@${ECHO_MSG} "===>  Installing README in ${PREFIX}/share/doc/nap"
	${MKDIR} ${PREFIX}/share/doc/nap
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/nap
.endif

post-install:
	@${CAT} ${PKGDIR}/MESSAGE

.include <bsd.port.mk>
