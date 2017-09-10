# Created by: George Reid <greid@ukug.uk.freebsd.org>
# $FreeBSD$

PORTNAME=	asmutils
PORTVERSION=	0.18
PORTREVISION=	4
CATEGORIES=	devel
MASTER_SITES=	http://asm.sourceforge.net/asmutils/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Set of Unix utilities written in x86 assembly language

LICENSE=	GPLv2

ONLY_FOR_ARCHS=	i386

BUILD_DEPENDS=	nasm:devel/nasm

USES=		gmake
USE_GCC=	any
MAKE_ARGS=	OS="${OPSYS:tu}" KERNEL="${OSREL:S/.//g}" CC="${CC}" LD="${LD}"

# This will play merry hell with portlint(1)
BINARIES=	bonus/asmutils basename cal cat chmod chown chroot cmp cp \
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

LIBRARIES=	libc.so.0 libcrypto.so.0 libm.so.0

PLIST_FILES=	${BINARIES:S/^/bin\/asmutils\//:S/bonus\///} \
		${LINKS:S/^/bin\/asmutils\//} ${LIBRARIES:S/^/lib\/asmutils\//}
PORTDOCS=	*

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e 's,^static ,,' ${WRKSRC}/lib/libm.c

# Stripping binaries will break installation
STRIP=	#

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/bin/asmutils \
		${STAGEDIR}${PREFIX}/lib/asmutils
	${INSTALL_PROGRAM} ${BINARIES:S,^,${WRKSRC}/src/,} \
		${STAGEDIR}${PREFIX}/bin/asmutils
	${INSTALL_PROGRAM} ${LIBRARIES:S,^,${WRKSRC}/lib/,} \
		${STAGEDIR}${PREFIX}/lib/asmutils
	(cd ${STAGEDIR}${PREFIX}/bin/asmutils && \
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

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/[^i]* ${STAGEDIR}${DOCSDIR}
	${LN} -sf Asmutils-HOWTO.html ${STAGEDIR}/${DOCSDIR}/index.html

.include <bsd.port.mk>
