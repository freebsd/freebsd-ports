# ex:ts=8
# Ports collection makefile for:	GDB 5.1
# Date created:				30 March 2001
# Whom:					David O'Brien <obrien@NUXI.com>
#
# $FreeBSD$
#

SNAPDATE=	2002-10-15
SNAPVER=	${SNAPDATE:S/-//g}

PORTNAME=	gdb
PORTVERSION=	5.3
PORTREVISION=	${SNAPVER}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEWARE}
#MASTER_SITE_SUBDIR=	gdb/releases
MASTER_SITE_SUBDIR=	gdb/snapshots/branch
DISTNAME=	gdb+dejagnu-weekly-5.2.90_${SNAPVER}

PATCH_SITES=	${MASTER_SITE_LOCAL}
PATCH_SITE_SUBDIR=	obrien
#PATCHFILES=	gdb521_xfree-loadmod.diff

MAINTAINER=	mp@FreeBSD.org

WRKSRC=		${WRKDIR}/${DISTNAME:S/-weekly//}
USE_BZIP2=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--program-suffix=53

pre-configure:
	cd ${WRKSRC} ; ${RM} -rf dejagnu expect sim tcl texinfo

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/gdb/gdb \
		${PREFIX}/bin/${PORTNAME}${PORTVERSION:S/.//g}

cklatest:
	ncftpls \
	    ftp://mirrors.rcn.net/mirrors/sources.redhat.com/${MASTER_SITE_SUBDIR}/  \
	    | ${GREP} gdb+dejagnu-weekly

.include <bsd.port.mk>
