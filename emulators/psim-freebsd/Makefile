# ex:ts=8
# Ports collection makefile for:	GDB 5.1 PowerPC simulator
# Date created:				12 October 2001
# Whom:					Mark Peek <mp@FreeBSD.org>
# 					David O'Brien <obrien@NUXI.com>
# $FreeBSD$
#

PORTNAME=	psim-freebsd
PORTVERSION=	5.0.92
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_SOURCEWARE}
MASTER_SITE_SUBDIR=	gdb/snapshots
DISTNAME=	gdb-${PORTVERSION}

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
