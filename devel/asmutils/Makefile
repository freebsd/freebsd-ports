# New ports collection makefile for:   asmutils
# Date created:        22 January 2001
# Whom:                George Reid <greid@ukug.uk.freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	asmutils
PORTVERSION=	0.13
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.linuxassembly.org/pub/asm/

MAINTAINER=	greid@ukug.uk.freebsd.org

BUILD_DEPENDS=	nasm:${PORTSDIR}/devel/nasm

ONLY_FOR_ARCHS=	i386

USE_GMAKE=	yes

INSTALLS_SHLIB=	yes
LDCONFIG_DIRS=	${PREFIX}/lib/asmutils

# This will play merry hell with portlint
BINARIES=	cat basename chmod chroot chown cp cpuinfo dirname echo \
		env id extname factor grep head hostname httpd kill ln ls \
		lzss mkdir more mv nc pwd renice rm sh sleep strings sync \
		tee true uname wc yes md5sum rmdsum rc6crypt execve report \
		asmutils domainname sln rmdir false arch cpuspeed regs

DOCFILES=	Asmutils-HOWTO acknowledgements endorsements history \
		index s-contrib s-debug s-include s-layout s-optimize

post-patch:
	@(${SED} -e 's,%%KERNEL%%,${OSREL:S/.//g},g' ${WRKSRC}/MCONFIG > ${WRKDIR}/foo \
		&& ${MV} ${WRKDIR}/foo ${WRKSRC}/MCONFIG)

do-install:
	${MKDIR} ${PREFIX}/bin/asmutils
	${MKDIR} ${PREFIX}/lib/asmutils
.for B in ${BINARIES}
	${INSTALL_PROGRAM} ${WRKSRC}/src/$B ${PREFIX}/bin/asmutils
.endfor
.for L in c crypto m
	${INSTALL_PROGRAM} ${WRKSRC}/lib/lib$L.so.0 ${PREFIX}/lib/asmutils
	${INSTALL_DATA} ${WRKSRC}/lib/lib$L.a ${PREFIX}/lib/asmutils
.endfor
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/asmutils
.for D in ${DOCFILES}
	${INSTALL_DATA} ${WRKSRC}/doc/$D.html ${PREFIX}/share/doc/asmutils
.endfor
.endif

.include <bsd.port.mk>
