# ex:ts=8
# Ports collection makefile for:	GDB 5.1 PowerPC simulator
# Date created:				12 October 2001
# Whom:					Mark Peek <mp@FreeBSD.org>
# 					David O'Brien <obrien@NUXI.com>
# $FreeBSD$
#

SNAPDATE=	2001-10-12
SNAPVER=	${SNAPDATE:S/-//g}

PORTNAME=	psim-freebsd
PORTVERSION=	${SNAPVER}
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_SOURCEWARE}
MASTER_SITE_SUBDIR=	gdb/snapshots
DISTNAME=	gdb+dejagnu-${SNAPVER}

MAINTAINER=	mp@FreeBSD.org

USE_BZIP2=	yes

.include <bsd.port.pre.mk>

USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	${ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ARGS=	--enable-psim --target=powerpc-freebsd-elf --program-suffix=psim

pre-configure:
	cd ${WRKSRC} ; ${RM} -rf dejagnu expect tcl texinfo

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/gdb/gdb ${PREFIX}/bin/${PORTNAME}
	${MKDIR} ${PREFIX}/share/examples/${PORTNAME}
	${INSTALL_DATA} ${FILESDIR}/dot.gdbinit \
		${PREFIX}/share/examples/${PORTNAME}
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${FILESDIR}/HOW-TO ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
