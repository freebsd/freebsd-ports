# New ports collection makefile for:	linux-eagle
# Date created:				29 December 2001
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	linux-eagle
EAGLEVERSION?=	4.09r2
EAGLELANG?=	e
PORTVERSION=	${EAGLEVERSION:S/r/./}
CATEGORIES?=	cad linux
MASTER_SITES=	ftp://ftp.cadsoft.de/pub/program/${EAGLEVERSION}/
DISTNAME=	${PORTNAME:S/linux-//}-${EAGLEVERSION}${EAGLELANG}
EXTRACT_SUFX=	.tgz

MAINTAINER?=	riggs@rrr.de

RUN_DEPENDS=	${LINUXBASE}/lib/ld-linux.so.2:${PORTSDIR}/emulators/linux_base

ONLY_FOR_ARCHS=	i386

WRKSRC=		${WRKDIR}/${PORTNAME:S/linux-//}-${EAGLEVERSION}
DATADIR=	${PREFIX}/share/${PORTNAME:S/linux-//}

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
