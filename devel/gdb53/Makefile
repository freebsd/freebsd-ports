# ex:ts=8
# Ports collection makefile for:	GDB 5.1
# Date created:				30 March 2001
# Whom:					David O'Brien <obrien@NUXI.com>
#
# $FreeBSD$
#

PORTNAME=	gdb
PORTVERSION=	5.3
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEWARE}
MASTER_SITE_SUBDIR=	gdb/releases

MAINTAINER=	mp@FreeBSD.org
COMMENT=	GNU GDB 5.3 developmental snapshot

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
