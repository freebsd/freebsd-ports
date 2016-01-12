# $FreeBSD$

PORTNAME=	cvs
PORTVERSION=	1.20120905
PORTREVISION?=	4
CATEGORIES=	devel
MASTER_SITES=	LOCAL/eadler

MAINTAINER?=	ports@FreeBSD.org
COMMENT?=	Version control system

LICENSE=	GPLv2+

CONFLICTS_INSTALL?=	cvs+ipv6-[12]* cvs-devel-[12]*

OPTIONS_DEFINE=	IPV6 KERBEROS EXAMPLES
OPTIONS_DEFAULT=KERBEROS
.if !make(makesum)
OPTIONS_EXCLUDE?=IPV6
.endif

IPV6_CATEGORIES=	ipv6
IPV6_PATCH_SITES=	ftp://ftp.kame.net/pub/kame/misc/
IPV6_PATCHFILES=	${DISTNAME}-v6-20140105.diff.gz:-p1
KERBEROS_MAKE_ARGS=	KERBEROS_SUPPORT=yes

USES=		makeinfo shebangfix tar:xz uidfix
SHEBANG_FILES=	contrib/clmerge contrib/cln_hist \
		contrib/commit_prep contrib/cvs_acls \
		contrib/easy-import contrib/log \
		contrib/log_accum contrib/mfpipe \
		contrib/rcslock
PATCH_WRKSRC=	${WRKDIR}/call/cvs
WRKSRC=		${WRKDIR}/call/cvs-build
INFO=		cvs cvsclient

# bsd.stage.makes sets the wrong value for DESTDIR
DESTDIRNAME=	NADA
MAKE_ARGS=	DESTDIR=${STAGEDIR}${PREFIX}

pre-install:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}/contrib

.include <bsd.port.mk>
