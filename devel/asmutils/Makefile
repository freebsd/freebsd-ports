# New ports collection makefile for:	asmutils
# Date created:				22 January 2001
# Whom:					George Reid <greid@ukug.uk.freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	asmutils
PORTVERSION=	0.18
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://asm.sourceforge.net/asmutils/

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	A set of UNIX utilities written in x86 assembly language

ONLY_FOR_ARCHS=	i386

BUILD_DEPENDS=	nasm:${PORTSDIR}/devel/nasm

USE_GMAKE=	yes

# This will play merry hell with portlint
BINS=		bonus/asmutils basename cal cat chmod chown chroot cmp cp \
		cpuinfo cut date dc dd deflate dirname du echo env \
		bonus/execve extname factor fromdos ftpd getty grep head \
		hexdump host hostname httpd id idea init kill kldload less \
		ln ls lzss m_inetd md5 md5sum mkdir mknod mount mv nc \
		netstat nice nm nohup od paste ping pop3d proxy pwd rc6crypt \
		readelf readkey readlink reboot renice bonus/report rm \
		rmdsum rot13 scan scons sh sha1sum sleep strings sync tail \
		tar tee telnet telnetd test touch tr true uname uuencode \
		watch wc wget which whoami write yes

LINKS=		arch cpuspeed domainname false halt inflate kldstat kldunload \
		mkfifo more poweroff regs rmdir size sln todos umount usleep

LIBS=		libc.so.0 libcrypto.so.0 libm.so.0

PLIST_FILES=	${BINS:S/^/bin\/asmutils\//:S/bonus\///} \
		${LINKS:S/^/bin\/asmutils\//} ${LIBS:S/^/lib\/asmutils\//}
PLIST_DIRS=	bin/asmutils lib/asmutils
PORTDOCS=	*

post-patch:
	@${REINPLACE_CMD} -e 's,%%KERNEL%%,${OSREL:S/.//g},g' ${WRKSRC}/MCONFIG
	@${REINPLACE_CMD} -e 's,^static ,,' ${WRKSRC}/lib/libm.c
# Workaround for broken macro local labels in nasm v2.07+
	@${REINPLACE_CMD} -e 's,%{$$strucname},&%+,' ${WRKSRC}/inc/elf.inc \
		${WRKSRC}/inc/system.inc

# Stripping binaries will break install
STRIP=	#

do-install:
	@${MKDIR} ${PREFIX}/bin/asmutils ${PREFIX}/lib/asmutils
.for B in ${BINS}
	${INSTALL_PROGRAM} ${WRKSRC}/src/${B} ${PREFIX}/bin/asmutils
.endfor
.for L in ${LIBS}
	${INSTALL_PROGRAM} ${WRKSRC}/lib/${L} ${PREFIX}/lib/asmutils
.endfor
	(cd ${PREFIX}/bin/asmutils && \
		${LN} -sf uname arch && \
		${LN} -sf cpuinfo cpuspeed && \
		${LN} -sf hostname domainname && \
		${LN} -sf true false && \
		${LN} -sf reboot halt && \
		${LN} -sf deflate inflate && \
		${LN} -sf kldload kldstat && \
		${LN} -sf kldload kldunload && \
		${LN} -sf mknod mkfifo && \
		${LN} -sf less more && \
		${LN} -sf reboot poweroff && \
		${LN} -sf execve regs && \
		${LN} -sf mkdir rmdir && \
		${LN} -sf nm size && \
		${LN} -sf ln sln && \
		${LN} -sf fromdos todos && \
		${LN} -sf mount umount && \
		${LN} -sf sleep usleep)

.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/[^i]* ${DOCSDIR}
	@cd ${DOCSDIR} && ${LN} -sf Asmutils-HOWTO.html index.html
.endif

.include <bsd.port.mk>
