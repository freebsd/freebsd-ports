# ex:ts=8
# Ports collection makefile for:	GDB 5.1
# Date created:				30 March 2001
# Whom:					David O'Brien <obrien@NUXI.com>
#
# $FreeBSD$
#

SNAPDATE=	2004-03-23
SNAPVER=	${SNAPDATE:S/-//g}

PORTNAME=	gdb
PORTVERSION=	6
PORTREVISION=	${SNAPVER}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEWARE}
MASTER_SITE_SUBDIR=	gdb/snapshots/current
DISTNAME=	gdb+dejagnu-weekly-${SNAPVER}

MAINTAINER=	obrien@FreeBSD.org
COMMENT=	GNU GDB 6

WRKSRC=		${WRKDIR}/${DISTNAME:S/-weekly//}
USE_BZIP2=	yes
USE_GMAKE=	yes
USE_REINPLACE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--program-suffix=6

post-patch:
	@${REINPLACE_CMD} -e 's/$$/ [FreeBSD]/' ${WRKSRC}/gdb/version.in

do-patch: post-patch
	@${ECHO} 'FreeBSD-specific patches disabled for now, until upgraded.'

pre-configure:
	cd ${WRKSRC} ; ${RM} -rf dejagnu expect sim tcl texinfo

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/gdb/gdb \
		${PREFIX}/bin/${PORTNAME}${PORTVERSION:S/.//g}

cklatest:
	ncftpls \
	    ftp://sources.redhat.com/pub/${MASTER_SITE_SUBDIR}/  \
	    | ${GREP} gdb+dejagnu-weekly

.include <bsd.port.mk>

.if ${ARCH} == "amd64"
CONFIGURE_TARGET=	x86_64-portbld-freebsd${OSREL}
.endif
