# ex:ts=8
# Ports collection makefile for:	GDB 5.1
# Date created:				30 March 2001
# Whom:					David O'Brien <obrien@NUXI.com>
#
# $FreeBSD$
#

PORTNAME=	gdb
PORTVERSION=	5.2.1
PORTREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEWARE}
MASTER_SITE_SUBDIR=	gdb/releases

PATCH_SITES=	${MASTER_SITE_LOCAL}
PATCH_SITE_SUBDIR=	obrien
PATCHFILES=	gdb521_xfree-loadmod.diff

MAINTAINER=	mp@FreeBSD.org
COMMENT=	GNU GDB 5.2.1 debugger

.include <bsd.port.pre.mk>

.if ${ARCH} == "amd64"
BROKEN=		"Configure fails on amd64"
.endif

LATEST_LINK=	gdb52
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--program-suffix=521

pre-configure:
	cd ${WRKSRC} ; ${RM} -rf dejagnu expect sim tcl texinfo

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/gdb/gdb \
		${PREFIX}/bin/${PORTNAME}${PORTVERSION:S/.//g}

cklatest:
	ncftpls \
	    ftp://mirrors.rcn.net/mirrors/sources.redhat.com/${MASTER_SITE_SUBDIR}/  \
	    | ${GREP} gdb+dejagnu-

.include <bsd.port.post.mk>
