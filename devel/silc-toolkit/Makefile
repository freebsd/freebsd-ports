# New ports collection makefile for:	silc toolkit
# Date created:				Thu Nov 8 01:50:05 BRST 2001
# Whom:			Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	silc
PORTVERSION=	0.7.2
CATEGORIES=	devel ipv6 net security
MASTER_SITES=	http://www.silcnet.org/download/toolkit/sources/ \
		ftp://ftp.silcnet.org/silc/toolkit/sources/ \
		http://www.planetmirror.com/pub/silcnet/toolkit/sources / \
		ftp://ftp.au.silcnet.org/pub/silcnet/toolkit/sources/ \
		http://the.wiretapped.net/security/network-security/silc/toolkit/sources/ \
		ftp://ftp.wiretapped.net/pub/security/network-security/silc/toolkit/sources/ \
		http://munitions.vipul.net/software/mirrors/silc/ \
		ftp://ftp.no.silcnet.org/pub/silc/toolkit/sources/
PKGNAMESUFFIX=	-toolkit
DISTNAME=	${PORTNAME}${PKGNAMESUFFIX}-${PORTVERSION}

MAINTAINER=	lioux@FreeBSD.org

RUN_DEPENDS=	silc:${PORTSDIR}/net/silc-client

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
USE_GLIB=	yes
CONFIGURE_ARGS=	--with-silcd-config-file=${PREFIX}/etc/${PORTNAME} \
		--with-docdir=${PREFIX}/share/doc/${PORTNAME}${PKGNAMESUFFIX} \
		--with-etcdir=${PREFIX}/etc/${PORTNAME} \
		--with-helpdir=${PREFIX}/share/${PORTNAME}${PKGNAMESUFFIX}/help \
		--with-logsdir=${PORTNAME}/logs \
		--with-simdir=libexec/${PORTNAME}/modules \
		--includedir=${PREFIX}/include/${PORTNAME}
PLIST_SUB=	INSTALL_DIR="${INSTALL_DIR}"

INSTALL_DIR?=	${INSTALL} -d -o ${BINOWN} -g ${BINGRP} -m 755

.ifdef(WITHOUT_OPTIMIZED_ASM)
CONFIGURE_ARGS+=	--disable-asm
.endif

.ifndef(WITH_PTHREADS)
CONFIGURE_ARGS+=	--disable-threads
.else
CONFIGURE_ENV+=	CFLAGS="${CFLAGS} ${PTHREAD_CFLAGS} ${PTHREAD_LIBS}"
.endif

pre-everything::
.ifndef(WITHOUT_OPTIMIZED_ASM)
	@${ECHO_MSG} '===> Define WITHOUT_OPTIMIZED_ASM to disable assembler optimizations'
.endif
.ifndef(WITH_PTHREADS)
	@${ECHO_MSG} '===> Define WITH_PTHREADS to enable pthreads support'
.endif

post-patch:
.ifdef(NOPORTDOCS)
	@${PERL} -pi -ne 's|doc includes|includes|;s| doc-install| |; \
		s|^.*-mkdir -p \$$\(docdir\).*$$||' ${WRKSRC}/Makefile.in
.endif
	@${PERL} -pi -e 's|-O2||' ${CONFIGURE_WRKSRC}/${CONFIGURE_SCRIPT}

pre-install:
	@${RM} -Rf ${WRKSRC}/doc/examples/CVS

.include <bsd.port.pre.mk>

.if ${ARCH} != "i386"
WITHOUT_OPTIMIZED_ASM=	yes
.endif

.if ${OSVERSION} >= 400014
CONFIGURE_ARGS+=	--enable-ipv6
.endif

.include <bsd.port.post.mk>
