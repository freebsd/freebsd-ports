PORTNAME=	cvs
PORTVERSION=	1.20120905
PORTREVISION?=	9
CATEGORIES=	devel
MASTER_SITES=	LOCAL/eadler

MAINTAINER?=	schaiba@gmail.com
COMMENT?=	Version control system

LICENSE=	GPLv2+

USES=		cpe shebangfix tar:xz uidfix

CONFLICTS_INSTALL?=	cvs-devel cvs+ipv6

OPTIONS_DEFINE=	INFO IPV6 KERBEROS EXAMPLES
OPTIONS_DEFAULT=INFO KERBEROS
.if !make(makesum)
OPTIONS_EXCLUDE?=IPV6
.endif

INFO_INFO=		cvs cvsclient
INFO_USES=		makeinfo
IPV6_PATCH_SITES=	LOCAL/ume
IPV6_PATCHFILES=	${DISTNAME}-v6-20140105.diff.gz:-p1
KERBEROS_MAKE_ARGS=	KERBEROS_SUPPORT=yes

CPE_VENDOR=	gnu
SHEBANG_FILES=	contrib/clmerge contrib/cln_hist \
		contrib/commit_prep contrib/cvs_acls \
		contrib/easy-import contrib/log \
		contrib/log_accum contrib/mfpipe \
		contrib/rcslock
PATCH_WRKSRC=	${WRKDIR}/call/cvs
WRKSRC=		${WRKDIR}/call/cvs-build

# bsd.stage.makes sets the wrong value for DESTDIR
DESTDIRNAME=	NADA
MAKE_ARGS=	DESTDIR=${STAGEDIR}${PREFIX}
# XXX static PIE libraries not yet supported by the base system
MAKE_ARGS+=	WITHOUT_PIE=true
MAKE_ARGS+=	MANDIR=/share/man/man

.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} -e "s,/info/,/${INFO_PATH}/,g" ${WRKSRC}/Makefile.inc
.if !${PORT_OPTIONS:MINFO}
	@${REINPLACE_CMD} -e "s,doc,,g" ${WRKSRC}/Makefile
.endif
pre-install:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}/contrib

.include <bsd.port.mk>
