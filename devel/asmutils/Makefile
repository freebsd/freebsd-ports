# New ports collection makefile for:   asmutils
# Date created:        22 January 2001
# Whom:                George Reid <greid@ukug.uk.freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	asmutils
PORTVERSION=	0.14
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://linuxassembly.org/asmutils/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A set of UNIX utilities written in assembly language

BUILD_DEPENDS=	nasm:${PORTSDIR}/devel/nasm

ONLY_FOR_ARCHS=	i386

USE_GMAKE=	yes

INSTALLS_SHLIB=	yes
LDCONFIG_DIRS=	${PREFIX}/lib/asmutils

# This will play merry hell with portlint
BINARIES=	asmutils basename cat chmod chown chroot cp cpuinfo date \
		dd dirname echo env execve extname factor grep head \
		hexdump hostname httpd id init kill ln ls lzss md5sum \
		mkdir more mv nc ping pwd rc6crypt renice report rm rmdsum \
		sh sleep strings sync tee true uname wc yes

DOCFILES=	Asmutils-HOWTO acknowledgements endorsements history \
		index s-contrib s-debug s-include s-layout s-optimize

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 500113
BROKEN=         "Does not compile"
.endif

post-patch:
	@(${SED} -e 's,%%KERNEL%%,${OSREL:S/.//g},g' ${WRKSRC}/MCONFIG > ${WRKDIR}/foo \
		&& ${MV} ${WRKDIR}/foo ${WRKSRC}/MCONFIG)

do-install:
	${MKDIR} ${PREFIX}/bin/asmutils
	${MKDIR} ${PREFIX}/lib/asmutils
.for B in ${BINARIES}
	${INSTALL_PROGRAM} ${WRKSRC}/src/$B ${PREFIX}/bin/asmutils
.endfor
	(cd ${PREFIX}/bin/asmutils && \
		${LN} -sf uname arch && \
		${LN} -sf cpuinfo cpuspeed && \
		${LN} -sf hostname domainname && \
		${LN} -sf true false && \
		${LN} -sf execve regs && \
		${LN} -sf mkdir rmdir && \
		${LN} -sf ln sln)
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

.include <bsd.port.post.mk>
