# New ports collection makefile for:	linux-eagle
# Date created:				29 December 2001
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	eagle
PKGNAMEPREFIX=	linux-
EAGLEVERSION=	4.08r2
PORTVERSION=	${EAGLEVERSION:S/r/./}
CATEGORIES=	cad
MASTER_SITES=	ftp://ftp.cadsoft.de/pub/program/${EAGLEVERSION}/
DISTNAME=	${PORTNAME}-${EAGLEVERSION}e
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org

RUN_DEPENDS=	${LINUXBASE}/lib/ld.so:${PORTSDIR}/emulators/linux_base

ONLY_FOR_ARCHS=	i386

WRKSRC=		${WRKDIR}/${PORTNAME}-${EAGLEVERSION}

RESTRICTED=	"Usage permitted for non-commercial purposes only"
NO_CDROM=	"Sale for profit is not permitted"

NO_BUILD=	yes
PKGMESSAGE=	${WRKDIR}/pkg-message

MAN1=		eagle.1

do-install:
	${MKDIR} ${DATADIR}
	${TAR} -C ${WRKSRC} -cf - . | ${TAR} -C ${DATADIR} --unlink -xf -
	${LN} -sf ${DATADIR}/bin/eagle ${PREFIX}/bin/eagle
	${INSTALL_MAN} ${DATADIR}/man/eagle.1 ${PREFIX}/man/man1

post-install:
	@${SED} -e "s:%%PREFIX%%:${PREFIX}:g" ${PKGDIR}/pkg-message > \
		${PKGMESSAGE}
.if !defined(BATCH)
	@${ECHO_MSG}
	@${CAT} ${PKGMESSAGE}
	@${ECHO_MSG}
.endif

.include <bsd.port.mk>
