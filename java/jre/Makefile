# New ports collection makefile for:	jre
# Date created:				8 May 2000
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	jre
PORTVERSION=	${JRE_VERSION}
CATEGORIES=	java devel
MASTER_SITES=	ftp://ftp.se.freebsd.org/pub/FreeBSD/JDK/ \
		${MASTER_SITE_LOCAL} \
		ftp://ftp.sc.sri.com/pub/FreeBSD/JDK/ \
		http://www.freebsd.org/java/
MASTER_SITE_SUBDIR=	patrick

MAINTAINER=	sobomax@FreeBSD.org

RUN_DEPENDS=	javavm:${PORTSDIR}/java/javavmwrapper

NO_CDROM=	"License doesn't allow distribution with fee"

ONLY_FOR_ARCHS=	i386
JRE_VERSION=	1.1.8
PLIST_SUB+=	JRE_VERSION=${JRE_VERSION}

WRKSRC=		${WRKDIR}/jre

STRIPFILES=	bin/i386/green_threads/jre \
		bin/i386/green_threads/jre_X \
		lib/i386/green_threads/libawt.so \
		lib/i386/green_threads/libjava.so \
		lib/i386/green_threads/libjpeg.so \
		lib/i386/green_threads/libmath.so \
		lib/i386/green_threads/libmmedia.so \
		lib/i386/green_threads/libnet.so \
		lib/i386/green_threads/libsysresource.so \
		lib/i386/green_threads/libzip.so

.include <bsd.port.pre.mk>

.if ${PORTOBJFORMAT} == "aout"
DISTFILES=	jre${JRE_VERSION}i_AOUT.V1999-11-9.tar.gz
.else
DISTFILES=	jre${JRE_VERSION}i_ELF.V1999-11-9.tar.gz
.endif

pre-extract:
.if ${PORTOBJFORMAT} == "elf"
	@if ! (${LDCONFIG} -r | ${GREP} -qwF -e "-lc.3"); then \
		${ECHO_MSG} ; \
		${ECHO_MSG} " WARNING! It appears that you don't have installed libc.so.3 shared library," ; \
		${ECHO_MSG} "          which is required to run JRE. Usually you can install it as part of" ; \
		${ECHO_MSG} "          the \`compat3x' package. If you have FreeBSD source code installed" ; \
		${ECHO_MSG} "          then you can use the following command to install it:" ; \
		${ECHO_MSG} ; \
		${ECHO_MSG} "          # cd /usr/src/lib/compat/compat3x.${ARCH} ; make install" ; \
		${ECHO_MSG} ; \
	fi
.endif

do-build:
	@for file in ${STRIPFILES}; do \
		strip ${WRKSRC}/$$file; \
	done

do-install:
	${MKDIR} ${PREFIX}/jre${JRE_VERSION}
	${MKDIR} ${PREFIX}/share/java/classes
	${MKDIR} ${PREFIX}/share/doc/java
	(cd ${WRKSRC} && ${TAR} -c -f - .) \
		| (cd ${PREFIX}/jre${JRE_VERSION} && ${TAR} --unlink -x -f -)
	cd ${PREFIX}/jre${JRE_VERSION}/bin && \
		${LN} -sf .java_wrapper java && \
		cd i386/green_threads && \
			${LN} -sf jre java && \
			${LN} -sf jre_X java_X

post-install:
	${LOCALBASE}/bin/registervm "${PREFIX}/jre${JRE_VERSION}/bin/java # JRE${JRE_VERSION}"

.include <bsd.port.post.mk>
