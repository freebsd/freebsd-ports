# New ports collection makefile for:	newt
# Date created:		08 Jan 2000
# Whom:			Will Andrews <andrews@technologist.com>
#
# $FreeBSD$
#

PORTNAME=	newt
PORTVERSION=	0.50.8.2
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.redhat.com/pub/redhat/redhat-6.2-en/os/i386/SRPMS/

DISTNAME=	${PORTNAME}-0.50.8-2
EXTRACT_SUFX=	.src.rpm

MAINTAINER=	ports@FreeBSD.org

LIB_DEPENDS=	slang.1:${PORTSDIR}/devel/libslang \
		tcl82.1:${PORTSDIR}/lang/tcl82 \
		popt.0:${PORTSDIR}/devel/popt
BUILD_DEPENDS=	rpm2cpio:${PORTSDIR}/archivers/rpm \
		python1.5:${PORTSDIR}/lang/python15

USE_GMAKE=	yes
GNU_CONFIGURE=	yes
INSTALLS_SHLIB=	yes
WRKSRC=		${WRKDIR}/newt-0.50.8
VERSION=	0
MAKE_ENV+=	prefix=${PREFIX} VERSION=${VERSION} CC=${CC} PCFLAGS="${CFLAGS}"
PLIST_SUB+=	VERSION="${VERSION}"
CPIO?=		/usr/bin/cpio

do-extract:
	@${RM} -rf ${WRKDIR}
	@${MKDIR} ${WRKDIR}
	@${LOCALBASE}/bin/rpm2cpio ${_DISTDIR}${DISTFILES} | (cd ${WRKDIR};${CPIO} -i)
	@${TAR} xfz ${WRKSRC}.tar.gz -C ${WRKDIR}

.include <bsd.port.mk>
