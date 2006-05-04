# ex:ts=8
# Ports collection makefile for:	FPC-GDB 5.2.1
# Date created:				8 February 2004
# Whom:				John Merryweather Cooper <coop9211@uidaho.edu>
#
# $FreeBSD$
#

PORTNAME=	gdb
PORTVERSION=	5.2.1
CATEGORIES=	devel lang
MASTER_SITES=	${MASTER_SITE_SOURCEWARE}
MASTER_SITE_SUBDIR=	gdb/old-releases
PKGNAMEPREFIX=	fpc-

PATCH_SITES=	ftp://ftp.freepascal.org/pub/fpc/contrib/libgdb/old/v5.2.1/ \
		ftp://ftp.planetmirror.com/pub/fpc/contrib/libgdb/old/v5.2.1/ \
		ftp://ftp.jp.freepascal.org/mirror/fpc/contrib/libgdb/old/v5.2.1/ \
		ftp://freepascal.stack.nl/pub/fpc/contrib/libgdb/old/v5.2.1/ \
		ftp://ftp.no.freepascal.org/pub/fpc/contrib/libgdb/old/v5.2.1/ \
		ftp://ftp.us.freepascal.org/pub/fpc/contrib/libgdb/old/v5.2.1/ \
		${MASTER_SITE_LOCAL:S/$/:local/}
PATCH_SITE_SUBDIR=	obrien/:local
PATCHFILES=	gdb521.dif gdb521_xfree-loadmod.diff:local

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GNU GDB 5.2.1 modified for Free Pascal

.include <bsd.port.pre.mk>

NO_LATEST_LINK=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--program-suffix=fpc
AR?=		/usr/bin/ar

ONLY_FOR_ARCHS=	i386

pre-configure:
	cd ${WRKSRC} ; ${RM} -rf dejagnu expect sim tcl texinfo

post-configure:
# if devel/bison is installed, build will fail --> force yacc
	@${FIND} ${WRKSRC} -name "Makefile*" | ${XARGS} \
		${REINPLACE_CMD} 's|bison -y|yacc|g'

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/gdb/gdb \
		${PREFIX}/bin/gdbfpc
	cd ${WRKSRC}/gdb && ${AR} -rs libgdb.a cli*.o mi*.o
	cd ${WRKSRC}/bfd && ${AR} -rs libbfd.a *.o
	cd ${WRKSRC}/opcodes && ${AR} -rs libopcodes.a *.o
	@${MKDIR} ${PREFIX}/lib/fpc/1.0.10/units/freebsd/gdbint/libgdb
	@${INSTALL_DATA} \
		${WRKSRC}/gdb/libgdb.a \
		${WRKSRC}/bfd/libbfd.a \
		${WRKSRC}/opcodes/libopcodes.a \
		${WRKSRC}/libiberty/libiberty.a \
		${WRKSRC}/intl/libintl.a \
		${PREFIX}/lib/fpc/1.0.10/units/freebsd/gdbint/libgdb

cklatest:
	ncftpls \
	    ftp://mirrors.rcn.net/mirrors/sources.redhat.com/${MASTER_SITE_SUBDIR}/  \
	    | ${GREP} gdb+dejagnu-

.include <bsd.port.post.mk>
