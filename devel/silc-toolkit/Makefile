# New ports collection makefile for:	silc-toolkit
# Date created:				2003.12.15
# Whom:					Evgueni V. Gavrilov <aquatique@rusunix.org>
#
# $FreeBSD$
#

PORTNAME=	silc
PORTVERSION=	1.1.9
CATEGORIES=	devel ipv6 net security
MASTER_SITES=	http://www.silcnet.org/download/%SUBDIR%/ \
		http://ftp.silcnet.org/%SUBDIR%/ \
		http://www.nic.funet.fi/pub/mirrors/ftp.silcnet.org/silc/%SUBDIR%/ \
		http://ftp.sunet.se/pub/network/silc/%SUBDIR%/ \
		ftp://ftp.silcnet.org/silc/%SUBDIR%/ \
		ftp://ftp.funet.fi/pub/mirrors/ftp.silcnet.org/silc/%SUBDIR%/ \
		ftp://ftp.sunet.se/pub/network/silc/%SUBDIR%/
MASTER_SITE_SUBDIR=	toolkit/sources
PKGNAMESUFFIX=	-toolkit
DISTNAME=	${PORTNAME}${PKGNAMESUFFIX}-${PORTVERSION}

MAINTAINER=	nevans@talkpoint.com
COMMENT=	Secure Internet Live Conferencing (SILC) network toolkit

CONFLICTS=	silc-client-1.1.* silc-irssi-client-1.1.*

USE_AUTOTOOLS=	libtool:22
USE_BZIP2=	yes
USE_PERL5=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
CONFIGURE_ARGS=	--with-etcdir=${PREFIX}/etc/${PORTNAME}${PKGNAMESUFFIX} \
		--with-simdir=${PREFIX}/lib/silcsim \
		--with-helpdir=${PREFIX}/share/${PORTNAME}${PKGNAMESUFFIX}/help \
		--includedir=${PREFIX}/include/silc \
		--with-docdir=${DOCSDIR}${PKGNAMESUFFIX} \
		--enable-shared --without-libtoolfix
CONFIGURE_ENV=	CFLAGS+="${CFLAGS}" \
		CPPFLAGS+="${CPPFLAGS}"
USE_LDCONFIG=	yes

.if defined(NOPORTDOCS)
PLIST_SUB+=	PORTDOCS="@comment "
.endif

.ifndef(WITH_PTHREADS)
CONFIGURE_ARGS+=	--without-pthreads
.else
CONFIGURE_ENV+=	CFLAGS="${CFLAGS} ${PTHREAD_CFLAGS} ${PTHREAD_LIBS}"
.endif

pre-everything::
.ifndef(WITHOUT_IPV6)
	@${ECHO_MSG} '===> Define WITHOUT_IPV6 to disable IPv6 support'
.endif
.ifndef(WITHOUT_OPTIMIZED_ASM)
	@${ECHO_MSG} '===> Define WITHOUT_OPTIMIZED_ASM to disable assembler optimizations'
.endif
.ifndef(WITH_PTHREADS)
	@${ECHO_MSG} '===> Define WITH_PTHREADS to enable pthreads support'
.endif
	@${ECHO_MSG}
.ifndef(WITH_OPTIMIZED_CFLAGS)
	@${ECHO_MSG} '===> Define WITH_OPTIMIZED_CFLAGS to enable compilation optimizations'
	@${ECHO_MSG} '===> which is known to break some platforms (e.g., alpha)'
.endif

.include <bsd.port.pre.mk>

.if ${ARCH} != "i386"
WITHOUT_OPTIMIZED_ASM=	yes
.endif

.if !defined(WITHOUT_IPV6)
CONFIGURE_ARGS+=	--enable-ipv6
.endif

.ifdef(WITHOUT_OPTIMIZED_ASM)
CONFIGURE_ARGS+=	--disable-asm
.endif

post-patch:
.if defined(NOPORTDOCS)
	@${REINPLACE_CMD} -E -e 's|^(install-data-hook:).*|\1|' \
		${WRKSRC}/doc/Makefile.in ${WRKSRC}/lib/Makefile.in
.endif
	@${REINPLACE_CMD} -e 's|(libdir)/pkgconfig|(prefix)/libdata/pkgconfig|g' \
		${WRKSRC}/lib/Makefile.in

.include <bsd.port.post.mk>
