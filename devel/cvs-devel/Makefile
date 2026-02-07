PORTNAME=	cvs
DISTVERSION=	1.12.13
PORTREVISION=	15
CATEGORIES=	devel
MASTER_SITES=	GNU/non-gnu/${PORTNAME}/source/feature/${DISTVERSION}
PKGNAMESUFFIX=	-devel

MAINTAINER=	bdheeman@gmail.com
COMMENT=	IPv6 enabled cvs. You can use IPv6 connection when using pserver
WWW=		https://www.nongnu.org/cvs/

LICENSE=	GPLv1
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		cpe gettext-runtime makeinfo perl5 tar:bzip2
CPE_VENDOR=	gnu
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-ipv6 \
		--with-editor="vi" \
		--with-external-zlib \
		--with-tmpdir="/tmp" \
		--without-gssapi

CONFLICTS=	cvs cvs+ipv6

INFO=		cvs cvsclient

CVS_SITE?=	:pserver:anoncvs@anoncvs.jp.FreeBSD.org:/home/ncvs
CVS_VER?=	v${DISTVERSION:S//_/g}

OPTIONS_DEFINE=	PAM
PAM_DESC=	PAM support

.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MPAM}
CONFIGURE_ARGS+=	--enable-pam
.endif

post-patch:
	@${REINPLACE_CMD} 's/${DISTVERSION:S/./\./g}/&-devel/g' \
		${WRKSRC}/configure
	@${CP} ${FILESDIR}/missing ${WRKSRC}

generate-patch:
	cvs -R -d ${CVS_SITE} rdiff -u -r ${CVS_VER} -r HEAD \
	  src/contrib/cvs \
	| ${SED} \
	  -e 's,^\+\+\+ src/contrib/cvs/,+++ ,' \
	  -e 's,^Index: src/contrib/cvs/,Index: ,' \
	  -e 's,\$$FreeBSD: ,FreeBSD: ,' \
	  > ${FILESDIR}/patch-freebsdlocal
	cvs -R -d ${CVS_SITE} rdiff -u -D 1999-12-01 -r HEAD \
	  gnu/usr.bin/cvs/cvs/prepend_args.c \
	  gnu/usr.bin/cvs/cvs/prepend_args.h \
	| ${SED} \
	  -e 's,^\+\+\+ src/gnu/usr.bin/cvs/cvs/,+++ src/,' \
	  -e 's,^Index: src/gnu/usr.bin/cvs/cvs/,Index: src/,' \
	  -e 's,\$$FreeBSD: ,FreeBSD: ,' \
	  >> ${FILESDIR}/patch-freebsdlocal

.include <bsd.port.post.mk>
